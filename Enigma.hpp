#ifndef Enigma_h
#define Enigma_h

#include "Machine.hpp"
#include <string>

class Enigma : public Machine {
	std::string encode(const std::string& input);
	std::string decode(const std::string& input);
};

#endif
