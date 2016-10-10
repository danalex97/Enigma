#ifndef Plugboard_h
#define Plugboard_h

#include "Component.hpp"

class Plugboard : public Component {
public:
	char map(char c) const;
};

#endif 
