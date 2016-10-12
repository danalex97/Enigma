#ifndef Reflector_h
#define Reflector_h

#include "Component.hpp"

class Reflector : public Component {
public:
	Reflector() = default;
	virtual ~Reflector() = default;

	char map(char c) const;
};

#endif
