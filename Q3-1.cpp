#include<iostream>


class Stacks{		//stack num starts from 0
 
	int *arr;
	int size;
	int top[3];
	int sizeEach;
	int stackNum;

	int end(int stackNum){
		return (stackNum + 1 ) * sizeEach;
	}

	int start(int stackNum) {
		return stackNum * sizeEach;
	}

public:
	Stacks(int stackNum, int size) {
		this->size = size;
		this->stackNum = stackNum;
		arr = new int [size];

		sizeEach = size / stackNum;
		top[0] = -1;
		top[1] = sizeEach - 1;
		top[2] = 2 *sizeEach - 1;
	}

	void push(int stackNum, int n) {

		if(top[stackNum] > end(stackNum))
			return;
						
		top[stackNum]++;	
		arr[top[stackNum]] = n;
	}

	int pop(int stackNum){
		
		if(top[stackNum] < start(stackNum)) 
			return -1;
		
		int ret = arr[top[stackNum]];
		arr[top[stackNum]] = 0;
		top[stackNum]--;
		return ret;
	}


	void print(){
		std::cout << std::endl;
		for (int i = 0; i < size; ++i)
			std::cout << arr[i] << " ";
	}

};


int main() {

	Stacks *stacks = new Stacks(3, 10);

	stacks->push(0, 1);
	stacks->push(0, 2);
	stacks->push(1, 3);
	stacks->push(1, 4);
	stacks->push(2, 5);
	stacks->push(2, 6);

	stacks->print();

	std::cout << "\nstack->pop(1)" <<  stacks->pop(0);
	std::cout << "\nstack->pop(2)" <<  stacks->pop(1);
	std::cout << "\nstack->pop(3)" <<  stacks->pop(2);

	stacks->print();
}