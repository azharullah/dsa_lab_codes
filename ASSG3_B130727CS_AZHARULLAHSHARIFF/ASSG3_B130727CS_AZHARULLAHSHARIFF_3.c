#include<stdio.h>
#include<stdlib.h>

void insert();
void removed();
void peek();
void increase_priority();
void makeheap();
void max_heap(int i);
void increase_key(int i,int ele);
int parent(int i);
int left(int i);
int right(int i);
 
int heap[1000],n=0,hsize=0;

void main()
{
	int ch;
	//scanf("%d",&ch);
	while(1)
	{
		scanf("%d",&ch);
		switch(ch)
		{
			case 0: exit(1);

			case 1: insert();
					break;

			case 2: removed();
					break;

			case 3: peek();
					break;

			//case 4: increase_priority();
			//		break;

			default: printf("\nEnter a valid choice\n");
		}
	}
}

void insert()
{
	int ele,i;
	scanf("%d",&ele);
	hsize++;
	heap[hsize]=-32000;
	printf("%%");
	//increase_key(i,ele);
	makeheap();
	max_heap(0);
}

void removed()
{
	if(hsize<0)
	{
		printf("\nHEAP UNDERFLOW\n");
		return;
	}
	printf("%d",heap[0]);
	heap[0]=heap[hsize];
	hsize--;
	max_heap(0);
}

void peek()
{
	if(n==0)
	{
		printf("EMPTY");
		return;
	}
	printf("%d ",heap[0]);
}

void increase_key(int i,int ele)
{
	int k,temp;
	if(ele<heap[i])
	{
		printf("\nNOT POSSIBLE\n");
		return;
	}
	heap[i]=ele;
	while( (i>1) && (heap[parent(i)]<heap[i]) )
	{
		temp=heap[parent(i)];
		heap[parent(i)]=heap[i];
		heap[i]=temp;
		i=parent(i);
	}
}

void makeheap()
{
	int i;
	for(i=(n/2);i>=0;i++)
		max_heap(i);
}

void max_heap(int i)
{
	int l,r,largest,temp;
	l=left(i);
	r=right(i);
	if( (l<=hsize) && (heap[l]>heap[i]) )
		largest=l;
	else largest=i;
	if( (r<=largest) && (heap[largest]<heap[r]) )
		largest=r;
	if(largest!=i)
	{
		temp=heap[i];
		heap[i]=heap[largest];
		heap[largest]=temp;	
	}
	max_heap(largest);
}

int left(int i)
	{
		return (2*i);
	}

int right(int i)
	{
	return (2*i+1);
	}
	
int parent(int i)
	{
		return (i/2);
	}
