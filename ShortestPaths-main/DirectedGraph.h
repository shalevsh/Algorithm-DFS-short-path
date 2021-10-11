#pragma once
#include"Vertex.h"
class DirectedGraph {
private:
	int size = 0;
	Vertex** arr = nullptr;
public:
	DirectedGraph(int size) {
		MakeEmptyGraph(size);
		for (int i = 0; i < size; i++) {
			arr[i] = new Vertex(i);
		}
	}
	~DirectedGraph() {
		for (int i = 0; i < size; i++) {
			delete arr[i];
		}
	}
	void MakeEmptyGraph(int size);
	bool IsAdjacent(Vertex* u, Vertex* v) const;
	void AddEdge(Vertex* u, Vertex* v);
	void RemoveEdge(int u, int v);
	int getNumOfVertices() const { return size; }
	Node* GetAdjList(int index) const { return arr[index]->getHead(); }
	//Node* adj(int i);
	int isEmpty();
	void PrintGraph();
	int AddEdge(int i, int j);
	int* BFS(int i);
	void updateGraph(int* distanceArr);
	DirectedGraph* buildGraphT();
	Vertex** getVertexArr() { return arr; }


};

