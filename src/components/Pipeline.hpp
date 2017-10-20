#ifndef Pipeline_h
#define Pipeline_h

#include "components/Component.hpp"

#include <vector>
#include <memory>

/* The pipeline is used to compose components in order to
 * have a single component used for the actual mapping function.
 * The implementation queries the components as some of them
 * can be updated(e.g. rotors). The class uses shared pointers
 * to take rasponsability for the objects not updated or implicitly
 * updated.(e.g. reflectors and reverse rotors)
 */

class Pipeline : public Component {
public:
	Pipeline() = default;
	virtual ~Pipeline() = default;

	void add(std::shared_ptr<Component> component);

	char map(char ch) const;
	char inv_map(char ch) const;
private:
	std::vector<std::shared_ptr<Component> > pipeline;
};

#endif
