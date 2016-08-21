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


Node * findBegLoop(Node **root){

	Node *start = *root;
	Node *slow = *root;
	Node *fast = *root;

	if(!slow || !fast) return NULL;

	while(slow->link && fast->link){

		slow = slow->link;
		fast = fast->link->link;
		if(slow == fast) break;
	}

	if(fast == NULL || fast->link == NULL) return NULL;

	slow = start;

	while(slow && fast){
	
		slow = slow->link;
		fast = fast->link;
		if(slow == fast) return slow;
	}
	return NULL;
}



int main() {

	Node *head = NULL;

	appendToEnd(&head, 1);
	appendToEnd(&head, 2);
	appendToEnd(&head, 3);
	appendToEnd(&head, 4);
	appendToEnd(&head, 5);
	appendToEnd(&head, 6);
	appendToEnd(&head, 7);
	appendToEnd(&head, 8);

	Node *temp = head;
	while(temp->link) {
		temp = temp->link;
	}
	temp->link = head->link->link->link;		//loop at 4

	Node *ret = findBegLoop(&head);
	std::cout << "Loop at: " << ret->data << std::endl;
}