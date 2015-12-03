# WebP for the Universal Windows Platform
WebP image library for Windows 10 (Universal apps)

## How-To

### Display image programatically

    // Download webp image
    var bytes = await new HttpClient().GetByteArrayAsync("http://www.gstatic.com/webp/gallery/5.webp");
    
    // Create an instance of the decoder
    var webp = new WebPDecoder();
    
    // Decode to BGRA (Bitmaps use this format)
    var pixelData = (await webp.DecodeBgraAsync(bytes)).ToArray();
    
    // Get the size
    var size = await webp.GetSizeAsync(bytes);
    
    // With the size of the webp, create a WriteableBitmap
    var bitmap = new WriteableBitmap((int) size.Width, (int) size.Height);
    
    // Write the pixel data to the buffer
    var stream = bitmap.PixelBuffer.AsStream();
    await stream.WriteAsync(pixelData, 0, pixelData.Length);
    
    // Set the bitmap
    ImageControl.Source = bitmap;

### Display image utilizing the attached property in Xaml

    // TODO

## Visual Studio Extension

You can install the `WebP for the UWP`'s SDK by downloading [it here](https://visualstudiogallery.msdn.microsoft.com/2e3df485-bc4a-4d67-baaa-0d7bd24bb5a1).
