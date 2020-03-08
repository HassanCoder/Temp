#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *left;
	struct node *right;
};

struct node* AddNode(int data);
void InOrder(struct node *node);
void PreOrder(struct node *node);
void PostOrder(struct node *node);

int main(void)
{
	struct node *root;

	root = AddNode(1);
	root->left = AddNode(2);
	root->right = AddNode(3);
	root->left->left = AddNode(4);
	root->left->right = AddNode(5);

	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);

	return 0;
}

struct node* AddNode(int data)
{
	struct node *node;
	node = (struct node*) malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}


void PreOrder(struct node *node)
{
	if(node == NULL)
		return;

	printf("%d ", node->data);

	PreOrder(node->left);
	PreOrder(node->right);

	return;
}

void InOrder(struct node *node)
{
	if(node == NULL)
		return;

	InOrder(node->left);
	printf("%d ", node->data);
	InOrder(node->right);

	return;
}

void PostOrder(struct node *node)
{
	if(node == NULL)
		return;

	PostOrder(node->left);
	PostOrder(node->right);
	printf("%d ", node->data);

	return;
}







