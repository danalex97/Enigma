#ifndef Enigma_h
#define Enigma_h

#include "Machine.hpp"

#include "Pipeline.hpp"
#include "Plugboard.hpp"
#include "Rotor.hpp"
#include "Reflector.hpp"

#include <string>
#include <vector>
#include <memory>

class Enigma : public Machine {
public:
	Enigma(const std::vector<std::string>& rotor_files, const std::string * const  p_plugboard_files);
	virtual ~Enigma() = default;

	std::string encode(const std::string& input);
	std::string decode(const std::string& input);
private:
	void build_pipeline();
	std::string feed(const std::string& input, bool forward);

	std::vector<std::shared_ptr<Rotor> > rotors;
	
	std::shared_ptr<Plugboard> plugboard;
	std::shared_ptr<Reflector> reflector;
	
	Pipeline pipeline;
};

#endif
