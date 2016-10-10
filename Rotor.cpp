#include "Rotor.hpp"

char Rotor::map(char ch) const {
	return ch;
}

char Rotor::inv_map(char ch) const {
	return ch;
}

void Rotor::forward() {
}

void Rotor::backward() {
}

char ReverseRotor::map(char ch) const {
	return ch;
}
