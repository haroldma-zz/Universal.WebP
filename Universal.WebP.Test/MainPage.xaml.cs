using Windows.UI.Xaml.Controls;

namespace Universal.WebP.Test
{
    /// <summary>
    ///     An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            InitializeComponent();
        }

        // Setting the image manually, instead of using the WebPSupport class

        /*  protected override async void OnNavigatedTo(NavigationEventArgs e)
          {
              var bytes = await new HttpClient().GetByteArrayAsync("http://www.gstatic.com/webp/gallery/5.webp");

              var webp = new WebPDecoder();
              var size = await webp.GetSizeAsync(bytes);
              var pixelData = (await webp.DecodeBgraAsync(bytes)).ToArray();

              var bitmap = new WriteableBitmap((int) size.Width, (int) size.Height);
              var stream = bitmap.PixelBuffer.AsStream();
              await stream.WriteAsync(pixelData, 0, pixelData.Length);

              WebPImage.Source = bitmap;
          }*/
    }
}