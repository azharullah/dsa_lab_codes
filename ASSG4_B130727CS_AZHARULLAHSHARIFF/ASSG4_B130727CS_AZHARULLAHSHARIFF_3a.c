#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char data;
	struct node *leftchild,*rightchild;
};

struct node * stack[1000];
int n=-1;

struct node *temp,*temp1,*root=NULL,*temp2;

void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void push(struct node *);
void pop();

void main()
{
	int i=0;
	char exp[1000];
	scanf("%s",exp);
	if(strlen(exp)==0)
	{
		printf("Empty string \n");
		exit(1);
	}
	if(strlen(exp)==1)
	{
		printf("%s \n",exp);
		printf("%s \n",exp);
		printf("%s \n",exp);
		exit(1);
	}
	for(i=0;i<strlen(exp);i++)
	{
		if( exp[i]=='^' || exp[i]=='*' || exp[i]=='/' || exp[i]=='+' || exp[i]=='-' )
		{
			temp1=(struct node*) malloc (sizeof(struct node));
			temp1->data=exp[i];
			temp1->leftchild=NULL;
			temp1->rightchild=NULL;
			pop();
			temp1->rightchild=temp;
			pop();
			temp1->leftchild=temp;
			push(temp1);
		}
		else
		{
			temp=(struct node*) malloc (sizeof(struct node));
			temp->data=exp[i];
			temp->leftchild=NULL;
			temp->rightchild=NULL;
			push(temp);
		}
	}

	inorder(temp1);
	printf("\n");
	preorder(temp1);
	printf("\n");
	postorder(temp1);
}

void push(struct node *temp2)
{   
	n++;
	stack[n]=temp2;
	//printf("pushing %c  ",temp2->data);
}

void pop()
{
	if(n==-1)
		temp=NULL;
	else
	{
		temp=stack[n];
		n--;
		//printf("popping %c",temp->data);
	}
}

void inorder(struct node *root)
{
	if(root->leftchild==NULL && root->rightchild==NULL)
	{
		printf("%c",root->data);
		return;
	}
	printf("(");
	inorder(root->leftchild);
	printf("%c",root->data);
	inorder(root->rightchild);
	printf(")");
}

void postorder(struct node *root)
{
	if(root!=NULL)
	 {  
		postorder(root->leftchild);
		postorder(root->rightchild);
		printf("%c",root->data);
	 }	
}

void preorder(struct node *root)
{
	if(root!=NULL)
	 {  
		printf("%c",root->data);
		preorder(root->leftchild);
		preorder(root->rightchild);
	 }
}
