#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int a[],int p,int r);
void quicksort(int a[],int p,int r);
int minele(int b[],int n);
int minpos(int b[],int n);

#define max 1024*1024 

FILE *fp1,*fp2;
char name[]="file1",name2[]="8file1",name3[]="4file1",name4[]="2file";

void main()
{
	int i,j,k,num,a[max];
	fp1=fopen("BIGFILE","w");
	for(i=0;i<64*max;i++)
	{
		num=rand() % 1000;
		fprintf(fp1,"%d\n",num);
	}
	fclose(fp1);
	fp1=fopen("BIGFILE","r");
	rewind(fp1);
	for(i=1;i<=64;i++)
	{
		name[4]=i+48;
		fp2=fopen(name,"w");
		for(j=0;j<max;j++)
		{
			fscanf(fp1,"%d",&num);
			fprintf(fp2,"%d\n",num);
		}
		fclose(fp2);
	}
	fclose(fp1); 
	for(i=1;i<=64;i++)
	{
		name[4]=i+48;
		fp2=fopen(name,"r");
		for(j=0;j<max;j++)
		{
			fscanf(fp2,"%d",&a[j]);
		}
		fclose(fp2);
		quicksort(a,0,max-1);
		fp2=fopen(name,"w");
		for(j=0;j<max;j++)
		{
			fprintf(fp2,"%d\n",a[j]);
		}
		fclose(fp2);
	}
	

	i=1;
	for(k=0;k<8;k++)  //8 way merge 
	{
	name2[5]=k+48+1;
	FILE *f1,*f2,*f3,*f4,*f5,*f6,*f7,*f8,*f88;
	int a1,a2,a3,a4,a5,a6,a7,a8,arr[8],pos,min,z;
	name[4]=i+48;
	f1=fopen(name,"r");
	rewind(f1);
	fscanf(f1,"%d",&a1);
	arr[0]=a1;
	i++;
	name[4]=i+48;
	f2=fopen(name,"r");
	rewind(f2);
	fscanf(f2,"%d",&a2);
	arr[1]=a2;
	i++;
	name[4]=i+48;
	f3=fopen(name,"r");
	rewind(f3);
	fscanf(f3,"%d",&a3);
	arr[2]=a3;
	i++;
	name[4]=i+48;
	f4=fopen(name,"r");
	rewind(f4);
	fscanf(f4,"%d",&a4);
	arr[3]=a4;
	i++;
	name[4]=i+48;
	f5=fopen(name,"r");
	rewind(f5);
	fscanf(f5,"%d",&a5);
	arr[4]=a5;
	i++;
	name[4]=i+48;
	f6=fopen(name,"r");
	rewind(f6);
	fscanf(f6,"%d",&a6);
	arr[5]=a6;
	i++;
	name[4]=i+48;
	f7=fopen(name,"r");
	rewind(f7);
	fscanf(f7,"%d",&a7);
	arr[6]=a7;
	i++;
	name[4]=i+48;
	f8=fopen(name,"r");
	rewind(f8);
	fscanf(f8,"%d",&a8);
	arr[7]=a8;
	i++;
	f88=fopen(name2,"w");
	for(z=0;z<8*max;z++)
	{
	pos=minpos(arr,8);
	min=minele(arr,8);
	printf("%d--%d ",pos,min);
	fprintf(f88,"%d\n",min);
	if(pos==0)
		fscanf(f1,"%d",&arr[0]);
	else if(pos==1)
		fscanf(f2,"%d",&arr[1]);
	else if(pos==2)
		fscanf(f3,"%d",&arr[2]);
	else if(pos==3)
		fscanf(f4,"%d",&arr[3]);
	else if(pos==4)
		fscanf(f5,"%d",&arr[4]);
	else if(pos==5)
		fscanf(f6,"%d",&arr[5]);
	else if(pos==6)
		fscanf(f7,"%d",&arr[6]);
	else if(pos==7)
		fscanf(f8,"%d",&arr[7]);
	}
	fclose(f88);
	}
	
	i=1;
	for(k=0;k<4;k++)  //4 way merge 
	{
	name3[5]=k+48+1;
	FILE *f1,*f2,*f3,*f4,*f44;
	int a1,a2,a3,a4,arr[4],pos,min,z;
	name2[5]=i+48;
	f1=fopen(name2,"r");
	rewind(f1);
	fscanf(f1,"%d",&a1);
	arr[0]=a1;
	i++;
	name2[5]=i+48;
	f2=fopen(name2,"r");
	rewind(f2);
	fscanf(f2,"%d",&a2);
	arr[1]=a2;
	i++;
	name2[5]=i+48;
	f3=fopen(name2,"r");
	fscanf(f3,"%d",&a3);
	rewind(f3);
	arr[2]=a3;
	i++;
	name2[5]=i+48;
	f4=fopen(name2,"r");
	rewind(f4);
	fscanf(f4,"%d",&a4);
	arr[3]=a4;
	i++;
	f44=fopen(name3,"w");
	for(z=0;z<4*max;z++)
	{
	pos=minpos(arr,4);
	min=minele(arr,4);
	printf("%d--%d ",pos,min);
	fprintf(f44,"%d\n",min);
	if(pos==0)
		fscanf(f1,"%d",&arr[0]);
	else if(pos==1)
		fscanf(f2,"%d",&arr[1]);
	else if(pos==2)
		fscanf(f3,"%d",&arr[2]);
	else if(pos==3)
		fscanf(f4,"%d",&arr[3]);
	}
	fclose(f44);
	i=1;
	}

	i=1;
	for(k=0;k<1;k++)  //2 way merge 
	{
	name4[5]=k+48+1;
	FILE *f1,*f2,*f22;
	int a1,a2,arr[2],pos,min,z;
	name3[5]=i+48;
	f1=fopen(name3,"r");
	rewind(f1);
	fscanf(f1,"%d",&a1);
	arr[0]=a1;
	i++;
	name3[5]=i+48;
	f2=fopen(name3,"r");
	rewind(f2);
	fscanf(f2,"%d",&a2);
	arr[1]=a2;
	i++;
	f22=fopen(name4,"w");
	for(z=0;z<2*max;z++)
	{
	pos=minpos(arr,2);
	min=minele(arr,2);
	printf("%d--%d ",pos,min);
	fprintf(f22,"%d\n",min);
	if(pos==0)
		fscanf(f1,"%d",&arr[0]);
	else if(pos==1)
		fscanf(f2,"%d",&arr[1]);
	}
	fclose(f22);
	}

}

int minpos(int b[],int n)
{
	int i,j,min=1000000;
	for(i=0;i<n;i++)
	{
		if(min>b[i])
			{
				min=b[i];
				j=i;
			}
	}
	return j;
}

int minele(int b[],int n)
{
	int i,min=1000000;
	for(i=0;i<n;i++)
	{
		if(min>b[i])
			min=b[i];
	}
	return min;
}

void quicksort(int a[],int p,int r)
 {
 int q;
  if(p<r)
    {
      q=partition(a,p,r);
      quicksort(a,p,q-1);
      quicksort(a,q+1,r);
   }
 }
 
int partition(int a[],int p,int r)
  {
  int x,temp,j,i;
     x=a[r];
     i=p-1;
      for(j=p;j<=r-1;j++)
        {
            if(a[j]<=x)
             {
                i=i+1;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
             }
                  
        }
         temp=a[i+1];
                a[i+1]=a[r];
                a[r]=temp;
       return i+1;
 }               
                

