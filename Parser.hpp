#ifndef Parser_h
#define Parser_h

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

/*
 * Parser used for preparing the givem objects for processing.
 * It is also used for parsing and string preparation related 
 * tasks. (static functions) Exception handling for invalid 
 * input and missing files is handled inside.
 */

class Parser {
public:
	Parser(const int argc, char ** const argv);
	virtual ~Parser() = default;

	std::vector<std::string> get_rotor_files() const;
	std::string get_plugboard_file() const;

	static std::string prepare_input();
	static std::string eliminate_special_chars(const std::string& input);
private:
	static const std::string SPECIAL_CHARS;
	std::vector<std::string> args;

	bool file_exists(const std::string& file_name) const;
};

#endif