#include <iostream>
#include "SortedMap.h"
#include "IteratorContainer.h"
#include "ShortTest.h"
#include "ExtendedTest.h"

using namespace std;

bool increasing2(TKey c1, TKey c2) {
	if (c1 <= c2) {
		return true;
	}
	else {
		return false;
	}
}


int main() {


	testAll();
	cout << "short tests done\n";
	testAllExtended();
	cout << "all tests done\n";


	SortedMap sm(increasing2);
	
	sm.add(2, 3);
	sm.add(1, 4);
	sm.add(5, 5);
	sm.add(3, 4);
	sm.afis();
	cout<<sm.updateValues(sm);
	cout << "\n\n\n";
	sm.afis();

	getchar();

}
