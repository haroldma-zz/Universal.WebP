#pragma once

namespace Universal
{
	namespace WebP
	{
		public ref class WebPDecoder sealed
		{
			public:
				WebPDecoder();

				/// <summary>
				/// Gets the decoder version.
				/// </summary>
				/// <returns></returns>
				int GetDecoderVersion();

				/// <summary>
				///  Gets the image width and height. Will also validate the WebP image header.
				/// </summary>
				/// <param name="input">The byte data of the webp image.</param>
				/// <returns></returns>
				Windows::Foundation::IAsyncOperation<Windows::Foundation::Size>^ GetSizeAsync(const Platform::Array<byte>^ input);

				/// <summary>
				///  Decodes the input to BGRA image samples in [b0, g0, r0, a0, b1, g1, r1, a1, ...] order.
				/// </summary>
				/// <param name="input">The input.</param>
				/// <returns></returns>
				Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer^>^ DecodeBgraAsync(const Platform::Array<byte>^ input);

				/// <summary>
				///  Decodes the input to RGBA image samples in [r0, g0, b0, a0, r1, g1, b1, a1, ...] order.
				/// </summary>
				/// <param name="input">The input.</param>
				/// <returns></returns>
				Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer^>^ DecodeRgbaAsync(const Platform::Array<byte>^ input);

				/// <summary>
				///  Decodes the input to ARGB image samples in [a0, r0, g0, b0, a1, r1, g1, b1, ...] order.
				/// </summary>
				/// <param name="input">The input.</param>
				/// <returns></returns>
				Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer^>^ DecodeArgbAsync(const Platform::Array<byte>^ input);

				/// <summary>
				///  Decodes the input to BGR image samples in [b0, g0, r0, b1, g1, r1, ...] order.
				/// </summary>
				/// <param name="input">The input.</param>
				/// <returns></returns>
				Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer^>^ DecodeBgrAsync(const Platform::Array<byte>^ input);

				/// <summary>
				/// Decodes the input to RGB image samples in [r0, g0, b0, r1, g1, b1, ...] order.
				/// </summary>
				/// <param name="input">The input.</param>
				/// <returns></returns>
				Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer^>^ DecodeRgbAsync(const Platform::Array<byte>^ input);
		};
	}
}
