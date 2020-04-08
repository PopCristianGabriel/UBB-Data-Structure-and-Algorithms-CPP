#include "IteratorContainer.h"
#include "Container.h"


IteratorContainer::IteratorContainer( Container& c): con(c) {
	this->stackPoz = -1;
	this->freq = 1;
	this->currentNode = con.get_root();
}

TElem IteratorContainer::getCurrent() {
	if (this->valid()) {
		return this->currentNode->information.v;
	}
}

bool IteratorContainer::valid() {
	return this->currentNode == nullptr;
}

void IteratorContainer::next() {
	if (this->freq < this->currentNode->information.f) {
		this->freq++;
	}
	else {
		if (this->currentNode->left != nullptr) {
			stackElem e;
			e.node = this->currentNode;
			e.up = false;
			this->currentNode = this->currentNode->left;
			this->stackPoz++;
			this->stack[this->stackPoz] = e;
			this->freq = 1;
			return;
		}
		else if (this->currentNode->right != nullptr) {
			stackElem e;
			e.node = this->currentNode;
			e.up = true;
			this->currentNode = this->currentNode->right;
			this->stackPoz++;
			this->stack[this->stackPoz] = e;
			this->freq = 1;
			return;
		}
		else {
			if (this->stackPoz != -1) {
				while (this->stackPoz != -1 && (this->stack[this->stackPoz].up == true || this->stack[this->stackPoz].node->right == nullptr)) {
					this->stackPoz--;
				}
			}
			this->freq = 1;
			if (this->stackPoz == -1) {
				this->currentNode = nullptr;
			}
			else {
				this->currentNode = this->stack[this->stackPoz].node;
				this->stack[this->stackPoz].up = true;
			}
		}
	}
}

void IteratorContainer::first() {
	this->currentNode = con.get_root();
}

