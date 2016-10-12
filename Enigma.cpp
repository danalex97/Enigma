#include "Enigma.hpp"
using namespace std;

#include <iostream>
#include <algorithm>

Enigma::Enigma(const vector<string>& rotor_files, const string * const p_plugboard_file) {
	for (auto &rotor_file : rotor_files) {
		rotors.push_back(make_shared<Rotor>(rotor_file));
	}
	if (p_plugboard_file != nullptr) { 
		plugboard = make_shared<Plugboard>(*p_plugboard_file);
	}
	reflector = make_shared<Reflector>();
	build_pipeline();	
}

void Enigma::build_pipeline() {
	pipeline.add(plugboard->get_ptr());
	for (int i = 0; i < rotors.size(); ++i) {
		pipeline.add(shared_ptr<Component>(
			rotors[i]
		));
	}
	pipeline.add(reflector->get_ptr());
	for (int i = rotors.size() - 1; i >= 0; --i) {
		pipeline.add(shared_ptr<Component>(
			new ReverseRotor(
				rotors[i].get()
			)
		));
	}
	pipeline.add(plugboard->get_ptr());
}

string Enigma::feed(const string& input, bool forward) {
	string output;		
	for (auto &ch : input) {
		if (ch >= 'A' && ch <= 'Z') {
			output += forward ? pipeline.map(ch) : pipeline.inv_map(ch);
			for (int i = 0; i < rotors.size(); ++i) {
				bool propagate = forward ? rotors[i]->forward() : rotors[i]->backward();
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
