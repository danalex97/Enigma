#ifndef Plugboard_h
#define Plugboard_h

#include "Component.hpp"
#include <string>
#include <fstream>

class Plugboard : public Component {
public:
	Plugboard();
	Plugboard(const std::string& file_name);

	char map(char c) const;
private:
	static const int SIGMA = 26;

	char mapping[SIGMA];
};


#endif 
