#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *leftchild,*rightchild;
};

struct node *root=NULL,*temp,*temp1,*array[100];

void insert(int );	
void display(struct node *);
void build_binary_tree(int a[],int total);
int largestbst(struct node *root1,int size);

int a[100005],n,total;

void main()
{
	int i=1,j,z;
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
	total=i;
	build_binary_tree(a,total);
	printf("Inorder traversal :");
	display(root);
	printf("\n Total is %d \n",total);
	z=largestbst(root,0);
	printf("\n%d\n",z);
}

int largestbst(struct node *root1,int size)
{
	if(root1->leftchild==NULL || root1->leftchild->data==-1)
	{
		if(root1->rightchild==NULL || root1->rightchild->data==-1)
			{
				printf("\n Reached the end, returning %d\n",size);
				if(size==0)
					return size+1;
				else
					return size;
			}
	}
	else
	{
		if(root1->data > root1->leftchild->data && root1->data < root1->rightchild->data)
		{
			if(size==0)
			{	
				printf("\nPassing %d through %d to leftchild\n",size+3,root1->data);
				largestbst(root1->leftchild,size+3);
				printf("\nPassing %d through %d to rightchild\n",size+3,root1->data);
				largestbst(root1->rightchild,size+3);
			}
			else
			{
				printf("\nPassing %d through %d to leftchild\n",size+3,root1->data);
				largestbst(root1->leftchild,size+2);
				printf("\nPassing %d through %d to rightchild\n",size+3,root1->data);
				largestbst(root1->rightchild,size+2);
			}
		}
		else
		{
			printf("\nbreaking through %d to leftchild\n",root1->data);
			largestbst(root1->leftchild,0);
			printf("\nbreaking through %d to leftchild\n",root1->data);
			largestbst(root1->rightchild,0);	
		}
	}
}

void build_binary_tree(int a[],int total)
{
	int i;
	for(i=1;i<total;i++)
	{
		array[i]=(struct node *) malloc (sizeof(struct node));
		array[i]->data=a[i];
		array[i]->leftchild=NULL;
		array[i]->rightchild=NULL;
	}
	for(i=1;i<(total-1/2);i++)
	{
		array[i]->leftchild=array[2*i];
		array[i]->rightchild=array[2*i+1];
	}
	root=array[1];
}

void display(struct node *root1)
{
	if(root1!=NULL)
	{
		display(root1->leftchild);
		if (root1->data!=-1)
			printf("%d ",root1->data);
		display(root1->rightchild);
	}
}
