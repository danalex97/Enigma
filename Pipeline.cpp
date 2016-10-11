#include "Pipeline.hpp"
using namespace std;

void Pipeline::add(shared_ptr<Component> component) {
	pipeline.push_back(component);
}

char Pipeline::map(char ch) const {
	for (int i = 0; i < pipeline.size(); ++i) {
		ch = pipeline[i]->map(ch);
	}
	return ch;
}
