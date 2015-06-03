#include<stdio.h>
#include<stdlib.h>

void enqueue();
void dequeue();
void peek();
void show();
 
int stk[1000],n=0,c;

void main()
{
	int ch;
	scanf("%d",&c);
	if(c<=0)
	{
		printf("\nEnter valid n\n");
		return;
	}
	while(1)
	{
		scanf("%d",&ch);
		switch(ch)
		{
			case 0: exit(1);

			case 1: enqueue();
					break;

			case 2: dequeue();
					break;

			case 3: peek();
					break;

			case 4: show();
					break;

			default: printf("\nEnter a valid choice\n");
		}
	}
}

void enqueue()
{
	if(n==c)
	{
		printf("OVERFLOW");
		return;
	}
	int ele,i;
	scanf("%d",&ele);
	for(i=n-1;i>=0;i--)
		stk[i+1]=stk[i];
	stk[0]=ele;
	n++;
}

void dequeue()
{
	if(n==0)
	{
		printf("EMPTY");
		return;
	}
	printf("%d ",stk[n-1]);
	n--;
}

void peek()
{
	if(n==0)
	{
		printf("EMPTY");
		return;
	}
	printf("%d ",stk[n-1]);
}

void show()
{
	int i;
	if(n==0)
	{
		printf("EMPTY");
		return;
	}
	for(i=n-1;i>=0;i--)
		printf("%d ",stk[i]);
}
