#include "Container.h"
#include "IteratorContainer.h"
#include <iostream>

//implementation of the operations from Container.h


Container::Container() {
	this->Size = 37;
	this->hashTable = new hashSlot[37];
	for (int i = 0; i < this->Size; i++) {
		this->hashTable[i].head = NULL;
		this->hashTable[i].alpha = 0;
	}
	this->nrOfElems = 0;
}

IteratorContainer Container::iterator() const {
	return IteratorContainer(*this);
}

void Container::free_SLL(node * head)
{
	if (head->next != NULL) {
		this->free_SLL(head->next);
	}
	free(head);
}

bool Container::isEmpty() const
{
	return this->nrOfElems == 0;
}


Container::~Container() {
	for (int i = 0; i < this->Size; i++) {
		if(this->hashTable[i].head)
		this->free_SLL(this->hashTable[i].head);
	}
	
}

int Container::hash_function(int x)
{
	return abs(x) % this->Size;
}

void Container::rehash_table()
{
	//this->size *= 2;

}

hashSlot * Container::get_hash_table()
{
	return this->hashTable;
}


void Container::add(TElem e)
{
	this->nrOfElems++;
	int key = this->hash_function(e);
	node* p = this->hashTable[key].head;
	node* newNode = new node;
	newNode->next = NULL;
	newNode->p.val = e;

	if (!p) {
		this->hashTable[key].head = newNode;
		this->hashTable[key].alpha = 1;
		this->hashTable[key].head->p.freq = 1;
		return;
	}
	node* b4 = p;
	while (p != NULL && p->p.val != e) {
		b4 = p;
		p = p->next;
	}
	if (p) {
		p->p.freq++;
		free(newNode);
	}
	else {
		b4->next = newNode;
		newNode->p.freq = 1;
	}
	this->hashTable->alpha++;
	//free(b4);
}


bool Container::remove(TElem e)
{
	int key = this->hash_function(e);
	node* p = this->hashTable[key].head;
	node* b4 = NULL;
	while (p != NULL and p->p.val != e) {
		b4 = p;
		p = p->next;
	}
	if (p == NULL) {
		return false;
	}
	this->nrOfElems--;
	p->p.freq--;
	
	if (!p->p.freq) {
		if (b4 == NULL) {
			this->hashTable[key].head = this->hashTable[key].head->next;
			return true;
		}
		b4->next = p->next;
		free(p);
		this->hashTable[key].alpha--;
	}
	return true;


}

void Container::addOccurences(int nr, TElem elem)
{
	if (nr < 0) {
		throw std::invalid_argument(0);
	}
	else {
		for (int i = 0; i < nr; i++) {
			this->add(elem);
		}
	}
}

bool Container::search(TElem e)
{
	int key = this->hash_function(e);
	node* p = this->hashTable[key].head;
	while (p != NULL && p->p.val != e) {
		p = p->next;
	}
	if (p) {
		return true;
	}
	return false;

}

int Container::nrOccurrences(TElem e)
{
	int key = this->hash_function(e);
	node*p = this->hashTable[key].head;
	while (p != NULL && p->p.val != e) {
		p = p->next;
	}
	if (p) {
		return p->p.freq;
	}
	return 0;

}

int Container::size() const
{
	return this->nrOfElems;
}
//the rest of the operations