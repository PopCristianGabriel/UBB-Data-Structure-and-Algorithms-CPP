#include "SortedMap.h"
#include "IteratorContainer.h"
#include <iostream>

//implementation of the operations from Container.h


SortedMap::SortedMap(Relation r) {
	this->head =(knot*) malloc(sizeof(knot));
	this->r = r;
	this->head->next = NULL;
	this->head->value.first = NULL;
	this->head->value.second = NULL;
}

knot * SortedMap::get_head()
{
	return this->head;
}

TValue SortedMap::add(TKey c, TValue v)
{
	bool found = false;
	knot* p = this->head;
	knot* prev = NULL;
	if (this->head->value.first == NULL && this->size() == 0) {
		this->head->value.first = c;
		this->head->value.second = v;
		this->listSize++;
		return NULL_TVALUE;
	}


	while (p != NULL && p->value.first != c && this->r(p->value.first, c) == true) {
		prev = p;
		p = p->next;
	}
	if (p == NULL)
	{
		knot* newKnot = (knot*)malloc(sizeof(knot));
		newKnot->next = NULL;
		prev->next = newKnot;
		newKnot->value.first = c;
		newKnot->value.second = v;
		this->listSize++;
		return NULL_TVALUE;
	}

	if (p->value.first == c) {
		int oldValue = p->value.second;
		p->value.second = v;
		return oldValue;
	}

	if (prev == NULL) {
		knot* newKnot = (knot*)malloc(sizeof(knot));
		newKnot->value.first = c;
		newKnot->value.second = v;
		newKnot->next = this->head;
		this->head = newKnot;
		this->listSize++;
		return NULL_TVALUE;
	}

	knot* newKnot = (knot*)malloc(sizeof(knot));
	newKnot->next = p;
	newKnot->value.first = c;
	newKnot->value.second = v;
	prev->next = newKnot;
	this->listSize++;
	return NULL_TVALUE;
	
}

TValue SortedMap::search(TKey c) const
{
	if (this->size() == 0) {
		return NULL_TVALUE;
	}
	knot*p = this->head;
	while (p != NULL) {
		if (p->value.first == c) {
			return p->value.second;
		}
		p = p->next;
	}
	return NULL_TVALUE;
}

TValue SortedMap::remove(TKey c)
{
	if (this->size() == 0) {
		return NULL_TVALUE;
	}
	knot* p = this->head;
	knot* prev = NULL;
	knot* next = p->next;
	while (p != NULL) {
		if (p != NULL && p->value.first == c) {
			if (p == this->head) {
				int value = this->head->value.second;
				if (p->next != NULL) {
					this->head = p->next;
					free(p);
					this->listSize--;
					return value;
				}
				this->head->value.first = NULL;
				this->listSize--;
				return value;
			}
			prev->next = next;
			int value = p->value.second;
			free(p);
			this->listSize--;
			return value;
		}
		prev = p;
		p = next;
		if(next != NULL)
		next = next->next;
	}
	return NULL_TVALUE;
}

int SortedMap::updateValues(SortedMap & sm)
{
	int nr;
	knot* p = this->head;
	while (p != NULL) {
		if (p->value.second != p->value.first) {
			nr = 1;
			int c, v;
			v = p->value.second;
			c = v;
			sm.remove(p->value.first);
			if (sm.add(c, v) != NULL_TVALUE) {
				nr = 2;
			}
			return nr + sm.updateValues(sm);
		}
		p = p->next;
	}
	return 0;
}

int SortedMap::size() const
{
	return this->listSize;
}

bool SortedMap::isEmpty() const
{
  	return this->head->value.first == NULL;
}

IteratorContainer SortedMap::iterator() const {
	return IteratorContainer(*this);
}

void SortedMap::afis()
{
	knot* p = this->head;
	while (p != NULL) {
		std::cout << "key: " << p->value.first << "Val: " << p->value.second << "\n";
		p = p->next;
	}
}


SortedMap::~SortedMap() {
	knot* p = this->head;
	while (p != NULL) {
		this->head = this->head->next;
		free(p);
		p = this->head;
	}
}


//the rest of the operations