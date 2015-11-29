using System;
using System.Diagnostics;
using System.IO;
using System.Net.Http;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Storage.Streams;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Media.Imaging;

namespace WebP.Universal.Test
{
    public static class WebPSupport
    {
        public static readonly DependencyProperty SourceProperty =
            DependencyProperty.RegisterAttached("Source", typeof (Uri), typeof (WebPSupport),
                new PropertyMetadata(null, SourceCallback));

        public static void SetSource(DependencyObject element, Uri value)
        {
            element.SetValue(SourceProperty, value);
        }

        public static Uri GetSource(DependencyObject element)
        {
            return (Uri) element.GetValue(SourceProperty);
        }

        private static async void SourceCallback(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            try
            {
                var image = d as Image;
                var imageBrush = d as ImageBrush;

                if (imageBrush == null && image == null) return;

                if (image != null) image.Source = null;
                else imageBrush.ImageSource = null;

                var url = (Uri) e.NewValue;

                if (url == null)
                {
                    return;
                }

                if (!url.OriginalString.Contains(".webp"))
                {
                    if (image != null) image.Source = new BitmapImage(url);
                    else imageBrush.ImageSource = new BitmapImage(url);
                    return;
                }
                if (url.OriginalString.StartsWith("ms-resource"))
                    url = new Uri(url.OriginalString.Replace("ms-resource:///Files/", "ms-appx:///"));

                var streamReference = RandomAccessStreamReference.CreateFromUri(url);
                ImageSource source;
                byte[] arr;
                
                using (var stream = (await streamReference.OpenReadAsync()).AsStreamForRead())
                {
                    arr = new byte[stream.Length];
                    await stream.ReadAsync(arr, 0, arr.Length);
                }

                var webp = new WebPDecoder();

                try
                {
                    var size = await webp.GetSizeAsync(arr);
                    var pixelData = await webp.DecodeBgraAsync(arr);
                    var wb = new WriteableBitmap((int) size.Width, (int) size.Height);
                    var pixelArr = pixelData.ToArray();
                    
                    using (var pixelDataStream = wb.PixelBuffer.AsStream())
                    {
                        await pixelDataStream.WriteAsync(pixelArr, 0, pixelArr.Length);
                        source = wb;
                    }
                }
                catch
                {
                    using (var rnd = new MemoryStream(arr).AsRandomAccessStream())
                    {
                        var bitmap = new BitmapImage();
                        await bitmap.SetSourceAsync(rnd);

                        source = bitmap;
                    }
                }

                if (image != null) image.Source = source;
                else imageBrush.ImageSource = source;
            }
            catch (Exception ex)
            {
                Debug.WriteLine("Something happened opening webp image. Stack trace: " + ex.Message);
            }
        }
    }
}