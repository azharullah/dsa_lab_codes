#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int f,int m,int l);
 
void mergesort(int a[],int f,int l)
{
	int m;
	m=f+(l-f)/2;
	if(f<l)
	{
		mergesort(a,f,m);
		mergesort(a,m+1,l);
		merge(a,f,m,l);
	}
}

void merge(int a[],int f,int m,int l)
{
	int l1[100],l2[100],p,q,x,y,z;
	p=m-f+1;
	q=l-m;
	for(x=0;x<p;x++)
		l1[x]=a[f+x];
	l1[f+x] = 1000000;
	for(y=0;y<q;y++)
		l2[y]=a[m+y+1];
	l2[m+y+1] = 1000000;
	x=0;
	y=0;
	z=f;
	while((x<p) && (y<q))
	{
		if(l1[x]>=l2[y])
		{
			a[z]=l2[y];
			y++;
			z++;
		}
		else 
		{
			a[z]=l1[x];
			x++;
			z++;
		}
	}
	while(x<p)
	{
		a[z]=l1[x];
		z++;
		x++;
	}
	while(y<q)
	{
		a[z]=l2[y];
		z++;
		y++;
	}
}

int main()
 {
 	int a[100],i,j,n;
 	char tc;
 	clock_t start,end;
 	double exe_time;
 	if(scanf("%d%c",&n,&tc)==2 && tc=='\n'&& n>0)
 	{
 	for(i=0;i<n;i++)
 		{
 			if(!(scanf("%d%c",&a[i],&tc)==2 && tc=='\n'))
 			{
 				printf("\n Enter valid numbers \n");
 				exit(1);
 			}
 		}
 	start=clock();
 	mergesort(a,0,n-1);
 	end=clock();
 	printf("\n Sorted array is :\n");
 	for(i=0;i<n;i++)
 		printf("%d \n",a[i]);
 	exe_time=(double)(end-start)/CLOCKS_PER_SEC;
 	printf("The execution time is %lf \n",exe_time);
 	return 0;
 	}
 	else 
 	{
 		printf("\n Enter a valid number \n");
 		exit(1);
 	}
 }