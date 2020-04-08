#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include "Container.h"
#include "IteratorContainer.h"
#include <windows.h>
#include <crtdbg.h>
#include "ShortTest.h"
#include "ExtendedTest.h"
using namespace std;


int main() {


	testAll();
	testAllExtended();
	cout<<"all tests are done";
	getchar();
	return 0;

}
