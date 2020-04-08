#pragma once;

typedef int TElem;

//other definitions if necessary (relation, null elements)

class IteratorContainer;
typedef struct Pair {
	int val;
	int freq;
};

typedef struct node {
	Pair p;
	node* next;

};

typedef struct hashSlot {
	node* head;
	int alpha;
};
class Container {

	friend class IteratorContainer;

private:
	//container representation
	int nrOfElems;
	hashSlot* hashTable;
	int Size;
	int alphaThreshHold;

	int hash_function(int x);
	void rehash_table();
public:
	//implicit constructor
	Container();

	hashSlot* get_hash_table();
	void add(TElem e);



	//removes one occurrence of an element from a bag

	//returns true if an element was removed, false otherwise (if e was not part of the bag)

	bool remove(TElem e);
	void addOccurences(int nr, TElem elem);


	//checks if an element appearch is the bag

	bool search(TElem e);



	//returns the number of occurrences for an element in the bag

	int nrOccurrences(TElem e);



	//returns the number of elements from the bag

	int size() const;




	//specific operations

	//returns an iterator for the container
	IteratorContainer iterator() const;

	void free_SLL(node* head);

	//checks if the bag is empty

	bool isEmpty() const;


	//destructor
	~Container();

};

