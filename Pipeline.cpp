#include "Pipeline.hpp"
using namespace std;

#include <iostream>

void Pipeline::add(shared_ptr<Component> component) {
	pipeline.push_back(component);
}

char Pipeline::map(char ch) const {
	for (int i = 0; i < pipeline.size(); ++i) {
		ch = pipeline[i]->map(ch);
	}
	return ch;
}

char Pipeline::inv_map(char ch) const {
	for (int i = pipeline.size() - 1; i >= 0; --i) {
		ch = pipeline[i]->inv_map(ch);
	}
	return ch;
}
