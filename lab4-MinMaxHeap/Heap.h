#pragma once

#include <exception>

typedef int TElem;
typedef bool(*Relation) (TElem e1, TElem e2);


class Heap {


private:

	int capacity;
	int length;
	TElem* elems;
	Relation r;

	void resize();

	void bubbleUp(int position);

	void bubbleDown(int position);

public:
	int get_len();

	Heap(Relation rel);

	void add(TElem new_elem);

	TElem remove();

	~Heap();

};

