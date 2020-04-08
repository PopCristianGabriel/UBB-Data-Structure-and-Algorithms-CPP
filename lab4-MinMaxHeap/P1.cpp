#include "P1.h"

list<TElem> mergeLists(list<list<TElem>> inputLists, Relation rel){
	Heap heap(rel);
	list<TElem> res;
	for (auto current_list = inputLists.begin(); current_list != inputLists.end(); current_list++) {
		for (auto current_elem = current_list->begin(); current_elem != current_list->end(); current_elem++) {
			heap.add(*current_elem);
		}
	}
	while (heap.get_len() > 0) {
		res.push_back(heap.remove());
	}
	return res;
}
