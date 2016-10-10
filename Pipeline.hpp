#ifndef Pipeline_h
#define Pipeline_h

#include "Component.hpp"

class Pipeline : public Component {
public:
	void add(Component *component);
	char map(char ch) const;
};

#endif
