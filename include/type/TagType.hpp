//
// Created by Qiufeng54321 on 2019-08-20.
// This file is licensed by GPL 3.0
//

#ifndef EMNO_TAGTYPE_HPP
#define EMNO_TAGTYPE_HPP

#include <Global.hpp>

namespace EMNO::Tags {
	enum class TagType : byte {
		END,
		BYTE,
		SHORT,
		INT,
		LONG,
		FLOAT,
		DOUBLE,
		BYTE_ARRAY,
		STRING,
		LIST,
		COMPOUND,
		INT_ARRAY,
		LONG_ARRAY
	};
}

#endif //EMNO_TAGTYPE_HPP
