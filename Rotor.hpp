#ifndef Rotor_h
#define Rotor_h

#include "Component.hpp"

class Rotor : public Component {
public:
	char map(char c) const;
	char inv_map(char c) const; 
	
	void forward();
	void backward();
};

class ReverseRotor : public Component {
public:
	char map(char c) const;
private:
	Rotor *rotor;
};

#endif
