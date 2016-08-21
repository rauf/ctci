#include<iostream>
#include<stdio.h>

class Node {
public:
	int data;
	Node *link;

	Node(int d){
		data = d;
		link = NULL;
	}
};

void appendToEnd(Node **root, int n) {

	while(*root)
		root = &(*root)->link;

	*root = new Node(n);;
}


void print(Node **root) {

	std::cout << "Linked List: ";
	while(*root){
		std::cout << "  " << (*root)->data;
		root = &(*root)->link;
	}
	std::cout << std::endl;
}

bool isEmpty(Node **head) {
	if(*head) return true; else return false;
}


int size(Node **root){

	int s = 0;
	while(*root){
		root = &(*root)->link;
		s++;
	}
	return s;
}

/*
void seperate(Node **root, int n) {

	Node **head = root;
	
	while(*root) {
		
		if((*root)->data < n) {
			std::cout << "inside if";
			Node *toMove = (*root)->link;
			(*root)->link = (**root).link;
			
			toMove->link = *head;
			*head = toMove;
		}
		root = &(*root)->link;
	}
}*/

  

void seperate(Node **root, int n) {

	Node *temp = *root;

	while(temp->link){
		if(temp->link->data < n){

			Node *toMove = temp->link;
			temp->link = temp->link->link;

			toMove->link = *root;
			*root = toMove;
		}
		else temp = temp->link;
	}
}


int main() {

	Node *head = NULL;

	appendToEnd(&head, 4);
	appendToEnd(&head, 45);
	appendToEnd(&head, 1);
	appendToEnd(&head, 6);
	appendToEnd(&head, 3);
	appendToEnd(&head, 76);
	appendToEnd(&head, 6);
	appendToEnd(&head, 7);


	print(&head);
	seperate(&head, 7);
	print(&head);
}