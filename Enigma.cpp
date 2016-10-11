#include "Enigma.hpp"
using namespace std;

#include <iostream>
#include <memory>

Enigma::Enigma(const vector<string>& rotor_files, const string * const p_plugboard_file) {
	for (auto &rotor : rotor_files) {
		rotors.push_back(Rotor(rotor));
	}
	if (p_plugboard_file != nullptr) { 
		plugboard = Plugboard(*p_plugboard_file);
	}
	build_pipeline();
}

void Enigma::build_pipeline() {
	pipeline.add(shared_ptr<Component>(&plugboard));
	for (int i = 0; i < rotors.size(); ++i) {
		pipeline.add(shared_ptr<Component>(
			&rotors[i]
		));
	}
	pipeline.add(shared_ptr<Component>(&reflector));
	for (int i = 0; i < rotors.size(); ++i) {
		pipeline.add(shared_ptr<Component>(
			new ReverseRotor(&rotors[i])
		));
	}
	pipeline.add(shared_ptr<Component>(&plugboard));
}

string Enigma::feed(const string& input, bool forward) {
	string output;		
	for (auto &ch : input) {
		if (ch >= 'A' && ch <= 'Z') {
			output += forward ? pipeline.map(ch) : pipeline.inv_map(ch);
		} else {
			output += ch;
		}
		for (int i = 0; i < rotors.size(); ++i) {
			bool propagate = forward ? rotors[i].forward() : rotors[i].backward();
			if (!propagate) {
				break;
			}
		}
	}
	return output;
}

string Enigma::encode(const string& input) {
	return feed(input, true);
} 

string Enigma::decode(const string& output) {
	return feed(output, false);
} 
