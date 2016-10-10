#ifndef Parser_h
#define Parser_h

#include <vector>
#include <string>

class Parser {
public:
	Parser(int argc, char **argv);

	std::vector<std::string> get_rotor_files();
	std::string *get_plugboard_file();
private:
	std::vector<std::string> args;
};

#endif