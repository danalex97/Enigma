#include <iostream>
#include <vector>
#include <string>

#include "Parser.hpp"
#include "Machine.hpp"
#include "Enigma.hpp"
using namespace std;

int main(int argc, char **argv) {
	if (argc < 2) {
		cerr << "Please provide input files.\n";
	} else {
		Parser parser(argc, argv);
		Machine *machine = new Enigma(
			parser.get_rotor_files(),
			parser.get_plugboard_file()
		);

		cout

		delete machine;
	}
}
