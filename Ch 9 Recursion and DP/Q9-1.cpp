#include<iostream>

int stairs(int *arr, int i){

	if(i == 1) return 1;
	else if (i == 2) return 2;
	else if (i == 3) return 4;

	if(arr[i] != 0) return arr[i];
	arr[i] = stairs(arr, i - 1) + stairs(arr, i - 2) + stairs(arr, i - 3);
	return arr[i];
}


int main() {

	int max = 100;
	int *arr = new int[max];

	int n = 10;

	std::cout << "\nSolution for  " << n << " = "<< stairs(arr, n) << std::endl;
}