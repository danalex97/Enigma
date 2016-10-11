#include "Rotor.hpp"
using namespace std;

Rotor::Rotor(string file_name) {
}

char Rotor::map(char ch) const {
	return ch;
}

char Rotor::inv_map(char ch) const {
	return ch;
}

bool Rotor::forward() {
}

bool Rotor::backward() {
}

char ReverseRotor::map(char ch) const {
	return ch;
}

ReverseRotor::ReverseRotor(Rotor *rotor) : rotor(rotor) {
}

char ReverseRotor::inv_map(char ch) const {
	return ch;
}
