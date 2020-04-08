#pragma once;

typedef int TElem;

//other definitions if necessary (relation, null elements)

class IteratorContainer;





class Container {

	friend class IteratorContainer;
	

private:
	//container representation
	long *vector;
	long len;
	long cap;

public:
	//implicit constructor
	Container();


	bool add(TElem e);
	bool remove(TElem e);
	bool search(TElem elem) const;
	long size() const;
	bool isEmpty() const;
	//specific operations

	//returns an iterator for the container
	IteratorContainer iterator() const;

	//destructor
	~Container();

};

