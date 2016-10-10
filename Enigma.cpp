#include "Enigma.hpp"
using namespace std;
		
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
	// ...
}

string Enigma::encode(const string& input) {

} 

string Enigma::decode(const string& output) {

} 
