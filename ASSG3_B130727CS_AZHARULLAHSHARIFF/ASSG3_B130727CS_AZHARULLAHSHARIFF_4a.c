#include<stdlib.h>
#include<stdio.h>

void addrecord();
int cntrecord();

struct info
{
	char name[30];
	int eno;
	struct info *next;
};

struct info *head=NULL,*temp,*disp;

void main()
{
	int i,n,count;
	scanf("%d",&n);
	if(n<=0)
	{
		printf("\nEnter valid n\n");
		return;
	}
	for(i=0;i<n;i++)
		addrecord();
	count=cntrecord();
	printf("\n%d\n",count);
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
	temp=add;
}
else
{
	temp->next=add;
	add->next=NULL;
	temp=add;
}
}

int cntrecord()
{
	int r=0;
	for (disp=head;disp!=NULL;disp=disp->next)
	{
		if(disp->eno>10)
			r++;
	}
	return r;
}
