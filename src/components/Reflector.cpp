#include "components/Reflector.hpp"

char Reflector::map(char ch) const {
	if (ch >= 'A' && ch <= 'Z') {
		return char((int(ch) - 'A' + 13) % 26) + 'A';
	}
	return ch;
}
