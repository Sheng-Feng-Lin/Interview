#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
	int cur_max;
}node;

void push(node **nd, int data);
void pop(node **nd);
int IsEmpty(node *nd);
int stacktop(node *nd);
void list(node *nd);


int main()
{
	node *top = NULL;

	push(&top, 5);
	push(&top, 4);
	push(&top, 2);
	push(&top, 10);
	push(&top, 100);
	list(top);
	printf("top is %d\n",stacktop(top));
	pop(&top);
	pop(&top);
	list(top);
	
	return 0;

}

void push(node **nd , int data)
{
	node *temp = (node *)malloc(sizeof(node));
	if(temp == NULL){
		printf("memory allocat fail");
		exit(1);
	}

	if((*nd) == NULL)
		temp -> cur_max = data;		
	else if(data > (*nd) -> cur_max)
		temp -> cur_max = data;
	else
		temp -> cur_max = (*nd) -> cur_max;
	
	temp -> data = data;
	temp -> next = *nd;
	*nd = temp;
	
}

void pop(node **nd)
{

	node *temp = *nd;
	if(IsEmpty(*nd)){
		printf("can't pop form stack\n");
		exit(1);
	}
	*nd = (*nd) -> next;
	free(temp);
}

int stacktop(node *nd)
{
	return nd -> data;

}

int IsEmpty(node *nd)
{
	if(nd == NULL)
		return 1;
	else
		return 0;
}

void list(node *nd)
{
	node *temp = nd;

	printf("Stack is :");
	while(temp != NULL){
		printf("%d -> ",temp -> data);
		temp = temp -> next;
	}
	printf("NULL \n");
	
	temp = nd;
	
	printf("Max Stack is : ");
	while(temp != NULL){
		printf("%d -> ", temp -> cur_max);
		temp = temp -> next;
	}
	printf("NULL \n");
}

