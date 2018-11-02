#include <stdio.h>


typedef struct n {
	int data;
	struct n* next;
} node;

typedef struct q {
	node* head;
	node* tail;
} queue;

queue* init();
queue* enqueue(queue* q, int data);
queue* dequeue(queue* q, int* data);
void printQueue(queue* q);



int main() {
	printf("Lets Start!\n");
	queue* q = init();

	q = enqueue(q, 11);
	q = enqueue(q, 22);
	q = enqueue(q, 33);
	q = enqueue(q, 44);
	q = enqueue(q, 55);
	q = enqueue(q, 66);
	q = enqueue(q, 77);
	printQueue(q);

	int data = -1;

	q = dequeue(q, &data);
	printf("dequeued %d from queue\n", data);

	q = dequeue(q, &data);
	printf("dequeued %d from queue\n", data);

	printQueue(q);

	printf("All Done!");
	return 0;
}

void printQueue(queue* q) {
	if(q == NULL) { return NULL; }
	if(q->head == NULL) { return NULL; }

	node* iter = q->head->next;
	while(iter != NULL) {
		printf("%d\n", iter->data);
		iter = iter->next;
	}
}


queue* init() {
	queue* q = (queue*) malloc(sizeof(queue));
	q->head = (node*) malloc(sizeof(node));
	q->tail = (node*) malloc(sizeof(node));
	q->head = q->tail;
	q->tail->next = NULL;
	
	return q;
}

queue* enqueue(queue* q, int data) {
	if(q == NULL) { q = init(); }

	q->tail->next = (node*) malloc(sizeof(node));
	q->tail->next->data = data;
	q->tail->next->next = NULL;

	q->tail = q->tail->next;

	return q;
}


queue* dequeue(queue* q, int* data) {
	if(q == NULL) { return NULL; }
	if(q->head == NULL) { return q; }
	if(q->head->next == NULL) { return q; }


	(*data) = q->head->next->data;
	node* temp = q->head->next;
	q->head->next = q->head->next->next;

	free(temp);

	return q;
}
