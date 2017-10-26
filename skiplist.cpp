/*
 * skiplist.cpp
 *
 *  Created on: 2017. okt. 9.
 *      Author: Bence
 */

#include "skiplist.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

skiplist::skiplist() {

	min = new Node();
	max = new Node();
	min->next.push_back(max);
	max->next.push_back(nullptr);

}

skiplist::~skiplist() {

}

void skiplist::insert(int k) {
	Node *fresh = new Node(k);
	srand(time(NULL));
	unsigned int szint = 0;
	/*unsigned int rnd=1;
	 while(rnd==1 and szint<10){
	 rnd=rand() % 2;
	 szint++;
	 }
	 while(min->next.size()<=szint){
	 min->set_ptr(max);
	 max->set_ptr(nullptr);
	 }
	 for(int i=0;i<=szint;i++){
	 fresh->set_ptr(max);
	 insertbtw(szint,fresh);
	 }*/
	fresh->set_ptr(max);
	insertbtw(szint, fresh);

}

void skiplist::erase(int k) {
	Node *cur = min;
	int lvl = min->next.size() - 1;
	while (cur->next[lvl]->value < k and cur->next[0]->next[0] != nullptr) {
		cur = cur->next[lvl];
	}
	if (cur->next[lvl]->value == k) {
		Node *del = cur->next[lvl];
		cur->next[lvl] = cur->next[lvl]->next[lvl];
		delete del;
	}
}

bool skiplist::contains(int k) {
	Node *cur = min;
	int lvl = min->next.size() - 1;
	while (cur->next[lvl]->value < k and cur->next[0]->next[0] != nullptr) {
		cur = cur->next[lvl];
	}
	if (cur->next[lvl]->value == k) {

		return true;
	} else
		return false;
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

void skiplist::print() {
	Node* cur = min;
	while (cur->next[0]->next[0] != nullptr) {
		std::cout << cur->next[0]->value << ' ';
		cur = cur->next[0];
	}
	std::cout << std::endl;

}

void skiplist::insertbtw(int szint, Node *fresh) {
	Node* cur = min;
	//üres
	if (cur->next[szint]->next[szint] == nullptr) {
		fresh->change_ptr(cur->next[szint], szint);
		cur->change_ptr(fresh, szint);
	}
	//1 elem
	else if(cur->next[szint]->next[szint]->next[szint] == nullptr){
		if(cur->next[szint]->value>fresh->value){
			fresh->change_ptr(cur->next[szint],szint);
			cur->change_ptr(fresh,szint);
		}
		else {
			fresh->change_ptr(max,szint);
			cur->next[szint]->change_ptr(fresh,szint);
		}
	}
	// több elem
	else {
		while (cur->next[szint]->value < fresh->value and cur->next[szint]->next[szint]->value > fresh->value
				and cur->next[szint]->next[szint] != nullptr) {
			cur = cur->next[szint];
		}
	}
	fresh->change_ptr(cur->next[szint], szint);
	cur->change_ptr(fresh, szint);
}
