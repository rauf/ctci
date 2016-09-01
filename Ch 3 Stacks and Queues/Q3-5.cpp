#include<iostream>
#include<cstring>
#include<stdio.h>

class Stack{

	int *arr;
	int top;
	int size;

public:
	Stack(int _size) {
		size = _size;
		arr = new int[size];
		top = -1;
	}

	void push(int n) {
		if(top > size) return;
		arr[++top] = n;
	}

	int pop() {
		if(top <= -1) return -1;

		int n = arr[top];
		top--;
		return n;
	}

	void print() {
		std::cout << "\nStack: ";
		for (int i = 0; i <= top; ++i)
				std::cout << arr[i] << "  ";
		std::cout << std::endl;
	}
	
	int getTop() {
		return top;
	}
};


class MyQueue{

	int size;
	Stack *s1;
	Stack *s2;

public:
	MyQueue(int size){
		this->size = size;
		s1 = new Stack(size);
		s2 = new Stack(size);
	}

	void enqueue(int n) {
		s1->push(n);
	} 

	void transfer() {
		while(s1->getTop() > -1) {
			s2->push(s1->pop());
		}

	}

	int dequeue(){
		transfer();
		return s2->pop();
	}

};


int main() {

	MyQueue *queue = new MyQueue(10);

	queue->enqueue(1);
	queue->enqueue(2);
	queue->enqueue(3);
	queue->enqueue(4);
	queue->enqueue(5);
	queue->enqueue(6);

	std::cout << "\ndequeue:  " << queue->dequeue();
	std::cout << "\ndequeue:  " << queue->dequeue();
	std::cout << "\ndequeue:  " << queue->dequeue();
	std::cout << "\ndequeue:  " << queue->dequeue();
	std::cout << "\ndequeue:  " << queue->dequeue();
	std::cout << "\ndequeue:  " << queue->dequeue();
	std::cout << "\ndequeue:  " << queue->dequeue();
	std::cout << "\ndequeue:  " << queue->dequeue();
}