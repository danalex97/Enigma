#include "Enigma.hpp"
using namespace std;

#include <iostream>
#include <memory>
#include <algorithm>

Enigma::Enigma(const vector<string>& rotor_files, const string * const p_plugboard_file) {
	for (auto &rotor_file : rotor_files) {
		shared_ptr<Rotor> rotor(new Rotor(rotor_file));
		rotors.push_back(*rotor);
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
	for (int i = rotors.size() - 1; i >= 0; --i) {
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
			for (int i = 0; i < rotors.size(); ++i) {
				bool propagate = forward ? rotors[i].forward() : rotors[i].backward();
				if (!propagate) {
					break;
				}
			}
		} else {
			output += ch;
		}
		
	}
	return output;
}

string Enigma::encode(const string& input) {
	return feed(input, true);
} 

string Enigma::decode(const string& output) {
	string feed_text = output + "A";
	reverse(feed_text.begin(), feed_text.end());
	string input = feed(feed_text, false);
	reverse(input.begin(), input.end());
	input = input.substr(0, input.size()-1);
	return input;
} 
