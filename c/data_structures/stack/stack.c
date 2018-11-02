#include <stdio.h>

typedef struct n {
	int data;
	struct n* next;
} node;



node* pop(node* stack, int* data);
node* push(node* stack, int data);
int length(node* stack);
void printStack(node* stack);

int main() {
	printf("Lets start\n");

	node* stack = NULL;

	stack = push(stack, 12);
	stack = push(stack, 1);
	stack = push(stack, 32);
	stack = push(stack, 41);
	stack = push(stack, 92);
	stack = push(stack, 501);
	
	printf("stack length: %d\n", length(stack));
	printStack(stack);

	int data = -1;

	stack = pop(stack, &data);
	printf("popped %d from stack\n", data);

	stack = pop(stack, &data);
	printf("popped %d from stack\n", data);

	stack = pop(stack, &data);
	printf("popped %d from stack\n", data);

	stack = pop(stack, &data);
	printf("popped %d from stack\n", data);

	stack = pop(stack, &data);
	printf("popped %d from stack\n", data);

	stack = pop(stack, &data);
	printf("popped %d from stack\n", data);

	printf("stack length: %d\n", length(stack));
	printStack(stack);


	stack = push(stack, 88);
	printf("stack length: %d\n", length(stack));
	printStack(stack);


	stack = pop(stack, &data);
	printf("popped %d from stack\n", data);

	printf("stack length: %d\n", length(stack));
	printStack(stack);


	printf("All Done!\n");
	return 0;
}

void printStack(node* stack) {
	node* iter = stack;

	while(iter != NULL) {
		printf("%d\n", iter->data);
		iter = iter->next;
	}
}

int length(node* stack) {
	if(stack == NULL) { return 0; }

	node* iter = stack;
	int cnt = 0;

	while(iter != NULL) { 
		iter = iter-> next;
		cnt++;
	}

	return cnt;
}

node* push(node* stack, int data) {
	node* head = (node*) malloc(sizeof(node));

	head->data = data;
	head->next = stack;

	stack = head;
	return stack;
}

node* pop(node* stack, int* data) {
	if(stack == NULL) { return -1; }

	node* temp = stack;
	(*data) = temp->data;
	stack = stack->next;

	free(temp);

	return stack;
}
