#include <stdio.h>


typedef struct n {
	int data;
	struct n* left;
	struct n* right;
} node;


node* init(int data);
node* insertNode(node* treeNode, int data);
node* insertNodeRos(node* treeNode, node* n);
node* removeNode(node* treeNode, int data);
void printPreOrder(node* treeNode);
void printPostOrder(node* treeNode);
void printInOrder(node* treeNode);


int main() {
	printf("Lets Start!\n");

	node* treeNode = NULL;

	treeNode = insertNode(treeNode, 88);
	treeNode = insertNode(treeNode, 42);
	treeNode = insertNode(treeNode, 120);
	treeNode = insertNode(treeNode, 160);
	treeNode = insertNode(treeNode, 100);
	treeNode = insertNode(treeNode, 22);
	treeNode = insertNode(treeNode, 12);
	treeNode = insertNode(treeNode, 17);
	treeNode = insertNode(treeNode, 33);
	treeNode = insertNode(treeNode, 20);
	treeNode = insertNode(treeNode, 25);


	printInOrder(treeNode);

	printf("Removing %d from tree\n", 20);
	treeNode = removeNode(treeNode, 20);
	printInOrder(treeNode);

	printf("Removing %d from tree\n", 33);
	treeNode = removeNode(treeNode, 33);
	printInOrder(treeNode);

	printf("Removing %d from tree\n", 22);
	treeNode = removeNode(treeNode, 22);
	printInOrder(treeNode);
	printPostOrder(treeNode);

	printf("All Done!");
	return 0;
}


node* insertNode(node* treeNode, int data) {
	if(treeNode == NULL) { return init(data); }

	if(data <= treeNode->data) { treeNode->left = insertNode(treeNode->left, data); }
	else { treeNode->right = insertNode(treeNode->right, data); }

	return treeNode;
}

node* insertNodeRos(node* treeNode, node* n) {
	if(treeNode == NULL) { return n; }

	if(n->data <= treeNode->data) { treeNode->left = insertNodeRos(treeNode->left, n); }
	else { treeNode->right = insertNodeRos(treeNode->right, n); }
	
	return treeNode;
}

node* removeNode(node* treeNode, int data) {
	if(treeNode == NULL) { return NULL; }
	
	if(treeNode->data == data) {
		if(treeNode->left == NULL && treeNode->right == NULL) {
			free(treeNode);
			return NULL;
		} else {
			if(treeNode->left == NULL) {
				node* n = treeNode->right;
				free(treeNode);
				return n;
			} else if(treeNode->right == NULL) {
				node* n = treeNode->left;
				free(treeNode);
				return n;
			} else {
				node* n = insertNodeRos(treeNode->left, treeNode->right);
				free(treeNode);
				return n;
			}
		}
	}
	else if(data < treeNode->data) { treeNode->left = removeNode(treeNode->left, data); }
	else { treeNode->right = removeNode(treeNode->right, data); }

	return treeNode;
}

node* init(int data) {
	node* n = (node*) malloc(sizeof(node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;

	return n;
}

void printPreOrder(node* treeNode) {
	if(treeNode == NULL) { return; }

	printPreOrder(treeNode->left);
	printPreOrder(treeNode->right);
	printf("%d\n", treeNode->data);
}

void printPostOrder(node* treeNode) {
	if(treeNode == NULL) { return; }

	printf("%d\n", treeNode->data);	
	printPostOrder(treeNode->left);
	printPostOrder(treeNode->right);
}

void printInOrder(node* treeNode) {
	if(treeNode == NULL) { return; }

	printInOrder(treeNode->left);
	printf("%d\n", treeNode->data);	
	printInOrder(treeNode->right);
}
