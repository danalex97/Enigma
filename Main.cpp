#include <iostream>
#include <vector>
#include <string>

#include "Parser.hpp"
#include "Machine.hpp"
#include "Enigma.hpp"
using namespace std;

static string build_input() {
	char chr;
	string input;
	while (cin >> noskipws >> chr) {
		input += chr;
		if (chr >= 'A' && chr <= 'Z') {
			continue;
		}
		if (chr == '\t' || chr == '\n' || chr == ' ' || chr == '\r') {
			continue;
		}
		throw invalid_argument("");
	}
	return input;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		cerr << "Please provide input files.\n";
	} else {
		Parser parser(argc, argv);
		Machine *machine = new Enigma(
			parser.get_rotor_files(),
			parser.get_plugboard_file()
		);

		try {
			string input = build_input();
			string output = machine->encode(input); 

			cout << output;
		} catch(...) {
			cout << "Invalid argument provided." << endl;
		}

		delete machine;
	}
}
