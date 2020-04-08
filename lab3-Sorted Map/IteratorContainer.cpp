#include "IteratorContainer.h"
#include <stdexcept>

IteratorContainer::IteratorContainer(const SortedMap& c): con(c) {
	this->p = con.head;
	this->head = con.head;
	
}

TElem IteratorContainer::getCurrent() {
	if (this->valid() == true) {
		return p->value;
	}
	else throw std::invalid_argument(0);
}

bool IteratorContainer::valid() {
	if (this->p == this->head) {
		return this->p->value.first != NULL;
	}
	return this->p != NULL;
}

void IteratorContainer::next() {
	if(this->valid() == true)
		this->p = this->p->next;
	else throw std::invalid_argument(0); 
}

void IteratorContainer::first() {
	this->p = this->head;
}

