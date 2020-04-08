#pragma once;

typedef int TElem;


typedef struct triplet {
	int l, c;
	TElem v;
	triplet* urm;
	triplet* pre;
}triplet;

//other definitions if necessary (relation, null elements)

class IteratorContainer;

class Matrix {



private:
	triplet* matrice;
	int cols; int lines;
	/*representation of the matrix*/

public:

	//constructor

	//throws exception if nrLines or nrCols is negative or zero

	Matrix(int nrLines, int nrCols);



	//returns the number of lines

	int nrLines() const;



	//returns the number of columns

	int nrColumns() const;



	//returns the element from line i and column j (indexing starts from 0)

	//throws exception if (i,j) is not a valid position in the Matrix

	TElem element(int i, int j) const;



	//modifies the value from line i and column j

	//returns the previous value from the position

	//throws exception if (i,j) is not a valid position in the Matrix

	TElem modify(int i, int j, TElem e);

	void transpusa();
	void afis();
	int get_val(int i, int j);

};

