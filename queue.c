#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;

void enqueue(node **head, node **tail,  int data);
void dequeue(node **tail);
void list(node *nd);


int main()
{
	node *head = NULL;
	node *tail = NULL;	
	enqueue(&head, &tail, 1);
	enqueue(&head, &tail, 2);
	enqueue(&head, &tail, 3);
	enqueue(&head, &tail, 4);
	list(head);
	dequeue(&head);
	dequeue(&head);
	dequeue(&head);
	list(head);




	return 0;
}

void enqueue(node **head,node **tail, int data)
{
	node *temp = (node *)malloc(sizeof(node));
	if(temp == NULL){
		printf("memory allocat fail");
		exit(1);
	}
	temp -> data = data;
	temp -> next = NULL;
	if (*head == NULL ){
		*head = temp;
	}
	else{
		(*tail) -> next = temp;
	}
	*tail = temp;
}

void dequeue(node **head)
{
	node *temp = *head;
	*head = (*head) -> next;	
	free(temp);

}

void list(node *nd)
{
	node *temp = nd;
	while(temp != NULL){
		printf("%d -> ", temp -> data);
		temp = temp -> next;
	}
	printf("NULL \n");
}

