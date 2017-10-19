/*
 * skiplist.cpp
 *
 *  Created on: 2017. okt. 9.
 *      Author: Bence
 */

#include "skiplist.h"
#include <iostream>

skiplist::skiplist() {

	min = new Node();
	max = new Node();
	min->next.push_back(max);
	max->next.push_back(nullptr);

}

skiplist::~skiplist() {

}

void skiplist::insert(int k) {
	Node *cur = min;
	int lvl = min->next.size() - 1;

	//URES SKIPLIST ESETEN
	if (size() < 1) {
		Node * fresh = new Node(k);
		fresh->set_ptr(cur->next[0]);
		cur->change_ptr(fresh, 0);

		//MAR VAN ELEM A LISTABAN
	} else {
		while (cur->next[lvl]->value < k and cur->next[0]->next[0] != nullptr
				and lvl >= 0) {
			if (cur->next[lvl]->value < k)
				cur = cur->next[lvl];
			else
				lvl--;
		}
		Node *fresh = new Node(k);
		fresh->set_ptr(cur->next[0]);
		cur->change_ptr(fresh, 0);

	}

}

void skiplist::erase(int k) {
	Node *cur = min;
	int lvl = min->next.size() - 1;
	while (cur->next[lvl]->value < k and cur->next[0]->next[0] != nullptr) {
		if (cur->next[lvl]->value < k)
			cur = cur->next[lvl];
		else
			lvl--;
	}
	if (cur->next[lvl]->value == k) {
		cur->next[lvl] = cur->next[lvl]->next[lvl];
	}

}

bool skiplist::contains(int k) {

	return true;
}

size_t skiplist::size() {
	int counter = -1;
	Node *cur = min;
	while (cur->next[0] != nullptr) {
		cur = cur->next[0];
		counter++;
	}

	return counter;
}

