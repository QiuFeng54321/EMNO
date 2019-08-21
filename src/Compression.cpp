//
// Created by Qiufeng54321 on 2019-08-20.
// This file is licensed by GPL 3.0
//

#include "Compression.hpp"

#include <utility>

namespace EMNO::Compression {
	ZLibInputStream::ZLibInputStream(std::string in) {
		open(std::move(in));
	}

	void ZLibInputStream::_init() {
		stream = z_stream();
		stream.zalloc = Z_NULL;
		stream.zfree = Z_NULL;
		stream.opaque = Z_NULL;
		int ret = deflateInit(&stream, Z_DEFAULT_COMPRESSION);
		if (ret != Z_OK) {
			throw std::runtime_error("Zlib: deflateInit error. Panic.");
		}
	}

	void ZLibInputStream::_finish() {
		inflateEnd(&stream);
	}

	std::vector<byte> ZLibInputStream::readBytes(std::vector<byte> in) {
		std::vector<byte> out;
		int res;
		uLong previous_out = 0;
		auto *next_out = (Bytef *) malloc(sizeof(Bytef) * ZLIB_CHUNK_SIZE);
		stream.next_in = in.data();
		stream.avail_in = in.size();
		do {
			stream.next_out = next_out;
			stream.avail_out = ZLIB_CHUNK_SIZE;
			res = inflate(&stream, Z_DEFAULT_COMPRESSION);
			out.insert(out.end(), next_out, next_out + (stream.total_out - previous_out));
			previous_out = stream.total_out;
		} while (res == Z_OK);
		return out;
	}

	std::vector<byte> ZLibInputStream::readBytes(int numbytes) {
		byte *recieved = (byte *) malloc(sizeof(byte) * numbytes);
		input.read((char *) recieved, numbytes);
		return readBytes(std::vector<byte>(recieved, recieved + numbytes));
	}

	std::vector<byte> ZLibInputStream::readAll() {
		auto here = input.tellg();
		input.seekg(std::ios::end);
		auto end = input.tellg();
		input.seekg(here);
		auto length = end - here;
		return readBytes(length);
	}

	void ZLibInputStream::open(std::string in) {
		input.open(in, std::ios::in | std::ios::binary);
		_init();
	}

	void ZLibInputStream::close() {
		input.close();
		_finish();
	}
}