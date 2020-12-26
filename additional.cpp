#include <fstream>
#include "additional.hpp"

#ifdef WIN32
	#include <windows.h>
#else
	#include <termios.h>
	#include <unistd.h>
#endif

std::string file_content(const std::string& file_path) {
	std::ifstream file(file_path);

	std::string result;
	result.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
	file.close();

	return result;
}

void set_stdin_echo(bool enable) {
#ifdef WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
    DWORD mode;

    GetConsoleMode(hStdin, &mode);
	mode = (enable ? (mode | ENABLE_ECHO_INPUT) : (mode & ~ENABLE_ECHO_INPUT));

    SetConsoleMode(hStdin, mode);

#else
    struct termios tty;

    tcgetattr(STDIN_FILENO, &tty);
	tty.c_lflag = (enable ? (tty.c_lflag | ECHO) : (tty.c_lflag & ~ECHO));

    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
}
