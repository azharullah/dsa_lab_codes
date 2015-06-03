#include <stdio.h>
#include <stdlib.h>

struct set
{
	int value;
	struct set *parent;
	int rank;
}*temp;

struct list
{
	struct set *next;
}*array;

int i=0,j;

void makeset(int );
struct set * findset(int );
void unionset();

void main()
{
	int ch,ele;
	array=(struct list *) calloc (10000,sizeof(struct list));
	while(1)
	{
		scanf("%d",&ch);
		switch(ch)
		{
			case 0 : printf("Exiting the program \n");
					 exit(1);
					 
			case 1 : scanf("%d",&ele);
					 makeset(ele);
					 break;
					 
			case 2 : scanf("%d",&ele);
					 temp=findset(ele);
					 printf("%d\n",temp->value);
					 break;
			
			case 3 : unionset();
					 break;
					 
			default : printf("Enter a valid choice\n");
					  break; 
		}		
	}
}

void makeset(int ele)
{
	struct set *newset;
	newset=(struct set *) malloc (sizeof(struct set));
	newset->value=ele;
	newset->parent=newset;
	array[i].next=newset;
	i++;
	//printf("%d\n",newset->value);
}

struct set * findset(int ele)
{
	for(j=0;j<i;j++)
	{
		if(array[j].next->value==ele)
			break;
	}
	temp=array[j].next;
	while(1)
	{
		if(temp->parent==temp)
			return temp;
		else
			temp=temp->parent;
	}
}

void unionset()
{
	struct set *ptr1,*ptr2;
	ptr1=(struct set *) malloc (sizeof(struct set));
	ptr2=(struct set *) malloc (sizeof(struct set));
	ptr1->rank=0;
	ptr2->rank=0;
	int ele1,ele2;
	scanf("%d%d",&ele1,&ele2);
	ptr1=findset(ele1);
	ptr2=findset(ele2);	
	if(ptr1->rank>ptr2->rank)
		ptr2->parent=ptr1;
	else if(ptr1->rank<ptr2->rank)
		ptr1->parent=ptr2;
	else
	{
		ptr2->parent=ptr1;
		ptr1->rank++;
	}
}
