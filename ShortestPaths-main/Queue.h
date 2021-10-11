#pragma once
#include <iostream>

using namespace std;
// A class to store a queue

class Queue{
private:
	int *arr, capacity, front, rear, count;
	// array to store queue elements
	// maximum capacity of the queue
	// front points to the front element in the queue (if any)
	// rear points to the last element in the queue
	// current size of the queue

public:
	Queue(int size) {
		arr = new int[size];
		capacity = size;
		front = 0;
		rear = -1;
		count = 0;
	}    
	~Queue() {
		delete[] arr;
	}                 // destructor
	void dequeue();
	void enqueue(int x);
	int peek();
	int size();
	bool isEmpty();
	bool isFull();
};



