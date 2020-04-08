#include "Heap.h"



int Heap::get_len()
{
	return this->length;
}

Heap::Heap(Relation rel) {
	this->capacity = 10;
	this->length = 0;
	this->elems = new TElem[this->capacity + 1];
	this->r = rel;
}


Heap::~Heap() {
	delete[] this->elems;
}


void Heap::resize() {
	this->capacity *= 2;
	TElem* new_list = new TElem[this->capacity + 1];
	for (int i = 1; i <= this->length; i++) {
		new_list[i] = this->elems[i];
	}
	delete[] this->elems;
	this->elems = new_list;
}


void Heap::add(TElem new_elem) {
	if (this->length >= this->capacity) {
		this->resize();
	}
	this->length += 1;
	this->elems[this->length] = new_elem;
	this->bubbleUp(this->length);
}


void Heap::bubbleUp(int position) {
	int child = position;
	int parent = position / 2;
	while (!(this->r(this->elems[child] , this->elems[parent])) && parent != 0) {
		TElem aux;
		aux = this->elems[child];
		this->elems[child] = this->elems[parent];
		this->elems[parent] = aux;
		child = parent;
		parent = child / 2;
	}
}


TElem Heap::remove() {
	if (this->length == 0) {
		throw std::exception("Empty heap");
	}
	TElem removed_elem = this->elems[1];
	this->elems[1] = this->elems[this->length];
	this->length -= 1;
	this->bubbleDown(1);
	return removed_elem;
}


void Heap::bubbleDown(int position) {
	int parent = position;

	while (parent <= this->length) {
		int child1 = position * 2;
		int child2 = position * 2 + 1;
		int minChild = -1;


		if (child1 <= this->length) {
			minChild = child1;
		}
		
		if (child2 <= this->length && this->r(this->elems[child2] , this->elems[child1])) {
			minChild = child2;
		}

		if (minChild != -1 && !this->r(this->elems[parent] , this->elems[minChild])) {
			TElem aux = this->elems[parent];
			this->elems[parent] = this->elems[minChild];
			this->elems[minChild] = aux;
			parent = minChild;
		}
		else {
			break;
		}
	}
}