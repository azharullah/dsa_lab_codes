#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void peek();
void show();
 
struct list
{
	int val;
	int *next;
} *f=NULL,*temp;

void main()
{
	int ch;
	while(1)
	{
		scanf("%d",&ch);
		switch(ch)
		{
			case 0: exit(1);

			case 1: push();
					break;

			case 2: pop();
					break;

			case 3: peek();
					break;

			case 4: show();
					break;

			default: printf("\nEnter a valid choice\n");
		}
	}
}

void push()
{
	struct list *node;
	int ele;
	scanf("%d",&ele);
	node= (struct list *) malloc(sizeof(struct list ));
	node->val=ele;
	node->next=NULL;
	if(f==NULL)
	{
		f=node;
		node->next=NULL;
		node->val=ele;
	}
	else
	{
		node->next=f;
		node->val=ele;
		f=node;
	}
}

void pop()
{
	temp=f;
	if(temp==NULL)
	{
		printf("STACK IS EMPTY");
		return;
	}
	else
	{	
		printf("%d ",temp->val);
		temp=temp->next;
		free(f);
		f=temp;
	}
}

void peek()
{
	if(f==NULL)
	{
		printf("STACK IS EMPTY");
		return;
	}
	printf("%d ",f->val);
}

void show()
{
	temp=f;
	if(temp==NULL)
	{
		printf("STACK IS EMPTY");
		return;
	}
	while(temp!=NULL)
	{
		printf("%d ",temp->val);
		temp=temp->next;
	}
}