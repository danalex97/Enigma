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

/*
 * The constructor prepares the machine by provinding the lookup files. 
 * After the single components are constructed, the pipeline is built.
 * The reponsability for static object is passed to the pipeline. In 
 * order to the objects' shared pointer table to be constructed only once
 * the component class enables passing by extending enable_shared_from_this.

 * The encoding and decoding methods have a common pipeline, that is the one
 * in feed function, the single diffence being the direction in which the rotor
 * moves.
 */

class Enigma : public Machine {
public:
	Enigma(const std::vector<std::string>& rotor_files, const std::string& plugboard_file);
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
