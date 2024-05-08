#include "Utils.h"

#include <fstream>
#include <iostream>
std::string read_file_into_string(const std::string& file_name)
{
	std::ifstream ifs;
	ifs.open(file_name, std::ios::in | std::ios::binary);
	ifs.unsetf(std::ios::skipws);

	// get its size:
	ifs.seekg(0, std::ios::end);
	const std::streampos input_size = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	auto buffer = std::string();
	buffer.reserve(input_size);
	std::copy(std::istream_iterator<char>(ifs), std::istream_iterator<char>(), std::back_inserter(buffer));
	ifs.close();
	
	return buffer;
}