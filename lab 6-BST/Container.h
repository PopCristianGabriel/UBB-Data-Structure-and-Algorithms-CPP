#pragma once


typedef int TComp;

typedef TComp TElem;

typedef bool(*Relation)(TComp, TComp);


typedef struct info {
	int v;
	int f;
};
typedef struct node {
	info information;
	node* left;
	node* right;
};


class Container {



private:
	node* root;
	Relation r;
	int Size;
	/*representation of SortedBag*/



public:
	IteratorContainer iterator() {
		return IteratorContainer(*this);
	}
	//constructor
	Container();
	Container(Relation r);



	//adds an element to the sorted bag

	void add(TComp e);



	//removes one occurrence of an element from a sorted bag

	//returns true if an element was removed, false otherwise (if e was not part of the sorted bag)

	bool remove(TComp e);



	//checks if an element appearch is the sorted bag

	bool search(TComp e) ;


	node* mySearch(TComp e, node* node);
	void dealocate(node* node);
	//returns the number of occurrences for an element in the sorted bag

	int nrOccurrences(TComp e) ;



	//returns the number of elements from the sorted bag

	int size();



	//returns an iterator for this sorted bag

	

	node* get_root();

	//checks if the sorted bag is empty

	bool isEmpty();


	

	~Container();

};