#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>

int heapsize;

int validy(char b[])
{
		int p,q,flag=0;
		for(q=0;q<strlen(b);q++)
			{
				if( (b[q]>='A') && (b[q]<='Z') )
					flag=0;
				else
					{
						flag=1;
						break;
					}
			if(flag==1)
				break;
			}
if(flag==0)
		return 1;
else 
		return 0;
}

int left(int i)
{
	return 2*i;
}

int right(int i)
{
	return (2*i+1);
}

void maxheap(char a[100][100],int i)
{
	int largest;
	char temp[100];
	int l = left(i);
	int r = right(i);
	if(l <= heapsize && (strcmp(a[l] ,a[i])  > 0))
		largest = l;
	else
		largest = i;
	if(r <= heapsize && (strcmp(a[r] ,a[largest])  > 0))
		largest = r;
	if(largest != i)
	{
		strcpy(temp,a[largest]);
		strcpy(a[largest],a[i]);
		strcpy(a[i],temp);
		maxheap(a,largest);
	}
}
void makeheap(char a[100][100],int n)
{
	int j;
	heapsize = n;
	for (j = floor(n/2); j >= 1; j--)
	{
		maxheap(a,j);
	}
}

void heapsort(char a[100][100],int n)
{
	int i;
	char temp[100];
	makeheap(a,n);

	for (i = n; i >= 2; i--)
	{
		strcpy(temp,a[1]);
		strcpy(a[1],a[i]);
		strcpy(a[i],temp);
		heapsize--;
		maxheap(a,1);
	}
}

void main()
{
	char a[100][100],swap[100],tc,b[100];
	int i,n,x;
	clock_t start,end;
 	double exe_time;
	if(scanf("%d%c",&n,&tc)==2 && tc=='\n'&& n>0)
	{
	for(i=1;i<=n;i++)
		{
			scanf("%s",a[i]);
			strcpy(b,a[i]);
			if(validy(b))
				continue;
			else
			{
				printf("\n Enter a valid string \n");
				exit(1);
			}
        }
	start=clock();
	heapsort(a,n);
	end=clock();
    printf("\nThe sorted array is: \n");
    for(i=1;i<=n;i++)
        {
            printf("%s\n",a[i]);
        }
	exe_time=(double)(end-start)/CLOCKS_PER_SEC;
 	printf("The execution time is %lf \n",exe_time);
	}
	else
	{
		printf("\n Enter valid number \n");
		exit(1);
	}
}