#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int valid(char s[])
{
	int p,flag=0;
	for(p=0;p<(strlen(s));p++)
		{
			if( ((s[p]>='a') && (s[p]<='z')) || ((s[p]>='A') && (s[p]<='Z')) )
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

int palindrome(char s1[])
	{
		int i,j=(strlen(s1)-1);
		char s3[100],t;
		strcpy(s3,s1);
		for(i=0;i<=j;i++)
			{
				t=s1[i];
				s1[i]=s1[j];
				s1[j]=t;
				j--;
			}
		if(strcmp(s1,s3)==0)
			return 1;
		else 
			return 0;
	}
	
int main()
{
char s[100],s1[100]; 
int i,tag=0,q,p;
printf("\n ENTER THE STRING.. \n");

while(1)
	{
		scanf("%s",s);
		if(valid(s))
			break;
		else
			printf("\n Enter a valid string \n");
	}
	
for(i=0;i<(strlen(s));i++)
	{
		q=0;
		for(p=0;p<i;p++)
			{
				s1[q]=s[p];
				q++;
			}
		for(p=(i+1);p<(strlen(s));p++)
			{
				s1[q]=s[p];
				q++;
			}
		s1[q]='\0';
		if(palindrome(s1))
			{
				printf("\n %c",s[i]);
				printf("\n %d",i);
				tag=1;
			}
			
	}

printf("\n");

if(tag==0)
	printf("\n Not possible \n");

return 0;
}
