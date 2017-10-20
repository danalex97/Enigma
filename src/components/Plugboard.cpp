#include "components/Plugboard.hpp"
using namespace std;

#include <iostream>

Plugboard::Plugboard(const string& file_name) {
	ifstream file(file_name);

	for (int i = 0; i < SIGMA; ++i) {
		mapping[i] = 'A' + char(i);
	}

	int x = 0, y = 0;
	while (file >> x >> y) {
		mapping[x] = 'A' + char(y);
		mapping[y] = 'A' + char(x);
	}

	file.close();
}

char Plugboard::map(char ch) const {
	if (ch >= 'A' && ch <= 'Z') {
		return mapping[int(ch - 'A')];
	}
	return ch;
}
