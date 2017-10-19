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

		void set_ptr(Node *ptr0)
		{
			this->next.push_back(ptr0);
		}

		void change_ptr(Node *ptr0,int lvl)
		{
			this->next[lvl]=ptr0;
		}

	};
	Node *min;
	Node *max;



};

#endif /* SKIPLIST_H_ */
