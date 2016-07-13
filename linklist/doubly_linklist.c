#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
}ND;

void creat_Node(ND **node);
void insert_Node(ND **node , int data);
void Delete_Node(ND **node , int data);
int IsEmpty(ND *node);
int List_Length(ND *node);
void list(ND *node);

ND *head = NULL;
ND *tail = NULL;

int main()
{
	ND *node;

	creat_Node(&node);
	insert_Node(&node , 10);
	insert_Node(&node, 20);	
	insert_Node(&node, 5);
	list(node);
	Delete_Node(&node, 20);
	list(node);
	Delete_Node(&node, 5555);
	list(node);
	
	
	return 0;
}

void creat_Node(ND **node)
{
	*node = NULL;
}

void insert_Node(ND **node, int data)
{
	ND *temp =(ND *)malloc(sizeof(ND));
	if(temp == NULL){
		printf("can't allocat memory\n");
		exit(1);
	}
	temp -> data = data;
	temp -> prev = NULL;
	temp -> next = NULL;
	if(*node == NULL){
		*node = temp;
		tail = temp;
	}
	else{
		temp -> prev = tail;
		tail -> next = temp;
		tail = temp;		
		
	}

}

void Delete_Node(ND **node , int data)
{
	ND *temp;
	temp = *node;
	while(temp != NULL){
		if (temp -> data == data){
			if (temp -> prev == NULL){ //remove first node
				temp -> next -> prev = temp -> prev;
				*node = temp -> next;
			}
			else if (temp -> next == NULL){ // remove last node
				temp -> prev -> next = temp -> next;
				tail = temp -> prev;
			}
			else{
				temp -> prev -> next = temp -> next;
				temp -> next -> prev = temp -> prev;
			}
			free(temp);
			printf("delete success.\n");
			break;
		}
		else if (temp -> next == NULL)
			printf("delete faild. \n");
			
		temp = temp -> next;
	}
}
int IsEmpty(ND *node)
{
	if(node == NULL)
		return 1;
	else
		return 0;
}

int List_Length(ND *node)
{
	ND *temp = node;
	int count = 0;
	while(temp != NULL){
		count++;
		temp = temp -> next; 
	}
	return count;
}

void list(ND *node)
{
	ND *temp, *temp1;
	
	temp = node;
	temp1 = tail;
	while(temp != NULL){
		printf("%d -> ", temp -> data);
		temp = temp -> next;
	}
	printf("NULL \n");
	
	while(temp1 != NULL){
		printf("%d -> ", temp1 -> data);
		temp1 = temp1 -> prev;
	}
	printf("NULL \n");
}
