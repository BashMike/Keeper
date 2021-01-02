#pragma once
#include <string>

std::string file_content(const std::string& file_path);

void set_stdin_echo(bool enable);

bool is_integer(const std::string& str);
bool is_float(const std::string& str);
