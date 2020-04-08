#pragma once
#include <list>
#include "Heap.h"
using namespace std;




//merges k sorted lists into one single list.
//the input lists are sorted considering the relation and the results should be sorted in the same way.
list<TElem> mergeLists(list<list<TElem>> inputLists, Relation rel);