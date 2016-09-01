#include<iostream>
#include<cstring>
#include<stdio.h>

#define BIG_NUM 1000000


class Node {

public:
	int data;
	Node *link;

	Node(int _data){
		data = _data;
		link = NULL;
	}
};

class Stack{

	int *arr;
	int top;
	int size;
	Node *minList;

	void addMin(int n) {
		if(minList == NULL){
			minList = new Node(n);
			return;
		}		
		Node *newNode = new Node(n);
		newNode->link = minList;
		minList = newNode;
	}

	void removeMin() {
		Node *toDelete = minList;
		minList = minList->link;
		delete toDelete;
	}

public:
	Stack(int _size) {
		size = _size;
		arr = new int[size];
		top = -1;
	}

	void push(int n) {
		if(top > size) return;

		if(minList == NULL || n < min()){
			addMin(n);
		} 
		arr[++top] = n;
	}

	int pop() {
		if(top <= -1) return -1;

		int n = arr[top];
		top--;

		if(min() == n) {
			removeMin();
		}
		return n;
	}

	int min(){
		return minList == NULL ? BIG_NUM :  minList->data;
	}

	void print() {
		std::cout << "\nArray: ";
		for (int i = 0; i <= top; ++i)
				std::cout << arr[i] << "  ";
		std::cout << std::endl;
	}

	
};


int main() {

	Stack *s = new Stack(10);

	s->push(5);
	s->push(12);
	s->push(4);
	s->push(6);
	s->push(2);
	s->push(65);

	s->print();

	std::cout << "Min : " << s->min();

	s->pop();
	s->pop();		//removing 2
	s->print();
	std::cout << "\nMin : " << s->min() << std::endl;

	s->pop();
	s->pop();
	s->pop();
	s->pop();		//removing all
	s->print();
	std::cout << "\nMin : " << s->min() << std::endl;
}