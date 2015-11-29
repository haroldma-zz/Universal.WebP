#pragma once

namespace WebP
{
	namespace Universal 
	{
		public ref class WebPDecoder sealed
		{
			public:
				WebPDecoder();
				Windows::Foundation::IAsyncOperation<Windows::Foundation::Size>^ GetSizeAsync(const Platform::Array<byte>^ input);
				Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer^>^ DecodeBgraAsync(const Platform::Array<byte>^ input);
				Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer^>^ DecodeRgbaAsync(const Platform::Array<byte>^ input);
				Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer^>^ DecodeArgbAsync(const Platform::Array<byte>^ input);
				Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer^>^ DecodeBgrAsync(const Platform::Array<byte>^ input);
				Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer^>^ DecodeRgbAsync(const Platform::Array<byte>^ input);
		};
	}
}
