#include<stdio.h>
#include<stdlib.h>

void addrecord();
void deleterecord(int );

struct info
{
char name[30];
int eno;
struct info *next;
struct info *prev;
};
struct info *head=NULL,*temp,*disp;


int main()
{
	int n,i;
	scanf("%d",&n);
	if(n<=0)
	{
		printf("\nEnter valid n\n");
		return;
	}
	for(i=0;i<n;i++)
		addrecord();
		
	printf("\n The double linked list is : \n");
	for (disp=head;disp!=NULL;disp=disp->next)
	{
		printf("%d",disp->eno);
		printf(" --> ");
	}
	printf("NULL \n");	
	
	
	for (disp=head;disp!=NULL;disp=disp->next)
	{
		printf("\n %d is skipped \n",disp->eno);
		disp=disp->next;
		if(disp==NULL)
			break;
		deleterecord(disp->eno);
	}
	
	printf("\n The double linked list is : \n");
	for (disp=head;disp!=NULL;disp=disp->next)
	{
		printf("%d",disp->eno);
		printf(" --> ");
	}
	printf("NULL \n");
	return 0;
}


void addrecord()
{
struct info *add;
add=(struct info*)malloc(sizeof(struct info));
scanf("%d",&add->eno);
if (head==NULL)
{
	head=add;
	add->next=NULL;
	add->prev=NULL;
	temp=add;
}
else
{
	temp->next=add;
	add->prev=temp;
	add->next=NULL;
	temp=add;
}
}


void deleterecord(int num)
{
struct info *del;
int teno;
teno=num;
del=(struct info*)malloc(sizeof (struct info));
del=head->next;
if (head->eno==teno)
{
	printf("\n Head data cannot be deleted\n");
	return;
}
while(del)
{
	if(del->eno==teno)
	{
		del->prev->next=del->next;
		if (del->next!=NULL)
		{ 
		//	del->prev->next=del->next;
			del->next->prev=del->prev;
		}
		else
		{
			del->next=temp->next=NULL;
			temp=head;
		}
	return;
	}
	else
	{
		del=del->next;
	}
}
printf("\nInvalid input\n");
}
