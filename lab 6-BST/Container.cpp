#include "Container.h"
#include "IteratorContainer.h"
#include <iostream>

//implementation of the operations from Container.h


Container::Container() {
	// TBA 
}

Container::Container(Relation r)
{
	this->r = r;
	this->root = NULL;
	this->Size = 0;
}

void Container::add(TComp e)
{
	this->Size++;
	if (this->root == NULL) {
		node* newNode = new node;
		newNode->information.f = 1;
		newNode->information.v = e;
		newNode->left = NULL;
		newNode->right = NULL;
	}
	node*p = this->root;
	node*pp = NULL;
	while (p != NULL && p->information.v != e) {
		if (this->r(p->information.v, e)) {
			pp = p;
			p = p->left;
		}
		else {
			pp = p;
			p = p->right;
		}
		
	}
	if (p != NULL) {
		p->information.f++;
	}
	else {
		node* nodeToAdd = new node;
		nodeToAdd->information.f = 1;
		nodeToAdd->information.v = e;
		nodeToAdd->left = NULL;
		nodeToAdd->right = NULL;
		if (this->r(pp->information.v, e)) {
			pp->left = nodeToAdd;
		}
		else {
			pp->right = nodeToAdd;
		}
	}

}

bool Container::remove(TComp e)
{
	node* found = this->mySearch(e, this->root);
	if (found != NULL) {
		if (found->information.f > 1) {
			found->information.f--;
			return true;
		}
		if (found->left == NULL && found->right != NULL) {
			found = found->right;
			return true;
		}
		if (found->left != NULL && found->right == NULL) {
			found = found->left;
			return true;
		}
		node*p = found->left;
		node* pp = found;
		int max;
		if (p != NULL) {
			max = p->information.v;
			while (p->left != NULL) {
				pp = p;
				p = p->left;
			}
			found = p;
			free(p);
			pp->left = NULL;
			return true;
		}
		this->Size--;

	}
	return false;
}

node * Container::mySearch(TComp e,node* node)
{
	if (node != NULL) {
		if (node->information.v == e) {
			return node;
		}
		else {
			
				this->mySearch(e, node->left);
				this->mySearch(e, node->right);
			
		}
	}
	return NULL;
}

bool Container::search(TComp e) 
{
	return this->mySearch(e, this->root) != NULL;
}

int Container::nrOccurrences(TComp e) 
{
	node* p = this->mySearch(e, this->root);
	if (p == NULL) {
		return 0;
	}
	return p->information.f;
}

int Container::size() 
{
	return this->Size;
}

node * Container::get_root()
{
	return this->root;
}


void Container::dealocate(node * node)
{
	if (node->left != NULL) {
		dealocate(node->left);
	}
	if (node->right != NULL) {
		dealocate(node->right);
	}
	free(node);
	node = NULL;
}

bool Container::isEmpty() 
{
	return this->Size == 0;
}


Container::~Container() {
	this->dealocate(this->root);
}


//the rest of the operations