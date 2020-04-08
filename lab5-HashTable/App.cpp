#include <iostream>
#include "Container.h"
#include "IteratorContainer.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
using namespace std;


int main() {


	//testAll();
	testAllExtended();
	Container b;
	IteratorContainer it = b.iterator();
	b.add(100);
	b.add(34);
	it.first();
	it.getCurrent();
	b.remove(100);
	b.remove(34);
	cout << "dawawdawd";
	getchar();


}
