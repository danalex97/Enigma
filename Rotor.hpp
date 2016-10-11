#ifndef Rotor_h
#define Rotor_h

#include "Component.hpp"

#include <string>
#include <fstream>

class Rotor : public Component {
public:
	Rotor(std::string file_name);

	char map(char c) const;
	char inv_map(char c) const; 
	
	void forward();
	void backward();
};

class ReverseRotor : public Component {
public:
	ReverseRotor(Rotor *rotor);
	char map(char c) const;
private:
	Rotor *rotor;
};

#endif
