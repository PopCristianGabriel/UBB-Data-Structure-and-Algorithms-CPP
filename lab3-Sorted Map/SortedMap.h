#pragma once;
#include <utility>

//other definitions if necessary (relation, null elements)

class IteratorContainer;

typedef int TKey;

typedef int TValue;





typedef std::pair<TKey, TValue> TElem;



#define NULL_TVALUE -1



typedef bool(*Relation)(TKey, TKey);


typedef struct knot{
	TElem value;
	knot* next;
	knot* prev;
}knot;


class SortedMap {

private:

	
	Relation r;
	int listSize;
	//representation of SortedMap



public:
	knot* head;



	// implicit constructor

	SortedMap(Relation r);



	// adds a pair (key,value) to the map

	//if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned

	//if the key does not exist, a new pair is added and the value null is returned

	knot* get_head();

	TValue add(TKey c, TValue v);



	//searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TELEM otherwise

	TValue search(TKey c) const;





	//removes a key from the map and returns the value associated with the key if the key existed or null: NULL_TELEM otherwise

	TValue remove(TKey c);


	int updateValues(SortedMap& sm);


	//returns the number of pairs (key,value) from the map

	int size() const;



	//checks whether the map is empty or not

	bool isEmpty() const;



	// return the iterator for the map

	// the iterator will return the keys following the order given by the relation

	IteratorContainer iterator() const;


	void afis();
	// destructor

	~SortedMap();

};

