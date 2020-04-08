#include "IteratorContainer.h"
#include "Container.h"


IteratorContainer::IteratorContainer(const Container& c): con(c) {
	auxiliar = con.matrice;
}

TElem IteratorContainer::getCurrent() {
 
}

bool IteratorContainer::valid() {
	return auxiliar == nullptr;

}

void IteratorContainer::next() {
	if (valid() ){
		auxiliar = auxiliar->urm;
	}
	//TBA
}

void IteratorContainer::first() {
	auxiliar = con.matrice;
}

