#pragma once
#include "ListOfNeighbors.h"
#include <iostream>
#include <string>
class Vertex {
private:
	int VertexNum;
	ListOfNeighbors* list = nullptr;
public:
	Vertex(int n) {
		this->VertexNum = n;
		list = new ListOfNeighbors();
	}
	int getNum() { return VertexNum; }
	Node* getHead() { return list->getHead(); }
	ListOfNeighbors* getList() { return list; }

};

