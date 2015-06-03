#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void radixsort(char a[100][100],int n);
void linearsort(char a[100][100],int n,int j);
int maxlen;

void radixsort(char a[100][100],int n)
{
int i,l,j;
for(i=0;i<maxlen;i++)
{
j=i;
linearsort(a,n,j); 
}
}

void main()
{
char a[100][100],ch;
int i,n,l;
clock_t start,end;
double exe_time;
maxlen=0;
if(scanf("%d%c",&n,&ch)==2 && ch=='\n'&& n>0)
{
for(i=0;i<n;i++)
 {
   scanf("%s",a[i]);
   if(maxlen<strlen(a[i]))
     maxlen=strlen(a[i]);
 }
start=clock();
  radixsort(a,n);
end=clock();
}
else
printf("\n Entered number is invalid \n");
printf("\n\n");
for(i=0;i<n;i++)
    printf("%s \n",a[i]);
exe_time=(double)(end-start)/CLOCKS_PER_SEC;
  printf("The execution time is %lf \n",exe_time);
}

void linearsort(char a[100][100],int n,int j)
{
    int temp[100],l,i;
     char b[100][100],f[100],val;
    for(i=0;i<16;i++)
     temp[i]=0;
     
    for(i=0;i<n;i++)
     {
     strcpy(f,a[i]);
       l=strlen(f)-j;
    if(l>=1)
    {   
      if( a[i][l-1]>=65 && a[i][l-1]<=97)
        {
          temp[a[i][l-1]-55]++;
        }
        else if(a[i][l-1]>=48 && a[i][l-1]<=58)
           temp[a[i][l-1]-47]++;
         else
           {
           printf("invalid input\n");
            exit(1);  
           }
    }
    
    else
    {
      val='0';
      temp[val-47]++;
     }
     
     
      }
      for(i=1;i<16;i++)
      {
       temp[i]+=temp[i-1];
      }
      
      for(i=n-1;i>=0;i--)
       {
          strcpy(f,a[i]);
       l=strlen(f)-j;
       if(l>=1)
       {
               if( a[i][l-1]>=65 && a[i][l-1]<=97)
                  {
                     strcpy(b[temp[a[i][l-1]-55]-1],a[i]);
                      temp[a[i][l-1]-55]--;
                  }
               else
                  {
                   strcpy(b[temp[a[i][l-1]-47]-1],a[i]);
                     temp[a[i][l-1]-47]--;
                     }
      }
      else
        {
        val='0';
        strcpy(b[temp[val-47]-1],a[i]);
        temp[val-47]=-1;
      }
      }
      
   for(i=0;i<n;i++)
 {
   strcpy(a[i],b[i]);
 }  
}