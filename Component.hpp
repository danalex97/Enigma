#ifndef Component_h
#define Component_h

class Component {
public:
	virtual char map(char c) const = 0;
	virtual char inv_map(char c) const;
};

#endif 
