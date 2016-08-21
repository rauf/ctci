#include<iostream>
#include<stdio.h>

class node {
public:
	char data;
	node *link;

	node(char d){
		data = d;
		link = NULL;
	}
};

/*
void appendToEnd(node **root, int n) {

	node* temp;

	if(*root == NULL){
		temp = new node(n);
		*root = temp;
	}
	else {

		temp = *root;
		while (temp->link != NULL)
			temp = temp->link;

		node *neww = new node(n);
		temp->link = neww;
	}
}
*/

void del(node **root, int n) {
	node **dptr = root;

	while(*dptr && (*dptr)->data != n) {
		dptr = &(*dptr)->link;
	}
	
	if(*dptr == NULL) return;

	node *toDelete = *dptr;
	*dptr = (**dptr).link;
	delete toDelete;
}

void appendToEnd(node **root, int n) {

	node **dptr = root;
	while(*dptr){
		dptr = &(*dptr)->link;
	}

	*dptr = new node(n);;
}


void print(node **root) {

	node **dptr = root;

	std::cout << "Linked List: ";
	while(*dptr){
		std::cout << "  " << (*dptr)->data;
		dptr = &(*dptr)->link;
	}
	std::cout << std::endl;
}

bool isEmpty(node **head) {
	if(*head) return true; else return false;
}


int size(node **root){

	int s = 0;
	while(*root){
		root = &(*root)->link;
		s++;
	}

	return s;
}
/*
void removeDup(node **root) {

	int arr[256];

	for (int i = 0; i < 256; ++i)
		arr[i] = 0;

	while(*root) {
		char ch = (*root)->data;
		std::cout << "\nch = " << ch;
		if(arr[ch]){

			node *toDelete = *root;
			*root = (*root)->link;
			delete toDelete;
		}

		arr[ch] = 1;

		root = &(*root)->link;
	}

}
*/


void removeDup(node **root) {

	node *temp = *root;
	int arr[256];
	
	for (int i = 0; i < 256; ++i)
		arr[i]= 0;

	if(temp == NULL) return;
	arr[temp->data] = 1;

	while(temp->link != NULL) {

		char ch = temp->link->data;
		
		if(arr[ch]){
			node *toDelete = temp->link;
			temp->link = temp->link->link;
			delete toDelete;
		}
		else temp = temp->link;
		arr[ch] = 1;
	}
}



void removeDup2(node **root) {

	node *slow = *root;

	if(slow == NULL) return;

	while(slow->link) {
		node *fast = slow;

		while(fast->link) {

			if(fast->link->data == slow->data){
				node *toDelete = fast->link;
				fast->link = fast->link->link;
				delete toDelete;
			}
			else fast = fast->link;
		}
		slow = slow->link;
	}
}


/*
void removeDup2(node **root) {

	if(root == NULL) return;
	
	while(*root) {

		printf("%c     ", (*root)->data);

		node **slow = root;

		while(*slow) {
			printf("\\%c  ", (*slow)->data);

			if((*slow)->data == (*root)->data){
				*slow = (*slow)->link;
			}

			slow = &(*slow)->link;
		}
		root = &(*root)->link;
	}
}

*/


int main() {

	node *head = NULL;

	appendToEnd(&head, 'F');
	appendToEnd(&head, 'F');
	appendToEnd(&head, 'O');
	appendToEnd(&head, 'L');
	appendToEnd(&head, 'L');
	appendToEnd(&head, 'O');
	appendToEnd(&head, 'W');
	appendToEnd(&head, 'U');
	appendToEnd(&head, 'P');
	appendToEnd(&head, 'F');
	appendToEnd(&head, 'G');
	appendToEnd(&head, 'X');

	appendToEnd(&head, 'F');
	appendToEnd(&head, 'P');
	appendToEnd(&head, 'P');



	print(&head);
	removeDup2(&head);
	print(&head);
}