#ifndef Plugboard_h
#define Plugboard_h

#include "Component.hpp"
#include <string>
#include <fstream>

class Plugboard : public Component {
public:
	Plugboard();
	Plugboard(std::string file_name);

	Plugboard& operator = (Plugboard&& obj) = default;

	char map(char c) const;
};

#endif 
