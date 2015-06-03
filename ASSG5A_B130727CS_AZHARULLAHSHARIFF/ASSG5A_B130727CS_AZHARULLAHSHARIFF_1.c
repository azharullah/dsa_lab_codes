#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int v2,time=0,t=0,c1;

struct arr
{
  int co;
  int val;
}d1[100];

struct node
{
   struct node *up;
   int cost;
   struct graph *nt;
};

struct graph
{
   struct graph *next; 
   struct graph *prev;
   struct node *up;
   int colour;
   int f;
   struct graph * p;
   int d;
   int value;
}*root1,*b[200],*temp,*head,*tail,*u;

struct node *newnode(int e)
{
   struct node *temp = (struct node *) malloc(sizeof(struct node ));
   temp->nt = b[e];
   temp->cost=c1;
   temp->up=NULL;
   return temp;
}


struct graph * make_graph(int e)
 {
    struct graph *temp= (struct graph *) malloc(sizeof(struct graph ));
  
     temp->colour=1;
     temp->d=INT_MAX;
     temp->value=e;
     temp->p=NULL;
     temp->up=NULL;
     return (temp);
 }  


struct graph * insert(struct graph *root,struct graph *node)
{
   if(root==NULL)
    {
      return(node);
    }
   else
     {
         root->next=insert(root->next,node);
     }
  return root;
}

int a[100],l2=0,l1=0;

void push(int e)
{
  a[l2]=e;
 l2++;
}

void print(int n)
{
  struct graph *temp;
  struct node *end;
  int i;

  for(i=0;i<n;i++)
  {
     end=b[i]->up;
  printf("%d ",b[i]->value);
      while(end!=NULL)
      {
	 printf("%d",end->nt->value);
         printf( " " );
         end=end->up;

      }
      printf("\n");
   }

}

void col(int n)
{ int i;

   for(i=0;i<n;i++)
   {
    printf("%d ",b[i]->colour);

   }
   printf("\n\n");
}

struct graph *DFS(struct graph *u,int n,int z)
{ 

struct node *v;
  time=time+1;
//printf("%d ",u->value);
 
u->d=time;
 u->colour=2;
    v=u->up;
   if(v==NULL)
   {
   }
   else
   while(v!=NULL)
   {
        if(v->nt->colour==1)
          {
            v->nt->p=u;
             DFS(v->nt,n,0);
          }
    v=v->up;
  }

push(u->value);
u->colour=3;
time=time+1;
u->f=time;
}

int hash(int x,int n)
{
  return((x+t)%n);
}


void main()
{
struct node *temp1,*temp2;
struct node *end;

int x,i=0,j,e,e1,e2,v1,c,s,s1,n,y[100],y1[100];
int n1=0,w[100],sum=0;;
char p1,p2,x1,x2;
scanf("%d%d\n",&n,&e);

scanf("%c\n",&x1);
scanf("%c",&x2);

for(i=0;i<n;i++)
{
  b[i]= make_graph(i);
}

for(i=0;i<e;i++)
{
  c=0;
  scanf("\n%c %c %d",&p1,&p2,&c1);
  v1=p1-65;
  v2=p2-65;

  struct node *temp1;
  temp1 = newnode(v2);
  end= b[v1]->up;
  if(b[v1]->up==NULL)
  {
    b[v1]->up = temp1;
  }
  else{
  while(end->up!=NULL)
  {
    end=end->up;
  }
  end->up = temp1;
  }

y[i]=v1;
y1[i]=v2;

}
s=x1-65;

if(s<0 || s>n-1)
{
  printf("invalid input\n");
  exit(1);
}

while(n1!=n)
{ 
  s1=hash(s,n);
  if(b[s1]->colour==1)
    DFS(b[s1],n,0);
  t++;
  n1++;
}

j=0;
for(i=l2-1;i>=0;i--)
{
  d1[j].val=a[i];
  d1[j].co=INT_MAX;
j++;
}


struct node* v;
for(i=0;i<n;i++)
{

  if(d1[i].val==s)
   {
      d1[i].co=0;
   }
}

int j1,i1,s2;
s2=x2-65;
for(i=0;i<n;i++)
{

  if(d1[i].val==s)
   {
      i1=i;
   }
}

for(i=i1;i<n;i++)
{
     
     u=b[d1[i].val];
    v=u->up;

if(d1[i].val==s2)
break;

   while(v!=NULL)
   {

      for(j=0;j<n;j++)
       {
         if(v->nt->value==d1[j].val)
          { 
               break;
          }      
        }
 
           if(v->cost+d1[i].co<d1[j].co)
            {
            d1[j].co=v->cost+d1[i].co;
            v->nt->p=u;
            
            }
      v=v->up;
   }

}

u=b[s2];
j=0;

for(i=0;i<n;i++)
{
if(d1[i].val==s2)
 sum=d1[i].co;
}
while(u!=NULL&&u->value!=s)
{
  w[j]=u->value;
for(i=0;i<n;i++)
 {
    if(u->value==d1[i].val)
     {
       if(d1[i].co==INT_MAX)
        {
            printf("no path found\n");
            exit(1);
        }
       break;
     }
 }
 j++;
 u=u->p;
}

if(u!=NULL && u->value==s)
{
w[j]=u->value;
j++;
for(i=0;i<n;i++)
 {
    if(u->value==d1[i].val)
     {
        if(d1[i].co==INT_MAX)
        {
            printf("no path found!\n");
            exit(1);
        }
       
       break;
     }
}

} 
printf("\n%d\n",sum);
for(i=j-1;i>0;i--)
{
  printf("%c->",w[i]+'A');
}
printf("%c\n",w[0]+'A');
}