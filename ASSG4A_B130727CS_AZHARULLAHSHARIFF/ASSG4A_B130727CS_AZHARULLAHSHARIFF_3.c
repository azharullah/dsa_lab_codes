#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *leftchild,*rightchild;
};

struct node *root=NULL,*temp,*temp1;

void insert(int );	
void display(struct node *);

int a[100005],n;

void main()
{
	int i=0,j;
	char ch;
	while(1)
	{
		scanf("%d%c",&a[i],&ch);
		if(ch=='\n')
			{
				i++;
				break;
			}
		i++;
	}
	n=i;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j && a[i]==a[j])
			{
				printf("The elements are not unique \n");
				exit(1);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		insert(a[i]);
	}
	printf("(");
	display(root);	
	printf(")");
	printf("\n");
}

void insert(int ele)
{
	struct node *newnode,*temp,*temp1;
	/*if(ele<0)
	{
		printf("Invalid input\n");
		return;
	}*/
	newnode=(struct node *) malloc (sizeof(struct node));
	newnode->data=ele;
	newnode->leftchild=NULL;
	newnode->rightchild=NULL;
	if (root==NULL)
	{
		root=newnode;
		return;
	}
	else
	{	
		temp1=root;
		temp=NULL;
		while(temp1!=NULL)
		{
			temp=temp1;
			if(temp1->data > ele)
			{
				temp1=temp1->leftchild;
			}
			else if(temp1->data < ele)
			{
				temp1=temp1->rightchild;
			}
			else
			{
				printf("Element is already present");
				return;
			}
		}
		if(temp->data > ele)
		{
			temp->leftchild=newnode;
		}
		else 
		{
			temp->rightchild=newnode;
		}
	}
}


void display(struct node *root1)
{
	if(root1!=NULL)
	{
		printf("%d",root1->data);
		printf("(");
		display(root1->leftchild);
		printf(")");
		printf("(");
		display(root1->rightchild);
		printf(")");
	}
}