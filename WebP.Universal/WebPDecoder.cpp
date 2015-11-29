#include "pch.h"
#include "WebPDecoder.h"

extern "C" {
	#include <webp/encode.h>
	#include <webp/decode.h>
}

using namespace WebP::Universal;
using namespace Platform;

using namespace concurrency;
using namespace Windows::Foundation;
using namespace Windows::Storage;
using namespace Windows::Storage::Streams;

WebPDecoder::WebPDecoder() {
}

IAsyncOperation<Size>^  WebPDecoder::GetSizeAsync(const Array<byte>^ input) {
	return create_async([=]() -> Size {
		int w, h;
		if (!WebPGetInfo(input->Data, input->Length, &w, &h)) {
			throw ref new FailureException("Input data is not in WebP format.");
		}
		return *ref new Size(w, h);
	});
}

IAsyncOperation<IBuffer^>^ WebPDecoder::DecodeBgraAsync(const Array<byte>^ input) {
	return create_async([=]() -> IBuffer^ {
		int w, h;
		auto data = WebPDecodeBGRA(input->Data, input->Length, &w, &h);
		auto data_size = w*h*sizeof(uint8_t) * 4;
		auto bytes = ref new Array<byte>(data, data_size);

		auto writer = ref new DataWriter();
		writer->WriteBytes(bytes);
		return writer->DetachBuffer();
	});
}

IAsyncOperation<IBuffer^>^ WebPDecoder::DecodeRgbaAsync(const Array<byte>^ input) {
	return create_async([=]() -> IBuffer^ {
		int w, h;
		auto data = WebPDecodeRGBA(input->Data, input->Length, &w, &h);
		auto data_size = w*h*sizeof(uint8_t) * 4;
		auto bytes = ref new Array<byte>(data, data_size);

		auto writer = ref new DataWriter();
		writer->WriteBytes(bytes);
		return writer->DetachBuffer();
	});
}

IAsyncOperation<IBuffer^>^ WebPDecoder::DecodeArgbAsync(const Array<byte>^ input) {
	return create_async([=]() -> IBuffer^ {
		int w, h;
		auto data = WebPDecodeARGB(input->Data, input->Length, &w, &h);
		auto data_size = w*h*sizeof(uint8_t) * 4;
		auto bytes = ref new Array<byte>(data, data_size);

		auto writer = ref new DataWriter();
		writer->WriteBytes(bytes);
		return writer->DetachBuffer();
	});
}

IAsyncOperation<IBuffer^>^ WebPDecoder::DecodeBgrAsync(const Array<byte>^ input) {
	return create_async([=]() -> IBuffer^ {
		int w, h;
		auto data = WebPDecodeBGR(input->Data, input->Length, &w, &h);
		auto data_size = w*h*sizeof(uint8_t) * 3;
		auto bytes = ref new Array<byte>(data, data_size);

		auto writer = ref new DataWriter();
		writer->WriteBytes(bytes);
		return writer->DetachBuffer();
	});
}

IAsyncOperation<IBuffer^>^ WebPDecoder::DecodeRgbAsync(const Array<byte>^ input) {
	return create_async([=]() -> IBuffer^ {
		int w, h;
		auto data = WebPDecodeRGB(input->Data, input->Length, &w, &h);
		auto data_size = w*h*sizeof(uint8_t) * 3;
		auto bytes = ref new Array<byte>(data, data_size);

		auto writer = ref new DataWriter();
		writer->WriteBytes(bytes);
		return writer->DetachBuffer();
	});
}