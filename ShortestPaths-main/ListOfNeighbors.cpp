#include "ListOfNeighbors.h"
using namespace std;
void ListOfNeighbors::MakeEmptyList() {
	head = tail = nullptr;
	numOfvertices = 0;
}

bool ListOfNeighbors::find(const int vertexNum) const {
	bool res = false;
	Node*curr = head;

	while (!res&& curr) {
		if (curr->getVertex() == vertexNum)
			res = true;
		curr = curr->getNext();
	}
	return res;
}

void ListOfNeighbors::clear() {
	Node* temp = head;
	if (temp == nullptr)
		return;
	while (temp != nullptr) {
		head = head->getNext();
		delete temp;
		temp = head;
	}
	numOfvertices = 0;
}

void ListOfNeighbors::addToTail(int vertex) {
	Node* node = new Node(vertex, nullptr);
	if (!head)
		head = tail = node;
	else {
		tail->setTail(node);
		tail = node;
	}
	numOfvertices++;
}

void ListOfNeighbors::DeleteNode(int vertex) {
	Node* curr = head, *prev = nullptr;
	
	if (head == tail) {
		if (head && head->getVertex() == vertex) {
			clear();
			numOfvertices--;
		}
		return;
	}
	else if (head->getVertex() == vertex) {
		head = curr->getNext();
		delete curr;
		numOfvertices--;
		return;
	}
	else {
		while (curr->getVertex() != vertex && curr != nullptr) {
			prev = curr;
			curr = curr->getNext();
		}
		if (!curr)
			return;
		if (curr == tail)
		tail = prev;
		
		prev->setTail(curr->getNext());
		delete curr;
		numOfvertices--;

	}
}

void ListOfNeighbors::printList(int vertexNum) {
	Node* temp = new Node(head->getVertex(), head->getNext());

	for (int i = 0; i < numOfvertices; i++) {
		cout<<"     " <<vertexNum<<"     "<< temp->getVertex()<< endl;
		if(temp->getNext())
		temp->setNext(temp->getNext());
	}
	delete temp;
}


