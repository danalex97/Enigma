#include <iostream>
#include <stdexcept>

#include "Parser.hpp"
#include "machine/Machine.hpp"
#include "machine/Enigma.hpp"
using namespace std;

int main(int argc, char **argv) {
	Parser *parser;
	try {
		parser = new Parser(argc, argv);
	} catch (invalid_argument e) {
		cerr << e.what() << endl;
		return 1;
	}

	Machine *machine = new Enigma(
		parser->get_rotor_files(),
		parser->get_plugboard_file()
	);

	string input;

	try {
		input = Parser::prepare_input();
	} catch (invalid_argument e) {
		cerr << e.what() << endl;
		return 1;
	}
	delete parser;

	string output = machine->encode(input);
	delete machine;

	cout << Parser::eliminate_special_chars(output);
	return 0;
}
