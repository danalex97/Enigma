#ifndef Parser_h
#define Parser_h

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

class Parser {
public:
	Parser(int argc, char **argv);
	virtual ~Parser() = default;

	std::vector<std::string> get_rotor_files();
	std::string get_plugboard_file();

	static std::string prepare_input();
private:
	static const std::string SPECIAL_CHARS;

	std::vector<std::string> args;
	bool file_exists(const std::string& file_name);
};

#endif