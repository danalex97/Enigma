#ifndef Rotor_h
#define Rotor_h

#include "components/Component.hpp"

#include <string>
#include <fstream>
#include <vector>
#include <memory>

/*
 * The rotor component build direct and inverse mappings
 * keeping track of the position of a rotor using a offset.
 * The update of the mapping is made in O(1) as it directly
 * depends on the offset, that can be updated using the
 * forward and backward functions.
 */

class Rotor : public Component {
public:
	Rotor(const std::string& file_name);
	virtual ~Rotor() = default;

	char map(char c) const;
	char inv_map(char c) const;

	bool forward();
	bool backward();
private:
	static const int SIGMA = 26;

	int offset;

	std::vector<int> dir_map;
	std::vector<int> rev_map;

	int char_pos(char ch) const;
	char offset_char(int pos) const;
};

/*
 * Wrapper class over Rotor used in the pipeline as the
 * second pass through the rotors. Is constructed from
 * a pointer to a rotor, being implicitly updated.
 */

class ReverseRotor : public Component {
public:
	ReverseRotor(Rotor * const rotor);
	virtual ~ReverseRotor() = default;

	char map(char c) const;
	char inv_map(char c) const;
private:
	Rotor * const rotor;
};

#endif
