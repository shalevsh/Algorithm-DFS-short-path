#pragma once
class Node {
private:
	int vertex;
	Node* next;
public:
	Node(int vertex, Node*next = nullptr) {
		this->vertex = vertex;
		this->next = next;
	}
	int getVertex() { return vertex; }
	Node* getNext() { return next; }
	void setNext(Node*next) {
		this->vertex = next->getVertex();
		this->next = next->getNext();
	}
	void setTail(Node*next) {
		this->next = next;
	}
};

