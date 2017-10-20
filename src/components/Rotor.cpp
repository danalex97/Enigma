#include "components/Rotor.hpp"
using namespace std;

Rotor::Rotor(const string& file_name) : dir_map(SIGMA), rev_map(SIGMA) {
	ifstream file(file_name);

	for (int i = 0; i < SIGMA; ++i) {
		int pos = 0;
		file >> pos;

		rev_map[pos] = i;
		dir_map[i] = pos;
	}
	offset = 0;

	file.close();
}


char Rotor::map(char ch) const {
	return offset_char(dir_map[char_pos(ch)]);
}

char Rotor::inv_map(char ch) const {
	return offset_char(rev_map[char_pos(ch)]);
}

char Rotor::offset_char(int pos) const {
	return 'A' + char((pos - offset + SIGMA) % SIGMA);
}

bool Rotor::forward() {
	offset = (offset + 1) % SIGMA;
	return offset == 0;
}

bool Rotor::backward() {
	offset = (offset - 1 + SIGMA) % SIGMA;
	return offset == 25;
}

int Rotor::char_pos(char ch) const {
	return (int(ch - 'A') + offset) % SIGMA;
}

ReverseRotor::ReverseRotor(Rotor * const rotor) : rotor(rotor) {
}

char ReverseRotor::map(char ch) const {
	return rotor->inv_map(ch);
}

char ReverseRotor::inv_map(char ch) const {
	return rotor->map(ch);
}
