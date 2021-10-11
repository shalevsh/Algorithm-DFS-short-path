#pragma once
#include "Node.h"
#include <iostream>

class ListOfNeighbors {
private:
	Node* head, *tail;
	int numOfvertices;
public:
	// ListOfNeighbors(const ListOfNeighbors& other) = delete; // not able to ctor
	//ListOfNeighbors& operator=(ListOfNeighbors& other) = delete;  // not able to = operator
	ListOfNeighbors() {
		MakeEmptyList();
	}
	~ListOfNeighbors() {
		delete head;
		delete tail;
	}
	void MakeEmptyList();
	bool find(const int vertex) const;
	void clear();
	void addToTail(int vertex);
	void DeleteNode(int vertex);
	int getListSize() const { return numOfvertices; }
	Node*getHead()const { return head; }
	void printList(int vertexNum);
	
};

