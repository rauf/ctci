#include<iostream>

class Node{
	public:
	int data;
	Node *link;

	Node(int d){
		data = d;
		link = NULL; 
	}
};



void append(Node **root, int n) {

	while(*root)
		root = &(*root)->link;

	*root = new Node(n);
}



int siz(Node **root) {

	int s = 0;
	while(*root){
		s++;
		root = &(*root)->link;
	}

	return s;
}


void kthFromLast(Node **root, int k){

	int size = siz(root);
	int n = size - k;
	int i = 0;

	while(i < n) {
		root = &(*root)->link;
		i++;
	}
	std::cout << "\nNumber is " << (*root)->data;
}


int kthFromLastRec(Node **root, int k){

	int m = 0;
	if(*root != NULL)
		m = kthFromLastRec(&(*root)->link, k);

	if(m == k)	return (*root)->data;
	return ++m;
}

int kthFromLastItr(Node **root, int k){

	Node *slow = *root;
	Node *fast = *root;

	int i = 1;

	while(i < k){
		fast = fast->link;
		i++;
	}

	while(fast->link) {
		fast = fast->link;
		slow = slow->link;
	}
	return slow->data;
}

int main() {

	Node *head = NULL;

	int i = 0;
	for (int i = 1; i <= 10; ++i)	
		append(&head, i);
	
	kthFromLast(&head, 6);
	kthFromLastRec(&head, 6);
	std::cout << "\nNum:  "<< kthFromLastRec(&head, 6);
	std::cout << "\nNum:  "<< kthFromLastItr(&head, 6);

}