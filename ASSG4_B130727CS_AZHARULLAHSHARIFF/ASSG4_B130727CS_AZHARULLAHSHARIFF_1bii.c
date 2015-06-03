#include<stdio.h>
#include<stdlib.h>

void insert();
void search();
int get_hash_value(int ele,int size);

int hashtable[100005],size;

void main()
{
	int ch,i;
	scanf("%d",&size);
	for(i=0;i<size;i++)
	{
		hashtable[i]=-32000;
	}
	while(1)
	{
		scanf("%d",&ch);
		switch(ch)
		{
			case 0: printf("\n Exiting the program..\n");
					exit(1);

			case 1: insert();
					break;
			
			case 2: search();
					break;

			default: printf("\n Enter a valid input \n");
				 	 break;
		}
	}
}

void insert()
{
	int ele,val,i=0,pos,j;
	scanf("%d",&ele);
	val=get_hash_value(ele,size);
	while(1)
	{
		if(i>=size)
		{
			printf("Hashtable is full \n");
			return;
		}
		pos=(val+i*i)%size;
		printf("%d ",pos);
		if(hashtable[pos]==-32000)
		{
			hashtable[pos]=ele;
			//printf("%d \n",pos);
			break;
		}
		else
		{
			i++;
		}
	}
}

void search()
{
	int ele,val,pos,i=0;
	scanf("%d",&ele);
	val=get_hash_value(ele,size);
	while(i<size)
	{
		pos=(val+i*i)%size;
		printf("%d ",pos);
		if(hashtable[pos]==ele)
		{
			printf("FOUND \n");
			return;
		}
		else if(hashtable[pos]==-32000)
		{
			printf("NOT FOUND \n");
			return;
		}
		else
		{
			i++;
		}
	}
}

int get_hash_value(int ele,int size)
{
	return ele%size;
}