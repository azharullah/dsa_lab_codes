#include<stdio.h>
#include<stdlib.h>

struct linear_queue
{
int info;
struct linear_queue *next;
}*front,*rear,*newnode,*ptr;

void show();
int underflow();
void enqueue(int);
void dequeue();

void main()
{
int ch,item;
while(1)
{
scanf("%d",&ch);
switch(ch)
{
	case 1:	scanf("%d",&item);
		enqueue(item);
		break;
	
	case 2:
		if(underflow()==1)
		{
			printf("%d",front->info);
			dequeue();
		}
		else 
		{
			printf("Queue is empty");
		}
		break;

	case 4:
		if(underflow()==1)
		{
			printf("\nThe queue is:\n");
			show();
		}
		else 
		{
			printf("Queue is empty");
		}
		break;

	case 3: if(underflow()==1)
		{
			printf("%d",front->info);
		}
		else 
		{
			printf("Queue is empty");
		}
		break;
 	
 	case 0: exit(1);

	default: printf("Enter valid choice");
		 break;
}
}
} 

int underflow()
{
if((front==NULL)&&(rear==NULL))
{
	return(0);
}
else
{
	return(1);
}
} 

void enqueue(int item)
{
newnode=(struct linear_queue*)malloc(sizeof(struct linear_queue));
newnode->info=item;
if((front==NULL)&&(rear==NULL))
{
	front=newnode;
	rear=newnode;
	newnode->next=NULL;
}
else
{
	rear->next=newnode;
	newnode->next=NULL;
	rear=newnode;
}
} 

void dequeue()
{
if(front==rear)
{
	front=NULL;
	rear=NULL;
}
else
{
	front=front->next;
}
}

void show()
{
ptr=front;
while(ptr!=NULL)
{
	printf("%d ",ptr->info);
	ptr=ptr->next;
	}
}
