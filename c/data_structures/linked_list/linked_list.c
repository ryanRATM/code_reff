#include <stdio.h>

typedef struct l {
	int data;
	struct l* next;	
} node;

void printList(node* list);
int length(node* list);
node* insertAtHead(node* list, int data);
node* insertAtTail(node* list, int data);

// to be implemented
node* indexOf(node* list, int data);
node* pop(node* list);
node* removeAt(node* list, int data);
node* contains(node* list, int data);
node* equals(node* orig, node* test);
node* merge(node* orig, node* extra);


int main() {
	printf("Hellow World!\n");
	node* list = NULL;

	printf("length: %d\n", length(list));

	list = insertAtHead(list, 10);
	list = insertAtHead(list, 9);

	printf("length: %d\n", length(list));
	printList(list);

	list = insertAtTail(list, 15);
	list = insertAtTail(list, 1);

	printf("length: %d\n", length(list));
	printList(list);

	list = insertAtHead(list, 3);

	printf("length: %d\n", length(list));
	printList(list);
	
	printf("All Done!\n");
	return 0;
}


void printList(node* list) {
	node* iter = list;
	int cnt = 0;
	while(iter != NULL) {
		printf("%d @ %d\n", cnt++, iter->data);
		iter = iter->next;
	}
}

int length(node* list) {
	int cnt = 0;
	node* iter = list;

	while(iter != NULL) {
		iter = iter->next;
		cnt++;
	}
	
	return cnt;
} 

node* insertAtHead(node* list, int data) {
	node* head = (node*) malloc(sizeof(node));

	head->next = list;
	head->data = data;

	return head;	
}

node* insertAtTail(node* list, int data) {
	if(list == NULL) {
		return insertAtHead(list, data);
	}

	node* iter = list;
	while(iter->next != NULL) { iter = iter->next; }
	
	iter->next = (node*) malloc(sizeof(node));
	iter->next->next = NULL;
	iter->next->data = data;

	return list;
}

/*
int remove(node* list) {

}
*/
