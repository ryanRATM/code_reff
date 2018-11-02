#include <stdio.h>
#include <stdbool.h>
#include <math.h>


typedef struct l {
	int data;
	struct l* next;	
} node;

void printArray(int* arr, int len);
void printList(node* list);
int length(node* list);
node* insertAtHead(node* list, int data);
node* insertAtTail(node* list, int data);
void removeNode(node* list, int data);
int pop(node* list);
int removeNodeAt(node* list, int index);
bool contains(node* list, int data);
bool equals(node* orig, node* test);
node* append(node* orig, node* extra);
int frequency(node* list, int data);
node** split(node* list, int numBins);
node* reverse(node* list);
int* toArray(node* list, int* len);
node* filter(node* list, bool (*func)(int));
node* map(node* list, int (*func)(int));


//  helper functions for map and filter
int mapPow(int x) { return pow(x, 2); }
bool filterOdd(int x) { return x % 2 == 0; }


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


	node* otherList1 = NULL; // 200
	node* otherList2 = NULL; // 2, 200
	otherList1 = insertAtTail(otherList1, 200);
	otherList2 = insertAtTail(otherList2, 200);
	otherList2 = insertAtHead(otherList2, 2);


	printf("Does list and otherList1 match: %c\n", (equals(list, otherList1)) ? 'Y' : 'N');
	printf("Does list and otherList2 match: %c\n", (equals(list, otherList2)) ? 'Y' : 'N');
	printf("Does otherList1 and otherList2 match: %c\n", (equals(otherList1, otherList2)) ? 'Y' : 'N');


	append(otherList1, otherList2);
	printf("length: %d\n", length(otherList1));
	printList(otherList1); // 200, 2, 200



	int otherList1Length = 0;
	int* otherList1Data = toArray(otherList1, &otherList1Length);
	printArray(otherList1Data, otherList1Length);



	node* otherList2Rev = reverse(otherList2);
	printf("length: %d\n", length(otherList2Rev));
	printList(otherList2Rev); // 200, 2
	

	/* >ADD HERE< */
	list = insertAtTail(list, 0);
	list = insertAtTail(list, 1);
	list = insertAtTail(list, 2);
	list = insertAtTail(list, 3);
	list = insertAtTail(list, 4);
	list = insertAtTail(list, 5);
	list = insertAtTail(list, 6);
	list = insertAtTail(list, 7);
	list = insertAtTail(list, 8);
	list = insertAtTail(list, 9);
	list = insertAtTail(list, 10);	
	printf("length: %d\n", length(list));
	printList(list);



	node** bins = split(list, 3);
	int i = 0;
	for(i = 0; i < 3; i++) {
		printf("bins[%d]: \n", i);
		printList(bins[i]);
	}


	printf("list length: %d\n", length(list));
	printList(list);


	node* mapList = map(list, mapPow);
	node* filtList = filter(list, filterOdd);

	printf("list length: %d\n", length(list));
	printList(list);
	printf("mapList length: %d\n", length(mapList));
	printList(mapList);
	printf("filtList length: %d\n", length(filtList));
	printList(filtList);


	printf("All Done!\n");
	return 0;
}


void printArray(int* arr, int len) {
	printf("arr length: %d\n", len);
	int i;
	for(i = 0; i < len; i++) {
		printf("arr[%d]: %d\n", i, arr[i]);
	}
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
	
	list = head;

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

node* append(node* orig, node* extra) {
	if(orig == NULL) { return extra; }
	if(extra == NULL) { return orig; }

	node* iter = orig;
	while(iter->next != NULL) { iter = iter->next; }
	
	iter->next = extra->next;
	
	return orig;
}


int frequency(node* list, int data) {
	if(list == NULL) { return 0; }

	node* iter = list->next;
	int cnt = 0;

	while(iter != NULL) {
		cnt += ((iter->data == data)? 0 : 1);
		iter = iter->next;
	}

	return cnt;
}

node** split(node* list, int numBins) {
	int len = length(list);
	if(len == 0) { return NULL; }


	node** bins = (node**) malloc(sizeof(node*) * numBins);
	node* iter = list->next;
	int perBin = (int) ceil(len / (double)(numBins));
	int i, j;

//	perBin += ((len % numBins) ? 0 : 1);
	printf("len: %d; numBins: %d; perBin: %d\n", len, numBins, perBin);
	
	for(i = 0; i < numBins; i++) {
		bins[i] = (node*) malloc(sizeof(node));
		bins[i] = NULL;
		for(j = 0; j < perBin && iter != NULL; j++) {
			bins[i] = insertAtTail(bins[i], iter->data);
			iter = iter->next;
		}
	}

	return bins;
}

node* reverse(node* list) {
	if(list == NULL) { return NULL; }

	node* listRev = NULL;
	node* iter = list->next;

	while(iter != NULL) {
		listRev = insertAtHead(listRev, iter->data);
		iter = iter->next;
	}
	
	return listRev;
}

int* toArray(node* list, int* len) {
	(*len) = length(list);
	if(len == 0) { return NULL; }

	printf("[length: %d]\n", (*len));
	int* values = (int*) malloc(sizeof(int) * (*len));
	node* iter = list->next;
	int i = 0;

	while(iter != NULL) {
		values[i++] = iter->data;
		iter = iter->next;
	}

	return values;
}


node* map(node* list, int (*func)(int)) {
	if(list == NULL) { return NULL; }
	
	node* iter = list->next;
	node* mapList = (node*) malloc(sizeof(node));
	mapList->next = (node*) malloc(sizeof(node));

	node* mIter = mapList->next;


	while(iter->next != NULL) {
		mIter->data = func(iter->data);
		mIter->next = (node*) malloc(sizeof(node));
				
		iter = iter->next;
		mIter = mIter->next;
	}

	mIter->data = func(iter->data);
	mIter->next = NULL;

	return mapList;
}

node* filter(node* list, bool (*func)(int)) {
	if(list == NULL) { return NULL; }

	node* iter = list->next;
	node* filterList = (node*) malloc(sizeof(node));
	filterList->next = (node*) malloc(sizeof(node));

	node* fIter = filterList->next;

	if(iter->next == NULL) {
		if(func(iter->data)) {
			fIter->data = iter->data;
			fIter->next = NULL;
		}
		return filterList;
	}

	while(iter->next->next != NULL) {
		if(func(iter->data)) {
			fIter->data = iter->data;
			fIter-> next = (node*) malloc(sizeof(node));
			fIter = fIter->next;
		}
		iter = iter->next;
	}

	if(func(iter->next->data)) {
		fIter->data = iter->next->data;
	}
	fIter->next = NULL;
	
	return filterList;
}
