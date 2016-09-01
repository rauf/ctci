#include<iostream>


int magic(int arr[], int beg, int end) {

	int mid = (beg + end) / 2;

	if(beg > end) return -1;

	if(mid == arr[mid]) return mid;
	else if(mid > arr[mid]) return magic(arr, mid + 1, end);
	else if(mid < arr[mid]) return magic(arr, beg, mid - 1);
}

int magicNotDistinct(int arr[], int beg, int end){
	
	int mid = (beg + end) / 2;

	if(beg > end) return -1;
	if(mid == arr[mid]) return mid;

	int righIdx = mid + 1 > arr[mid] ? mid + 1 : arr[mid];
	
	int right = magicNotDistinct(arr, righIdx, end);
	if(right >= 0)	return right;

	int left = magicNotDistinct(arr, beg, mid - 1 > arr[mid] ? arr[mid] : mid - 1);
	return left;
}

int main() {

	int arr[] = {-10, 0, 2, 5, 6 ,8, 10, 14, 15, 29};
	int arr2[] = {-10, 0, 1, 2, 3, 4, 4, 5, 5, 6 ,8, 10, 14, 14, 14, 15, 29};	//14 and 15 at right index

	std::cout << "\nSolution is: " << magic(arr, 0, 9) << std::endl; 
	std::cout << "\nSolution is: " << magicNotDistinct(arr2, 0, 15) << std::endl; 

}