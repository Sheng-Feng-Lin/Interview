#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}ND;

void creat_Node(ND **node);
void insert_Node(ND **node , int data);
void Delete_Node(ND **node , int data);
int IsEmpty(ND *node);
int List_Length(ND *node);
void list(ND *node);
void Bubble_Sort(ND **node);

ND *head = NULL;
ND *tail = NULL;

int main()
{
	ND *node;

	creat_Node(&node);
	insert_Node(&node , 10);
	insert_Node(&node, 20);	
	insert_Node(&node, 15);
	insert_Node(&node, 35);
	Bubble_Sort(&node); //louis
	list(node);
	printf("link list length = %d\n",List_Length(node) );
	Delete_Node(&node, 20);
	insert_Node(&node , 100);
	insert_Node(&node , 50);
	Delete_Node(&node,10);
	list(node);

	Delete_Node(&node, 50);	
	list(node);
	printf("link list length = %d\n",List_Length(node) );
	
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
	temp -> next = NULL;
	if(*node == NULL){
		*node = temp;
		tail = temp;
	}
	else{
		tail -> next = temp;
		tail = temp;		
		
	}

}

void Delete_Node(ND **node , int data)
{
	ND *temp, *temp1;
	temp = *node;
	while(temp != NULL){
		if (temp -> data == data){
			temp1 = temp;
			*node = temp->next;
			free(temp1);
			break;
		}
		else if(temp -> next -> data == data){
			temp1 = temp -> next;
			temp -> next = temp -> next -> next;
			free(temp1);
			break;
		}
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
	ND *temp;
	
	temp = node;

	while(temp != NULL){
		printf("%d -> ", temp -> data);
		temp = temp -> next;
	}
	printf("NULL \n");
}

void swap(ND *a, ND *b)
{
	int tmp = a -> data;
	a -> data = b -> data;
	b -> data = tmp;


}
void Bubble_Sort(ND **node)
{
	ND *tmp;
	ND *curr = *node;
	ND *prev = *node;
	ND *tail = NULL;

	while(*node != tail){
		curr = *node;
		prev = *node;
		while(curr && curr -> next && curr -> next != tail){
			if(curr -> data > curr -> next -> data){
				tmp = curr -> next;
				curr -> next = tmp -> next;
				tmp -> next = curr;
				if(curr == *node){
					*node = tmp;
					prev = tmp;
				}
				else{
					prev -> next = tmp;
					prev = prev -> next;
				}
			}
			else{
				if(curr != *node)
					prev = prev -> next;
				curr = curr -> next;
			}
		}
		tail = curr;
	}
}
