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

	int getSize(){
		return size;
	}

	int removeFirst(){
		int first = arr[0];

		for (int i = 0; i < size - 1 ; ++i) {
			arr[i] = arr[i + 1];
		}
		top--;
		return first;
	}
	
};

class SetOfStacks{

	Stack **stack;
	int size;
	int maxStacks;
	int currentStack;

public:

	SetOfStacks(int _maxStacks, int _size){	//size of one stack
		size = _size;
		maxStacks = _maxStacks;
		stack = new Stack*[maxStacks];
		currentStack = 0;
		stack[currentStack] = new Stack(size);
	}

	void push(int n) {
		
		if(stack[currentStack]->getTop() >= size - 1){
			currentStack++;
			stack[currentStack] = new Stack(size);
		}
		stack[currentStack]->push(n);
	}

	int pop() {

		int ret = stack[currentStack]->pop();

		if(stack[currentStack]->getTop() <= -1) { // stack empty
			delete stack[currentStack];
			stack[currentStack] = NULL;
			currentStack--;
		}
		return ret;
	}

	int popAt(int index){
	
		if(index == currentStack)
			return pop();
	
		int ret = stack[index]->pop();

		for (int i = index; i < maxStacks; ++i) {
			
			if(stack[i + 1] != NULL) {
				stack[i]->push(stack[i + 1]->removeFirst());
			}
			else break;
		}
		
		return ret;
	}

	void print(){
		for (int i = 0; i <= maxStacks; ++i) {
				if(stack[i] != NULL){
				std::cout << "\nStack num: " << i;
				stack[i]->print();
			}
		}
	}

};



int main() {

	SetOfStacks *s = new SetOfStacks(10, 3);

	s->push(5);
	s->push(12);
	s->push(4);
	s->push(6);
	s->push(2);
	s->push(65);
	s->push(22);
	s->push(46);
	s->push(566);
	s->push(65);
	s->push(253);

	s->print();

	std::cout << "\npop: " << s->pop();
	std::cout << "\npop: " << s->pop();
	
	s->print();

	std::cout << "\npop 0: " << s->popAt(0);

	s->print();
	std::cout << "\npop 1: " << s->popAt(1);
	s->print();

	std::cout << "\npop 2: " << s->popAt(2);
	s->print();
}