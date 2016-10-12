#ifndef Pipeline_h
#define Pipeline_h

#include "Component.hpp"

#include <vector>
#include <memory>

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
