#include "Rotor.hpp"
using namespace std;

#include <iostream>

Rotor::Rotor(string file_name) {
	ifstream file(file_name);

	for (int i = 0; i < SIGMA; ++i) {
		int pos = 0;
		file >> pos;
	
		rev_map[dir_map[pos]] = char(i) + 'A';
		dir_map[i] = char(pos) + 'A';
	}
	offset = 0;

	file.close();
}

char Rotor::map(char ch) const {
	return dir_map[char_pos(ch)];
}

char Rotor::inv_map(char ch) const {
	return rev_map[char_pos(ch)];
}

bool Rotor::forward() {
	offset = (offset + 1) % SIGMA;
	return offset == 0;
}

bool Rotor::backward() {
	offset = (offset - 1 + SIGMA) % SIGMA;
	return offset == 0;
}

int Rotor::char_pos(char ch) const {
	return (int(ch - 'A') + offset) % SIGMA;
}

ReverseRotor::ReverseRotor(Rotor *rotor) : rotor(rotor) {
}

char ReverseRotor::map(char ch) const {
	return rotor->inv_map(ch);
}

char ReverseRotor::inv_map(char ch) const {
	return rotor->map(ch);
}
