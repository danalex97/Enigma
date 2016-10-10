#ifndef Machine_h
#define Machine_h

#include <string>

class Machine {
	virtual std::string encode(std::string input) = 0;
	virtual std::string decode(std::string input) = 0;
};

#endif
