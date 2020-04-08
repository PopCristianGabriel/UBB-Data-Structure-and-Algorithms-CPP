#pragma once
#include "Container.h"

class Container;

class IteratorContainer
{
	friend class Container;

private:
	//the iterator stores a reference to the container 
	 Container& con;
	//other specific attributes: current, etc

	typedef struct stackElem {
		node* node;
		bool up;
	};

	stackElem stack[100];
	int stackPoz;
	int freq;
	node* currentNode;

	

public:

	IteratorContainer(Container& c);
	TElem getCurrent();
	bool valid();
	void next();
	void first();
};

