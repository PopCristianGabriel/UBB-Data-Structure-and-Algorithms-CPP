#include "IteratorContainer.h"
#include "Container.h"
#include <stdexcept>
#include <stddef.h>

IteratorContainer::IteratorContainer(const Container& c) : con(c) {
	this->hashTable = c.hashTable;
	this->size = c.Size;
	this->i = 0;
	this->head = this->hashTable[i].head;
	int j = 1;
}

TElem IteratorContainer::getCurrent() {
	if(this->valid())
		while (this->hashTable[this->i].head == NULL && valid()) {
			this->i++;
	}
	if (valid()) {
		this->head = this->hashTable[this->i].head;
		return this->head->p.val;
	}
	else throw std::invalid_argument(0);
}

bool IteratorContainer::valid() {
	return this->i < this->con.size();
}

void IteratorContainer::next() {
	if (this->valid()) {
		this->j++;
		if (this->head->p.freq -1 < j) {
			this->head = this->head->next;
			j = 1;
			if (!this->head) {
				this->i++;
				while (this->hashTable[this->i].head == NULL && valid()) {
					this->i++;
				}
				if (valid()) {
					this->head = this->hashTable[this->i].head;
			}
			}
		}
		
	}
	if (!valid())
		throw std::invalid_argument(0);
}

void IteratorContainer::first() {
	j = 1;
	i = 1;
	while (!this->hashTable[this->i].head && valid()) {
		this->i++;
	}
}

