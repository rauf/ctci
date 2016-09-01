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

Node* sumRev(Node ** list1, Node **list2){

	int carry = 0;
	int firstEnd = 0;
	int secondEnd = 0;
	Node *temp1 = *list1;
	Node *temp2 = *list2;
	Node *temp3 = NULL;
	Node *head = temp3;

	while(temp1 && temp2){

		int sum = temp1->data + temp2->data + carry;
		int x = sum % 10;

		if(temp3 == NULL) {
			head = new Node(x);
			temp3 = head;
		}
		else {
			temp3->link = new Node(x);
			temp3 = temp3->link;
		}

		carry = sum / 10;
		temp1 = temp1->link;
		temp2 = temp2->link;

		if(!temp1) firstEnd = 1;
		if(!temp2) secondEnd = 1;
	}

	if(secondEnd){
		while(temp1){
			int sum = temp1->data + carry;
			int x = sum % 10;
			temp3->link = new Node(x);
			carry = sum/10;
			temp1 = temp1->link;
			temp3 = temp3->link;
		}
	}

	if(firstEnd){
		while(temp2){
			int sum = temp2->data + carry;
			int x = sum % 10;
			temp3->link = new Node(x);
			carry = sum/10;
			temp2 = temp2->link;
			temp3 = temp3->link;
		}
	}

	if(carry != 0){
		temp3->link = new Node(carry);
	}

	return head;
}

void prependZeroes(Node **root, int n){

	for (int i = 0; i < n; ++i) {
		Node *newNode = new Node(0);
		newNode->link = *root;
		*root = newNode;
	}

}


Node* sumFwd(Node ** list1, Node **list2){

	int carry = 0;
	Node *temp1 = *list1;
	Node *temp2 = *list2;
	Node *temp3 = NULL;
	Node *head = temp3;
	int s1 = size(list1);
	int s2 = size(list2);
	int s = s1 > s2 ? s1 : s2;

	//prepend zeroes if list are of different length
	if(s1 < s2)prependZeroes(&temp1, s2 - s1);
	else if(s1 > s2) prependZeroes(&temp2, s1 - s2);

	int arr[s];
	int i = 0;

	while(temp1 && temp2){
		int sum = temp1->data + temp2->data;
		arr[i++] = sum;
		temp1 = temp1->link;
		temp2 = temp2->link;
	}

	--i;
	while(i >= 0){
		int sum = arr[i] + carry;
		int x = sum % 10;
		carry = sum / 10;

		arr[i] = x;
		--i;
	}

	if(carry != 0){
		head = new Node(carry);
		temp3 = head;
	}

	for (int i = 0; i < s; ++i){
		if(head == NULL){
			head = new Node(arr[i]);
			temp3 = head;
		} else {
			temp3->link = new Node(arr[i]);
			temp3 = temp3->link;
		}
	}
	return head;

}

int main() {

	Node *head1 = NULL;
	Node *head2 = NULL;

	appendToEnd(&head1, 1);
	appendToEnd(&head1, 2);
	appendToEnd(&head1, 3);
	appendToEnd(&head1, 4);
	
	print(&head1);

	appendToEnd(&head2, 5);
	appendToEnd(&head2, 6);
	appendToEnd(&head2, 7);
	print(&head2);

	Node *slistRev = sumRev(&head1, &head2);
	print(&slistRev);

	Node *slistFwd = sumFwd(&head1, &head2);
	print(&slistFwd);
}