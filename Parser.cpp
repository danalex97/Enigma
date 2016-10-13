#include "Parser.hpp"
using namespace std;

const std::string Parser::SPECIAL_CHARS = "\t\r\n ";

Parser::Parser(int argc, char **argv) {
	if (argc < 2) {
		throw invalid_argument("No input files given.");
	}
	for (int i = 1; i < argc; ++i) {
		args.push_back(argv[i]);
		if (!file_exists(args.back())) {
			throw invalid_argument("File does not exist.");
		}
	}
}

string Parser::prepare_input() {
	char chr;
	string input;
	while (cin >> noskipws >> chr) {
		if (chr >= 'A' && chr <= 'Z') {
			input += chr;
			continue;
		}
		if (SPECIAL_CHARS.find(chr) != string::npos) {
			continue;
		}
		throw invalid_argument("Unexpected char occured in input.");
	}
	return input;
}

bool Parser::file_exists(const std::string& file_name) {
    ifstream file(file_name);
    return file.good();
}

vector<string> Parser::get_rotor_files() { 
	vector<string> out;
	for (size_t i = 0; i < args.size() - 1; ++i) { 
		out.push_back(args[i]);
	}
	return out;
}
	
string Parser::get_plugboard_file() {
	return args.back();
}
