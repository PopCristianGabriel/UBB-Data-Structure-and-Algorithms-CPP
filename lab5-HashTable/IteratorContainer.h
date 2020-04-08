#pragma once
#include "Container.h"

class Container;

class IteratorContainer
{
	friend class Container;

private:
	hashSlot* hashTable;
	node* head;
	int i;
	int j;
	int size;
	//the iterator stores a reference to the container 
	const Container& con;
	//other specific attributes: current, etc

	IteratorContainer(const Container& c);

public:
	TElem getCurrent();
	bool valid();
	void next();
	void first();
};

