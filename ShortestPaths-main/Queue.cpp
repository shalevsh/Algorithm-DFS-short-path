#include "Queue.h"
// Utility function to dequeue the front element
void Queue::dequeue()
{
	// check for queue underflow
	if (isEmpty())
	{
		exit(1);
	}

	front = (front + 1) % capacity;
	count--;
}

// Utility function to add an item to the queue
void Queue::enqueue(int item)
{
	// check for queue overflow
	if (isFull())
	{
		
		exit(1);
	}


	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}

// Utility function to return the front element of the queue
int Queue::peek()
{
	if (isEmpty())
	{
	
		exit(1);
	}
	return arr[front];
}

// Utility function to return the size of the queue
int Queue::size() {
	return count;
}

// Utility function to check if the queue is empty or not
bool Queue::isEmpty() {
	return (size() == 0);
}

// Utility function to check if the queue is full or not
bool Queue::isFull() {
	return (size() == capacity);
}
