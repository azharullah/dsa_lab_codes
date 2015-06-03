#include<stdio.h>
#include<stdlib.h>

struct node 
{
	struct node *leftchild;
	struct node *rightchild;
	int data;
};

struct node *root=NULL,*disp;

void insert();
void search();
void findMin(struct node *);
void findMax(struct node *);
void predecessor();
void successor();
void delete();
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void display(struct node *);
struct node * parent(struct node *);
void successore();
void predecessore();

void main()
{
	int ch,p;
	while(1)
	{
		scanf("%d",&ch);
		switch(ch)
		{
			case 0: exit(1);

			case 1: insert();
					display(root);
					break;

			case 2: search();
					break;

			case 3: findMin(root);
					break;

			case 4: findMax(root);
					break;

			case 5: predecessore();	
					break;

			case 6: successore();
					break;

			case 7: delete();
					break;

			case 8: inorder(root);
					break;

			case 9: preorder(root);
					break;

			case 10: postorder(root);
					 break;

			default : printf("\nEnter a valid choice");
					  break;
		}
	}
}

void insert()
{
	struct node *newnode,*temp,*temp1;
	int ele;
	scanf("%d",&ele);
	if(ele<0)
	{
		printf("Invalid input\n");
		return;
	}
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

void search()
{
	int ele;
	scanf("%d",&ele);
	struct node *temp;
	temp=root;
	while(temp!=NULL)
	{
		if(temp->data == ele)
		{
			printf("FOUND \n");
			return;
		}
		else if(temp->data > ele)
		{
			temp=temp->leftchild;
		}
		else
		{
			temp=temp->rightchild;
		}
	}
	printf("NOT FOUND \n");
}

void findMin(struct node *root)
{
	struct node *temp;
	temp=root;
	if(root==NULL)
	{
		printf("NIL \n");
		return;
	}
	if(temp->leftchild == NULL)
	{
		printf("%d\n",temp->data);
	}
	else
	{
		while(temp->leftchild != NULL)
		{
			temp=temp->leftchild;
		}
		printf("%d \n",temp->data);
	}
}

void findMax(struct node *root)
{
	struct node *temp;
	temp=root;
	if(root==NULL)
	{
		printf("NIL \n");
		return;
	}
	if(temp->rightchild == NULL)
	{
		printf("%d\n",temp->data);
	}
	else
	{
		while(temp->rightchild != NULL)
		{
			temp=temp->rightchild;
		}
		printf("%d \n",temp->data);
	}
}

void predecessor()
{
	int ele;
	scanf("%d",&ele);
	struct node *temp,*temp1;
	temp=root;
	while(temp!=NULL)
	{
		if(temp->data == ele)
		{
			//printf("FOUND \n");
			break;
		}
		else if(temp->data > ele)
		{
			temp=temp->leftchild;
		}
		else
		{
			temp=temp->rightchild;
		}
	}
	if (temp->rightchild != NULL)
	{
		findMin(temp->rightchild);
		//printf("%d\n",succ);
		return;
	}
	temp1=parent(temp);
	//printf("Getting parent of %d is %d",temp->data,temp1->data);
	while(temp1!=NULL && temp->data==temp1->rightchild->data)
	{
		temp=temp1;
		temp1=parent(temp1);
	}
	printf("%d\n",temp1->data);
}

void predecessore()
{
	int ele,i,flag=0;
	scanf("%d",&ele);
	struct node *temp;
	temp=root;
	while(temp!=NULL)
		{
			if(temp->data == ele)
			{
				break;
			}
			else if(temp->data > ele)
			{
				temp=temp->leftchild;
			}
			else
			{
				temp=temp->rightchild;
			}
		}
	if(temp==NULL)
	{
		printf("NOT FOUND\n");
		return;
	}
	for(i=0;i<10000;i++)
	{
		temp=root;
		ele--;
		while(temp!=NULL)
		{
			if(temp->data == ele)
			{
				flag=1;
				break;
			}
			else if(temp->data > ele)
			{
				temp=temp->leftchild;
			}
			else
			{
				temp=temp->rightchild;
			}
		}
		if(flag==1)
			break;
	}
	if(flag==1)
		printf("%d\n",ele);
	else
		printf("NIL \n");
}

void successor()
{
	int ele;
	scanf("%d",&ele);
	struct node *temp,*temp1;
	temp=root;
	while(temp!=NULL)
	{
		if(temp->data == ele)
		{
			//printf("FOUND \n");
			break;
		}
		else if(temp->data > ele)
		{
			temp=temp->leftchild;
		}
		else
		{
			temp=temp->rightchild;
		}
	}
	if (temp->rightchild != NULL)
	{
		findMin(temp->rightchild);
		//printf("%d\n",succ);
		return;
	}
	temp1=parent(temp);
	//printf("Getting parent of %d is %d",temp->data,temp1->data);
	while(temp1!=NULL && temp->data==temp1->rightchild->data)
	{
		temp=temp1;
		temp1=parent(temp1);
	}
	printf("%d\n",temp1->data);
}

void successore()
{
	int ele,i,flag=0;
	scanf("%d",&ele);
	struct node *temp;
	temp=root;
	while(temp!=NULL)
		{
			if(temp->data == ele)
			{
				break;
			}
			else if(temp->data > ele)
			{
				temp=temp->leftchild;
			}
			else
			{
				temp=temp->rightchild;
			}
		}
	if(temp==NULL)
	{
		printf("NOT FOUND\n");
		return;
	}
	for(i=0;i<10000;i++)
	{
		temp=root;
		ele++;
		while(temp!=NULL)
		{
			if(temp->data == ele)
			{
				flag=1;
				break;
			}
			else if(temp->data > ele)
			{
				temp=temp->leftchild;
			}
			else
			{
				temp=temp->rightchild;
			}
		}
		if(flag==1)
			break;
	}
	if(flag==1)
		printf("%d\n",ele);
	else
		printf("NIL \n");
}

void delete()
{
	int tright=0,tleft=0,x;
	struct node *ptr=root;
	struct node *parent=root;
	struct node *t1=root;
	struct node *temp=root;
	scanf("%d",&x);
	if(root->data==x && root->leftchild==NULL && root->rightchild==NULL)
	{
		root=NULL;
		//printf("NIL\n");
		return;
	}
	while(ptr!=NULL && ptr->data!=x)
	{
	parent=ptr;
	if (x < ptr->data)
		ptr=ptr->leftchild;
	else
		ptr=ptr->rightchild;
	}
	if (ptr==NULL)
	{
		printf("Element is not present \n");
		return ;
	}
	else if( t1->data ==x && (t1->leftchild == NULL || t1->rightchild == NULL) )
		{
			if(t1->leftchild==NULL)
				t1=t1->rightchild;
			else
				t1=t1->leftchild;
		}
	else if (ptr->leftchild==NULL)
		{
			if (x < parent->data)
				parent->leftchild = ptr->rightchild;
			else
				parent->rightchild = ptr->rightchild;
		}
	else if (ptr->rightchild == NULL)
		{
			if (x<parent->data)
				parent->leftchild = ptr->leftchild;
			else
				parent->rightchild = ptr->leftchild;
		}
	else
	{
		temp=ptr;
		parent=ptr;
		if( (ptr->leftchild) >= (ptr->rightchild) )
		{
			ptr=ptr->leftchild;
			while(ptr->rightchild !=NULL)
			{
				tright=1;
				parent=ptr;
				ptr=ptr->rightchild;
			}
			temp->data=ptr->data;
			if(tright)
				parent->rightchild=ptr->leftchild;
			else
				parent->leftchild=ptr->leftchild;
		}
		else
		{
			ptr=ptr->rightchild;
			while (ptr->leftchild!=NULL)
			{
				tleft=1;
				parent=ptr;
				ptr=ptr->leftchild;
			}
			temp->data=ptr->data;
			if(tleft)
				parent->leftchild=ptr->rightchild;
			else
				parent->rightchild=ptr->rightchild;
		}
	free(ptr);
	}
}

void inorder(struct node *root1)
{
	if(root1!=NULL)
	{
		inorder(root1->leftchild);
		printf("%d ",root1->data);
		inorder(root1->rightchild);
	}
}

void preorder(struct node *root1)
{
	if(root1!=NULL)
	{
		printf("%d ",root1->data);
		preorder(root1->leftchild);
		preorder(root1->rightchild);
	}
}

void postorder(struct node *root1)
{
	if(root1!=NULL)
	{
		postorder(root1->leftchild);
		postorder(root1->rightchild);
		printf("%d ",root1->data);
	}
}

void display(struct node *root1) 
{
	if(root1!=NULL)
	{
		printf("%d ",root1->data);
		display(root1->leftchild);
		display(root1->rightchild);
	}
}

struct node * parent(struct node *somenode)
{
	struct node *temp,*temp1;
	temp1=root;
	temp=NULL;
	while(temp1!=NULL)
		{
			temp=temp1;
			if(temp1->data > somenode->data)
			{
				temp1=temp1->leftchild;
			}
			else if(temp1->data < somenode->data)
			{
				temp1=temp1->rightchild;
			}
		}
	printf("parent ** %d\n",temp->data);
	return temp;
}