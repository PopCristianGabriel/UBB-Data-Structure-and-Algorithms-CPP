#include "Container.h"
#include "IteratorContainer.h"
#include <iostream>

//implementation of the operations from Container.h


Container::Container() {
	this->vector = (long*)malloc(5 * sizeof(long));
	this->len = 0;
	this->cap = 5;
}

IteratorContainer Container::iterator() const {
	return IteratorContainer(*this);
}



Container::~Container() {
	// TBA
	free(this->vector);
	this->vector = NULL;
}

//the rest of the operations


bool Container::add(TElem e) {
	bool exists = this->search(e);

	if (exists == true) {
		return false;
	}
	if (this->len == this->cap) {
		long* copy = (long*)realloc(this->vector, 2*this->cap*sizeof(long));
		this->cap *= 2;
		if (copy == NULL) {
			throw;
		}
		this->vector = copy;
		copy = NULL;
		free(copy);
	}
	
	this->vector[this->len] = e;
	this->len++;
	return true;

}


bool Container::remove(TElem e) {
	for (long i = 0; i < this->len; i++) {
		if (e == this->vector[i]) {
			for (long j = i; j < this->len - 1; j++) {
				this->vector[j] = this->vector[j + 1];
			}
			this->len--;
			return true;
		}
	}
	return false;
}

bool Container::search(TElem elem) const {
	for (long i = 0; i < this->len; i++) {
		if (this->vector[i] == elem) {
			return true;
		}
	}
	return false;
}

long Container::size() const {
	return this->len;
}

bool Container::isEmpty() const {
	return this->len == 0;
}


