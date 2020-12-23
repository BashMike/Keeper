#include <fstream>
#include "additional.hpp"

std::string file_content(const std::string& file_path) {
	std::ifstream file(file_path);

	std::string result;
	result.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());

	return result;
}
