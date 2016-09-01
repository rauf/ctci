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

//returns -1 if not balanced, positive integer otherwise
int balanced(Node **root) {

	if(*root == NULL) return 0;

	int left =   balanced(&(*root)->llink);
	if(left == -1) return -1;

	int right =  balanced(&(*root)->rlink);
	if(right == -1) return -1;

	
	if(abs(left - right) > 1) return -1;

	if(left > right) return left + 1;
	else return right + 1;
}

bool isBalanced(Node **root) {

	if(balanced(root) == -1)
		return false;
	else return true;
}

int main() {

	Node *head = NULL;

	insert(&head, 5);
	insert(&head, 7);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	//insert(&head, 8);

	std::cout << "Inorder: " << std::endl;
	printInorder(&head);


	std::cout << "\nBalanced: " << isBalanced(&head) << std::endl;

}