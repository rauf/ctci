#include<iostream>

class Node{
	public:
	char data;
	Node *link;

	Node(char d){
		data = d;
		link = NULL; 
	}
};



void append(Node **root, int n) {

	while(*root)
		root = &(*root)->link;

	*root = new Node(n);
}


void print(Node **root) {

	Node **dptr = root;

	std::cout << "Linked List: ";
	while(*dptr){
		std::cout << "  " << (*dptr)->data;
		dptr = &(*dptr)->link;
	}
	std::cout << std::endl;
}


void deleteMid(Node *root) {

	if(root == NULL || root->link == NULL) return;

	Node *prev = NULL;
	while(root->link){
		root->data = root->link->data;
		prev = root;
		root = root->link;
	}

	delete prev->link;
	prev->link = NULL;
}


void deleteMid2(Node *root) {

	if(root == NULL || root->link == NULL) return;

	Node *n = root->link;
	root->data = n->data;
	root->link = n->link;
	delete n;
}


int main() {

	Node *head = NULL;

	append(&head, 'a');
	append(&head, 'b');
	append(&head, 'c');
	append(&head, 'd');
	append(&head, 'e');

	print(&head);
	deleteMid2(head->link->link);

	print(&head);
}