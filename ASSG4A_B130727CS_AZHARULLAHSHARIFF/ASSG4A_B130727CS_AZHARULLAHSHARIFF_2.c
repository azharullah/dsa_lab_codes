#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
	int data;
	struct node *leftchild,*rightchild;
};

struct node *root=NULL,*temp,*temp1;

struct list
{
	int listdata;
	struct list *next;
};

struct list *array[100],*ptr,*ptr1;

void insert(int );	
void display(struct node *);
void printlevels(int a[],int total);
void lltraversal(struct node * ,int );
void lltraversal1(struct node *,int );

int a[100005],n;

void main()
{
	int i=1,j;
	char ch;
	scanf("%d",&n);
	while(1)
	{
		scanf("%d%c",&a[i],&ch);
		if(a[i]<0 && a[i]!=-1)
		{
			printf("Entered nodes are negative \n");
			exit(1);
		}
		if(ch=='\n')
			{
				i++;
				break;
			}
		i++;
	}
	int total=i;
	for(i=1;i<total;i++)
	{
		for(j=1;j<total;j++)
		{
			if(i!=j && a[i]==a[j] && a[i]!=-1 && a[j]!=-1)
			{
				printf("The elements are not unique \n");
				exit(1);
			}
		}
	}
	for(i=1;i<total;i++)
	{
		if(a[i]!=-1)
			insert(a[i]);
	}
	ptr=array[0];
	ptr1=ptr;
	printf("\nInorder traversal:");
	display(root);
	printf("\n"); printlevels(a,total);
	// storing and printing into linked lists 
	//lltraversal(root,0);
	lltraversal1(root,0);
}

void insert(int ele)
{
	struct node *newnode,*temp,*temp1;
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
		display(root1->leftchild);
		printf("%d ",root1->data);
		display(root1->rightchild);
	}
}

void lltraversal1(struct node *root1,int level)
{
	return;
}

void lltraversal(struct node *root1,int level)
{
	struct list *ptr2;
	ptr2=ptr1;
	if(root1!=NULL)
	{
		if(level==0)
		{
			array[level]->listdata=root1->data;
			ptr1++;
			ptr2=ptr1;
			lltraversal(root1->leftchild,level++);
			ptr2++;
			lltraversal(root1->rightchild,level++);
			ptr2++;
			ptr1++;
		}
		else 
		{
			if(array[level]->listdata==-500)
			{
				ptr1=array[level];
			}
			else
			{
				struct list *newlistnode;
				newlistnode=(struct list *) malloc (sizeof(struct list));
				newlistnode->listdata=root1->data;
				newlistnode->next=NULL;
				ptr2->next=newlistnode;
				ptr2++;
				lltraversal(root1->leftchild,level++);
				lltraversal(root1->rightchild,level++);
				ptr1++;	
			}
		}
	}
}

void printlevels(int b[],int total)
{
	int j,i,height,k=0;
	height=(int) log2(total+1);
	//printf("Total is %d,No of levels is %d \n",total,height);
	i=1;
	while(i<=height)
	{
		for(j=pow(2,k);j<pow(2,k+1);j++)
		{
			if(b[j]!=-1)
			{
				printf("%d",b[j]);
				if(j<pow(2,k+1)-1)
				{
					printf("-->");
				}
			}
		}
		printf("\n");
		i++;
		k++;
	}
}