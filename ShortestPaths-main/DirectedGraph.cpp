#include "DirectedGraph.h"
#include <iostream>
#include "Queue.h"
using namespace std;
void DirectedGraph::MakeEmptyGraph(int size) {
	arr = new Vertex * [size];
	this->size = size;
}

bool DirectedGraph::IsAdjacent(Vertex* u, Vertex* v) const {
	return arr[u->getNum() - 1]->getList()->find(v->getNum());
}

void DirectedGraph::AddEdge(Vertex* u, Vertex* v) {
	arr[u->getNum() - 1]->getList()->addToTail(v->getNum());
}

void DirectedGraph::RemoveEdge(int u, int v) {
	arr[u]->getList()->DeleteNode(v);
}

int DirectedGraph::isEmpty() {
	return size;
}

void DirectedGraph::PrintGraph() {
	for (int i = 0; i < size; i++) {
		if (arr[i]->getList()->getHead())
			arr[i]->getList()->printList(i + 1);
	}
}

int DirectedGraph::AddEdge(int i, int j) {
	if (i<0 || i>size || arr[i - 1]->getList()->find(j)) {
		return 0;
	}
	Vertex A{ i };
	Vertex B{ j };
	this->AddEdge(&A, &B);
	return 1;
}
int* DirectedGraph::BFS(int s) {
	Node* temp = nullptr;
	bool* visited = new bool[size];
	int* parents = new int[size];
	int* d = new int[size];
	for (int i = 0; i < size; i++) {
		visited[i] = false;
		d[i] = -1;
		parents[i] = -1;
	}
	d[s - 1] = 0;
	
	Queue queue(size);
	
	visited[s - 1] = true;
	queue.enqueue(s);

	while (!queue.isEmpty()) {
		
		s = queue.peek();
		queue.dequeue();

		if(arr[s - 1]->getHead())
		 temp = new Node(arr[s - 1]->getHead()->getVertex(), arr[s - 1]->getHead()->getNext());
		int k;
		for (int i = 0; i < arr[s - 1]->getList()->getListSize(); i++) {
			k = temp->getVertex() - 1;

			if (!visited[k]) {
				visited[k] = true;
				d[k] = d[s - 1] + 1;
				parents[k] = s;
				queue.enqueue(k+1);
			}

			if (temp->getNext())
				temp->setNext(temp->getNext());
		}
		if (temp) {
			delete temp;
			temp = nullptr;
		}
	}
	return d;
}

void DirectedGraph::updateGraph(int* distanceArr)
{
	for (int i = 0; i < size; i++) {
		Node* head = arr[i]->getList()->getHead();
		Node* temp = nullptr;
		if (head)
			temp = new Node(head->getVertex(), head->getNext());
		if (distanceArr[i] == -1)
			arr[i]->getList()->clear();
		else {
			int size = arr[i]->getList()->getListSize();
			for (int j = 0; j < size; j++) {

				if ((distanceArr[temp->getVertex() - 1] == -1) || (distanceArr[i] + 1) != (distanceArr[temp->getVertex() - 1])) {
					RemoveEdge(i, temp->getVertex());
				}
				if (temp->getNext())
					temp->setNext(temp->getNext());
			}
		}
			delete temp;	
	}
}

DirectedGraph* DirectedGraph::buildGraphT()
{
	DirectedGraph* dGraphT = new DirectedGraph(size);

	for (int i = 0; i < size; i++) {
		Node* head = arr[i]->getList()->getHead();
		Node* temp = nullptr;
		if (head)
			temp = new Node(head->getVertex(), head->getNext());

		int sizeOfList = arr[i]->getList()->getListSize();
		for (int j = 0; j < sizeOfList; j++)
		{
			dGraphT->AddEdge(temp->getVertex(), i + 1);
			if (temp->getNext())
				temp->setNext(temp->getNext());
		}
	}
	return dGraphT;
}

