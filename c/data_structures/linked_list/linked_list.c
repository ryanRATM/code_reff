#include <stdio.h>
#include <stdbool.h>

typedef struct l {
	int data;
	struct l* next;	
} node;

void printList(node* list);
int length(node* list);
node* insertAtHead(node* list, int data);
node* insertAtTail(node* list, int data);
void removeNode(node* list, int data);

// to be implemented
int pop(node* list);
int removeNodeAt(node* list, int index);
bool contains(node* list, int data);
bool equals(node* orig, node* test);
node* merge(node* orig, node* extra);


int main() {
/*
	printf("true  ^ true:  %c\n", (true ^ true)   ? 'T' : 'F');
	printf("true  ^ false: %c\n", (true ^ false)  ? 'T' : 'F');
	printf("false ^ true:  %c\n", (false ^ true)  ? 'T' : 'F');
	printf("false ^ false: %c\n", (false ^ false) ? 'T' : 'F');
*/

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
	printList(list); //3, 9, 10, 15, 1


	removeNode(list, 15);
	printf("length: %d\n", length(list));
	printList(list);

	removeNode(list, 1);
	printf("length: %d\n", length(list));
	printList(list);


	removeNode(list, 3);
	printf("length: %d\n", length(list));
	printList(list);

	removeNode(list, 10);
	printf("length: %d\n", length(list));
	printList(list);

	removeNode(list, 9);
	printf("length: %d\n", length(list));
	printList(list);

	list = insertAtTail(list, 19);
	list = insertAtHead(list, 17);
	list = insertAtHead(list, 200);
	printf("length: %d\n", length(list));
	printList(list); // 200, 17, 19

	printf("Remove at index: %d => %d\n", 2, removeNodeAt(list, 2));
	printf("length: %d\n", length(list));
	printList(list);

	printf("Remove at index: %d => %d\n", 1, removeNodeAt(list, 1));
	printf("length: %d\n", length(list));
	printList(list); // 200


	printf("Does list contain %d: %c\n", 200, contains(list, 200) ? 'Y' : 'N');
	printf("Does list contain %d: %c\n", 1, contains(list, 1) ? 'Y' : 'N');


	node* otherList1 = NULL;
	node* otherList2 = NULL;
	otherList1 = insertAtTail(otherList1, 200);
	otherList2 = insertAtTail(otherList2, 200);
	otherList2 = insertAtHead(otherList2, 2);

	printf("Does list and otherList1 match: %c\n", (equals(list, otherList1)) ? 'Y' : 'N');
	printf("Does list and otherList2 match: %c\n", (equals(list, otherList2)) ? 'Y' : 'N');
	printf("Does otherList1 and otherList2 match: %c\n", (equals(otherList1, otherList2)) ? 'Y' : 'N');

	printf("All Done!\n");
	return 0;
}


void printList(node* list) {
	if(list == NULL) { return 0; }

	node* iter = list->next;
	int cnt = 0;
	while(iter != NULL) {
		printf("%d @ %d\n", cnt++, iter->data);
		iter = iter->next;
	}
}

int length(node* list) {
	if(list == NULL) { return 0; }

	int cnt = 0;
	node* iter = list->next;

	while(iter != NULL) {
		iter = iter->next;
		cnt++;
	}
	
	return cnt;
} 

node* insertAtHead(node* list, int data) {
	node* head = (node*) malloc(sizeof(node));

	head->next = (node*) malloc(sizeof(node));
	head->next->data = data;
	head->next->next = (list == NULL) ? list : list->next;
	
	//list = head;

	return head;
}

node* insertAtTail(node* list, int data) {
	if(list == NULL) {
		return insertAtHead(list, data);
	}

	node* iter = list; //->next;
	while(iter->next != NULL) { iter = iter->next; }
	
	iter->next = (node*) malloc(sizeof(node));
	iter->next->next = NULL;
	iter->next->data = data;

	return list;
}


void removeNode(node* list, int data) {
	if(list == NULL) { return; }

	node* iter = list;
	// case first

	while(iter->next != NULL) {
		if(iter->next->data == data) {
			node* match = iter->next;
			iter->next = match->next;
			free(match);
		} else { iter = iter->next; }
	}	
}

int pop(node* list) {
	return -1;
}

int removeNodeAt(node* list, int index) {
	if(list == NULL) { return -1; }	
	if(index < 0) { return -1; }

	node* iter = list;
	index++;

	while(iter != NULL && index-- != 1) { iter = iter->next; }
	
	if(index == 0) {
		node* temp = iter->next;
		int data = temp->data;
		iter->next = temp->next;

		free(temp);

		return data;
	} else { return -1; }
}


bool contains(node* list, int data) {
	if(list == NULL) { return false; }

	node* iter = list->next;
	bool isFound = false;

	while(iter != NULL) { 
		if(iter->data == data) {
			isFound = true;
			break;
		}
		iter = iter->next; 
	}

	return isFound;
}

bool equals(node* orig, node* test) {
	if((orig == NULL) && (test == NULL)) return true;
	if((orig == NULL) || (test == NULL)) return false;

	node* origIter = orig->next;
	node* testIter = test->next;

	while(origIter != NULL && testIter != NULL) {
		if(origIter->data != testIter->data) { return false; }
		origIter = origIter->next;
		testIter = testIter->next;
	}

	return (origIter == NULL) && (testIter == NULL);
}

node* merge(node* orig, node* extra) {
	return NULL;
}
