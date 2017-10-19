/*
 * skiplist.h
 *
 *  Created on: 2017. okt. 9.
 *      Author: Bence
 */
#include <algorithm>
#include <vector>
#include <time.h>
#include <stdlib.h>
#ifndef SKIPLIST_H_
#define SKIPLIST_H_

class skiplist {
public:
	skiplist();
	~skiplist();
	void insert(int);
	void erase(int);
	bool contains(int);
    size_t size();
private:
	class Node	{
	public:
		int value;
		std::vector <Node*> next;
		Node() {};
		Node(const int& value0) :value(value0) {};
	};
	Node *min=new Node();
	Node *max=new Node();
	Node *cur;

};

#endif /* SKIPLIST_H_ */
