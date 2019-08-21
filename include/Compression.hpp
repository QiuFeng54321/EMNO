//
// Created by Qiufeng54321 on 2019-08-20.
// This file is licensed by GPL 3.0
//

#ifndef EMNO_COMPRESSION_HPP
#define EMNO_COMPRESSION_HPP

#define ZLIB_CHUNK_SIZE 16384

#include <zlib.h>
#include "Global.hpp"

namespace EMNO::Compression {
	class ZLibInputStream {
	private:
		void _init();

		void _finish();

	protected:
		z_stream stream;
		std::ifstream input;
	public:
		ZLibInputStream(std::string in);

		/**
		 * decompress input bytes.
		 * code from https://github.com/majestic53/libanvil/blob/master/src/compression.cpp
		 * @param in input bytes to be decompressed
		 * @return decompressed data
		 */
		std::vector<byte> readBytes(std::vector<byte> in) noexcept(false);

		std::vector<byte> readBytes(int numbytes);

		std::vector<byte> readAll();

		void open(std::string in), close();
	};
}

#endif //EMNO_COMPRESSION_HPP
