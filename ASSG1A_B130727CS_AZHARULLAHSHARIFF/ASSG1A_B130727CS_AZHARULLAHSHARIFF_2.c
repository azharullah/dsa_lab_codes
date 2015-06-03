#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int satisfy(int z[12],int n)
	{
		int u,v,cnt=0,l=0,w;
		for(u=0;u<n;u++)
			{
				if(z[u]==1)
					cnt++;
			}
		if(cnt==0 || cnt==1)
			return 1;
		for(u=0;u<n;u++)
			{
				if(z[u]==1)
					{
						l++;
						v=u;
						while(z[v+1]==1)
							{
								l++;
								v++;
							}
					}
			}
	w=l-1;
	if(w==cnt)
		return 1;
	else
		return 0;
	}

int cof(int c[12][12],int r,int n)
	{
		int flag=0,f,g,z[12];
		for(f=1;f<=r;f++)
			{
				for(g=0;g<n;g++)
					printf("%d ",c[f][g]);
					printf("\n");
			}
		printf("\n\n");
		for(f=1;f<=r;f++)
			{
				for(g=0;g<n;g++)
					{
						z[g]=c[f][g];
					}
				if(satisfy(z,n))
					flag=0;
				else
					flag=1;
				if(flag==1)
					break;
			}	
	if(flag==1)
		return 0;
	else
		return 1;
	}

void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int *b,int i,int n,int a[11][11],int r) 
{
   int k,t,c[12][12],p=0,q=0,m; 
   if (i == n)
     {
		 for(t=0;t<n;t++)
			{
				q=b[t]-1;
				for(p=1;p<=r;p++)
					{
						c[p][t]=a[p][q];
					}
			}
		 for(p=0;p<n;p++)
				printf("%d", b[p]);
			printf("\n");
		 for(p=1;p<=r;p++)
			{
				for(q=0;q<n;q++)
					printf("%d",c[p][q]);
				printf("\n");
			}
			if(cof(c,r,n))
				{
					printf("\nYes\n");
					for(m=0;m<n;m++)
						printf("%d ",b[m]);
					exit(1);
				}
		}
   else
   {
        for (k=i;k<n;k++)
       {
          swap((b+i),(b+k));
          permute(b,i+1,n,a,r);
          swap((b+i),(b+k));
       }
   }
}

int main()
{
   int a[11][11],b[11],r,c,i,j;
   printf("\n Enter the number of rows of the array (>=1) \n");
   while(1)
	{
		scanf("%d",&r);
		if(r>=1)
			break;
		else
			printf("\n Enter valid number for number of rows \n");
	}
	printf("\n Enter the number of columns of the array (<=10) \n");
	while(1)
	{
		scanf("%d",&c);
		if(c>0 && c<=10)
			break;
		else
			printf("\n Enter valid number for number of columns \n");
	}
	printf("\n Enter the elements of the array\n");
	for(j=0;j<c;j++)
		a[0][j]=j+1;
	for(i=1;i<=r;i++)
    {
        for(j=0;j<c;j++)
            {
                scanf("%d",&a[i][j]);
                if( (a[i][j]!=0) && (a[i][j]!=1) )
					{
					    printf("\n Enter a correct element \n");
					    j--;	
				    }
            }
    }
    
    printf("\n The entered array is: \n");
	for(i=1;i<=r;i++)
		{
			for(j=0;j<c;j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}
   
	for(i=0;i<c;i++)
		b[i]=a[0][i];
	permute(b,0,c,a,r);
	printf("\n No \n");
	return 0;
}
