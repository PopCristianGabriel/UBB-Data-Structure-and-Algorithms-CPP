#pragma once
#include "SortedMap.h"

class Container;

class IteratorContainer
{
	friend class SortedMap;

private:
	//the iterator stores a reference to the container 
	const SortedMap& con;
	knot* p;
	knot* head;
	//other specific attributes: current, etc

	IteratorContainer(const SortedMap& c);

public:
	TElem getCurrent();
	bool valid();
	void next();
	void first();
};

