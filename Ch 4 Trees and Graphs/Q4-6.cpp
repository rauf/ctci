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

int successor(Node **root, int n) {

	Node *head = *root;
	Node *temp = *root;
	Node *parent = NULL;
	Node *left = NULL;
	int from = 0;	//1 for left subtree, 2 for right subtree

	if(temp == NULL) return -1;

	while(temp->data != n) {
		if(n < temp->data) {
			from = 1;
			parent = temp;
			left = temp;
			temp = temp->llink;
		} 
		else{
			from = 2;
			parent = temp;
			temp = temp->rlink;
		}
	}

	if(from == 1) {
		if(temp->rlink == NULL) return parent->data;
		else return temp->rlink->data;
	}
	else if(from == 2) {

		if(temp->rlink == NULL) {
			if(left != NULL) return left->data;
			else return -1;
		}
		else {
			return temp->rlink->data;
		} 
	}
	else return -1;
}

int main() {


	Node *head = NULL;

	insert(&head, 5);
	insert(&head, 7);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);

	std::cout << "Inorder: " << std::endl;
	printInorder(&head);
	
	std::cout << std::endl;
	
	std::cout << "\nsuccuessor : "<< successor(&head, 4) << std::endl;

}