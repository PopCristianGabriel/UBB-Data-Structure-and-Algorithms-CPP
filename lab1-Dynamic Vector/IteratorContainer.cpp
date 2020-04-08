#include "IteratorContainer.h"
#include "Container.h"


IteratorContainer::IteratorContainer(const Container& c) : con(c) {
	//initialize current and other specific attributes
	 currentIteration = 0;
}

TElem IteratorContainer::getCurrent() {
	//TBA
	if (valid() == true) {
		return con.vector[currentIteration];
	}
	else {
		throw;
	}
}

bool IteratorContainer::valid() {
	//TBA
	return(currentIteration < con.len);
}

void IteratorContainer::next() {
	if (valid() == true) {
		currentIteration++;
	}
	else {
		throw;
	}
}

void IteratorContainer::first() {
	currentIteration = 0;
}

