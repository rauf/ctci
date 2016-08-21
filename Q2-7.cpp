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

Node **reverseImpl(Node **root, Node **newList, Node **headNewList) {

	if(*root == NULL) return newList;
	newList = reverseImpl(&(*root)->link, newList, headNewList);

	*newList = new Node((*root)->data);
	
	if(*headNewList == NULL){
		*headNewList = *newList;
	}

	newList = &(*newList)->link;
	return newList;
}


//by recursion
Node *reverse(Node **root) {
	Node *newList = NULL;
	Node *head = NULL;

	reverseImpl(root, &newList, &head);
	return head;
}


//by manipulating pointers.. //more efficient
void reverse2(Node **root) {
	
	Node *temp = NULL;
	Node *next = (*root)->link;

	while((*root)->link) {

		(*root)->link = temp;
		temp = *root;
		*root = next;
		next = next->link;
	}
	(*root)->link = temp;
}


//checking by reversing the list
bool isPalindrome(Node **root) {

	Node *rev = reverse(root);

	while(*root){
		if((*root)->data != rev->data) return false;

		root = &(*root)->link;
		rev = rev->link;
	}
	return true;
}


bool isPalindrome2Impl(Node **root, Node **start){
	if(*root == NULL) return true;

	bool ret = isPalindrome2Impl(&(*root)->link, start);

	if((*root)->data != (*start)->data) ret = false;
	*start = (*start)->link;
	return ret;
}

//by comparing elements using recursion
bool isPalindrome2(Node **root){
	Node **start = root;
	return isPalindrome2Impl(root, start);
}


int main() {

	Node *head = NULL;
	
	appendToEnd(&head, 1);
	appendToEnd(&head, 2);
	appendToEnd(&head, 3);
	appendToEnd(&head, 4);
	appendToEnd(&head, 3);
	appendToEnd(&head, 2);
	appendToEnd(&head, 1);

	print(&head);

	std::cout << "\nisPalindrome  " << isPalindrome(&head) << std::endl;
	std::cout << "\nisPalindrome2  " << isPalindrome2(&head) << std::endl;

 
	Node *head1 = NULL;
	appendToEnd(&head1, 1);
	appendToEnd(&head1, 2);
	appendToEnd(&head1, 3);
	appendToEnd(&head1, 4);
	appendToEnd(&head1, 5);
	appendToEnd(&head1, 6);
	appendToEnd(&head1, 7);

	print(&head1);
	//Node *rev = 
	reverse2(&head1);
	print(&head1);


}