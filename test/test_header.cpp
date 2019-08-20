//
// Created by Qiufeng54321 on 2019-08-20.
// This file is licensed by GPL 3.0
//

#include <iostream>
#include "type/TagType.hpp"

int main() {
	std::cout << "Hello world!" << std::endl;
	auto type = static_cast<EMNO::Tags::TagType>((byte) 1);
}

