#include<iostream>
#include<stdlib.h>

class Node {
public:
	int data;
	Node *llink;
	Node *rlink;

	Node(int d) {
		data = d;
		llink = NULL;
		rlink = NULL;
	}
};


void insert(Node **root, int data) {

	if(*root == NULL) {
		*root = new Node(data);
		return;
	}

	if(data < (*root)->data) {
		insert(&(*root)->llink, data);
	}
	else {
		insert(&(*root)->rlink, data);
	}
}

void printInorder(Node **root) {

	if(*root) {
		printInorder(&(*root)->llink);
		std::cout << "  " << (*root)->data;
		printInorder(&(*root)->rlink);
	}
}

void create(int *arr, Node **root, int beg, int end) {

	if(beg > end) return;

	int mid = (beg + end) / 2;

	*root = new Node(arr[mid]);
	create(arr, &(*root)->llink, beg, mid - 1);
	create(arr, &(*root)->rlink, mid + 1, end);
}


int getHeight(Node **root) {

	if(*root == NULL) return 0;

	int left = getHeight(&(*root)->llink);
	int right = getHeight(&(*root)->rlink);

	return left > right ? left + 1: right + 1;
}

int main() {


	Node *head = NULL;
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

	create(arr, &head, 0, 14);

	std::cout << "Inorder: " << std::endl;
	printInorder(&head);
	
	std::cout << std::endl;
	
	std::cout << "\nHeight of tree is: "<< getHeight(&head) << std::endl;

}