#include<iostream>
#include<stdlib.h>
#include<stdio.h>

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

bool isBST(Node **root) {

	if(*root == NULL) return true;

	if((*root)->llink != NULL && (*root)->llink->data > (*root)->data) return false;
	if((*root)->rlink != NULL && (*root)->rlink->data < (*root)->data) return false;
	return isBST(&(*root)->llink) && isBST(&(*root)->rlink);
}


bool isBST(Node *root) {

	if(root == NULL) return true;

	if(root->llink != NULL && (root->llink)->data > root->data) return false;
	if(root->rlink != NULL && (root->rlink)->data < root->data)	return false;
	return isBST(root->llink) && isBST(root->rlink);
}


int main() {


	Node *head = NULL;

	insert(&head, 5);
	insert(&head, 7);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);

	head->llink->data = 11;

	std::cout << "Inorder: " << std::endl;
	printInorder(&head);
	
	std::cout << std::endl;
	
	std::cout << "\nisBST : "<< isBST(&head) << std::endl;

}