#ifndef Enigma_h
#define Enigma_h

#include "Machine.hpp"

#include "Pipeline.hpp"
#include "Plugboard.hpp"
#include "Rotor.hpp"
#include "Reflector.hpp"

#include <string>
#include <vector>

class Enigma : public Machine {
public:
	Enigma(const std::vector<std::string>& rotor_files, const std::string * const  p_plugboard_files);

	std::string encode(const std::string& input);
	std::string decode(const std::string& input);
private:
	void build_pipeline();

	std::vector<Rotor> rotors;
	
	Plugboard plugboard;
	Reflector reflector;
	Pipeline pipeline;
};

#endif
