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


bool match(Node **root1, Node **root2) {
	if(*root1 == NULL && *root2 == NULL) return true;
	if(*root1 == NULL || *root2 == NULL) return false;
	if((*root1)->data != (*root2)->data) return false;

	return match(&(*root1)->llink, &(*root2)->llink) 
			&& match(&(*root1)->rlink, &(*root2)->rlink);
 }

bool isSubtree(Node **root1, Node **root2) {

	if(*root1 == NULL) return false;

	if(((*root1)->data) == (*root2)->data && match(root1, root2)) return true;

	return isSubtree(&(*root1)->llink, root2) 
			|| isSubtree(&(*root1)->rlink, root2);
}

int main() {

	Node *head = NULL;

	insert(&head, 5);
	insert(&head, 7);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	insert(&head, 1);
	insert(&head, 8);

	Node *head2 = NULL;
	insert(&head2, 3);
	insert(&head2, 4);

	std::cout << "Inorder1: " << std::endl;
	printInorder(&head);


	std::cout << "Inorder2: " << std::endl;
	printInorder(&head2);

	std::cout << "\nisSubtree : " << isSubtree(&head, &head2) << std::endl;

}