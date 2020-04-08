#include "Container.h"
#include "IteratorContainer.h"
#include <iostream>
#include <stdexcept>

//implementation of the operations from Container.h


Matrix::Matrix(int nrLines, int nrCols) {
	this->cols = nrCols;
	this->lines = nrLines;
	this->matrice = NULL;
	


	// TBA 
}

int Matrix:: nrLines() const {
	return this->lines;
}

int Matrix ::nrColumns() const {
	return this->cols;
}


TElem Matrix::element(int i, int j) const {
	if (i > this->lines || j > this->cols || i < 0 || j < 0) {
		throw std::exception("false");
	}
	if (this->matrice == NULL) {
		return 0;
	}
	
	triplet* auxiliar = this->matrice;
	while (auxiliar != NULL) {
		if (auxiliar->c == j && auxiliar->l == i) {
			return auxiliar->v;
		}
		auxiliar = auxiliar->urm;
	}
	return 0;
}

void Matrix :: transpusa() {
	triplet* auxiliar = this->matrice;
	while (auxiliar != NULL){
		int aux = auxiliar->c;
		auxiliar->c = auxiliar->l;
		auxiliar->l = aux;
		auxiliar = auxiliar->urm;
		}
	
}

int Matrix::get_val(int i, int j) {
	triplet* aux = this->matrice;
	while (aux != NULL) {
		if (aux->c == j && aux->l == i) {
			return aux->v;
		}
		aux = aux->urm;
	}
	return 0;
}

void Matrix::afis() {
	for (int i = 0; i < this->lines; i++) {
		for (int j = 0; j < this->cols; j++) {
			int val = get_val(i, j);
			std::cout << val << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}


TElem Matrix::modify(int i, int j, TElem e) {
	
	if (i > this->lines || j > this->cols || i < 0 || j < 0) {
		throw std::runtime_error("invalid position");
	}
	
	if (this->matrice == NULL){
		triplet* nod = (triplet*)malloc(sizeof(triplet));
		nod->c = j;
		nod->l = i;
		nod->v = e;
		nod->urm = NULL;
		nod->pre = NULL;
		this->matrice = nod;
		return 0;
		}
	triplet* auxiliar = this->matrice;
	while (auxiliar != NULL) {
		if (auxiliar->c == j && auxiliar->l == i) {
			TElem prev = auxiliar->v;
			auxiliar->v = e;
			return prev;
		}
		if(auxiliar->urm != NULL)
		auxiliar = auxiliar->urm;
		else {
			break;
		}
	}
	triplet* nod = (triplet*)malloc(sizeof(triplet));
	nod->c = j;
	nod->l = i;
	nod->v = e;
	nod->urm = NULL;
	nod->pre = auxiliar;
	auxiliar->urm = nod;
	return 0;



	
}

//the rest of the operations