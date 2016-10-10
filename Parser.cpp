#include "Parser.hpp"
using namespace std;

Parser::Parser(int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		args.push_back(argv[i]);
	}
}

vector<string> Parser::get_rotor_files() {
	vector<string> out;
	for (size_t i = 0; i < args.size() - 1; ++i) {
		out.push_back(args[i]);
	}
	return out;
}
	
string *Parser::get_plugboard_file() {
	if (args.empty()) {
		return nullptr;
	} else {
		return &args.back();
	}
}
