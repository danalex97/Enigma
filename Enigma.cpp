#include "Enigma.hpp"
using namespace std;

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

string Enigma::encode(const string& input) {
} 

string Enigma::decode(const string& output) {

} 
