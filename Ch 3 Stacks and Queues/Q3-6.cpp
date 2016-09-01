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
	
	int peek() {
		return arr[top];
	}

	bool isEmpty() {
		return top == -1;
	}

	int getSize() {
		return size;
	}
};


void sort(Stack *s1){

	Stack *s2 = new Stack(s1->getSize());

	while(!s1->isEmpty()) {
		int num = s1->pop();

		if(s2->isEmpty() || num <= s2->peek()){
			s2->push(num);
		}

		else if(num > s2->peek()){
			while(!s2->isEmpty())
				s1->push(s2->pop());

			s2->push(num);
		}
	}

	while(!s2->isEmpty()){
		s1->push(s2->pop());
	}
	delete s2;
}

int main() {

	Stack *s = new Stack(10);

	s->push(6);
	s->push(5);
	s->push(3);
	s->push(8);
	s->push(7);
	s->push(1);

	s->print();

	sort(s);

	s->print();

}