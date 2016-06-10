#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	int value;
	struct _Node *left;
	struct _Node *right;

}Node;

void Insert_Node(int value);
void print_Inorder(Node *temp);
void print_Preorder(Node *temp);
void print_Postorder(Node *temp);
void d_tree(Node *temp);


Node *root = 0;

int main()
{
	Insert_Node(3); 
	Insert_Node(5); 
	Insert_Node(1); 
	Insert_Node(2); 
	Insert_Node(4); 
	
	printf("Inorder:"); 
	print_Inorder(root); 	
	printf("\n");

	printf("Preorder:");
	print_Preorder(root);
	printf("\n");


	printf("Postorder:");
	print_Postorder(root);
	printf("\n");

	
}

void Insert_Node(int value)
{
	Node *temp, *pre_temp;
	if(root == 0)
	{
		root =(Node*)malloc(sizeof(Node));
		root -> value = value;
		root -> left = 0;
		root -> right = 0;
	}
	else{
		temp = root;
		while(temp)
		{
			pre_temp = temp;
			if(value > temp -> value) // 			
				temp = temp -> right;
			else if (value < temp -> value)
				temp = temp -> left;
			else{
				printf("key already in BST\n");
				return;
			}
		}			
	

	if(value > pre_temp->value){
		pre_temp -> right = (Node *)malloc(sizeof(Node));
		pre_temp -> right -> value = value;
		pre_temp -> right -> left =0;
		pre_temp -> right -> right =0;
	}
	else if(value < pre_temp->value){
		pre_temp -> left = (Node *)malloc(sizeof(Node));
		pre_temp -> left -> value = value;
		pre_temp -> left -> left =0;
		pre_temp -> left -> right =0;			  
	}
	else
		printf("key already in BST\n");

	}
}

void print_Inorder(Node *temp)
{
	if(temp == 0)
		return;
	print_Inorder(temp -> left);
	printf("%d ", temp -> value);
	print_Inorder(temp -> right);
}

void print_Preorder(Node *temp)
{
	if(temp == 0)
		return;
	printf("%d ", temp -> value);
	print_Preorder(temp -> left);
	print_Preorder(temp -> right);
}
void print_Postorder(Node *temp)
{
	if(temp == 0)
		return;
	print_Postorder(temp -> left);
	print_Postorder(temp -> right);
	printf("%d ", temp -> value);
}

void d_tree(Node *temp)
{
	if(temp == 0)
		return;
	d_tree(temp -> left);
	d_tree(temp -> right);
	free(temp);
}

