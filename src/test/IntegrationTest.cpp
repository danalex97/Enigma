#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <algorithm>
using namespace std;

#include "Parser.hpp"
#include "machine/Machine.hpp"
#include "machine/Enigma.hpp"

const int SIGMA = 26;
const string FOLDER = "components";

const int TESTS = 100;

const int LENGTH = 1000;
const int ROTORS = 10;

static void gen_input_file(const string& file_path) {
	vector<int> vec;
	for (int i = 0; i < SIGMA; ++i) {
		vec.push_back(i);
	}
	random_shuffle(vec.begin(), vec.end());

	ofstream file(file_path);
	for (auto &v : vec) {
		file << v << ' ';
	}
	file.close();
}

static string gen_input(int length) {
	string out;
	for (int i = 0; i < length; ++i) {
		out += int(rand() % SIGMA) + 'A';
	}
	return out;
}

int main() {
	srand(time(0));
	for (int i = 1; i <= TESTS; ++i) {
		vector<string> rotor_files;
		for (int j = 0; j < ROTORS; ++j) {
			stringstream ss;
			ss << FOLDER << '/';
			ss << "rotor";
			ss << j;
			ss << ".rot";

			gen_input_file(ss.str());
			rotor_files.push_back(ss.str());
		}

		string plugboard_file = FOLDER + "/plugboard.pb";
		gen_input_file(plugboard_file);

		try {
			Machine *machine = new Enigma(
				rotor_files,
				plugboard_file
			);

			string input = gen_input(LENGTH);
			string output = machine->decode(machine->encode(input));

			if (output == input) {
				cout << "Test " << i << " passed.\n";
			} else {
				cout << "Test " << i << " failed.\n";

				cerr << "Expected: " << input << '\n';
				cerr << "Actual:   " << output << '\n';
				return 0;
			}

			delete machine;
		} catch(...) {
			cerr << "Program encuntered an error on test " << i << '\n';
			return 0;
		}
	}
	cerr << "All tests passed." << '\n';
	return 0;
}
