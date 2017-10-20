#ifndef Machine_h
#define Machine_h

#include <string>

/*
 * Interface of an encoding/decoding machine.
 */

class Machine {
public:
	Machine() = default;
	virtual ~Machine() = default;

	virtual std::string encode(const std::string& input) = 0;
	virtual std::string decode(const std::string& input) = 0;
};

#endif
