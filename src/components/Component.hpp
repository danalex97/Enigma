#ifndef Component_h
#define Component_h

#include <memory>

class Component : public std::enable_shared_from_this<Component> {
public:
	Component() = default;
	virtual ~Component() = default;

    std::shared_ptr<Component> get_ptr() {
    	return shared_from_this();
    }

	virtual char map(char c) const = 0;
	virtual char inv_map(char c) const;
};

#endif
