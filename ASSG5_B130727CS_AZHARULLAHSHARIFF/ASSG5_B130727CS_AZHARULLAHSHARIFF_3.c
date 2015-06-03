//This is correct, 3 is wrong

#include <stdio.h>
#include <stdlib.h>

struct hash *hashtable = NULL;
int size = 0;

struct graph 
{
    int ele,cost;
    struct graph *next;
}*temp;

int stack[1000],n=-1,disp;

struct hash 
{
    int visited;
    struct graph *head;
};

int u,v,i,vert,edge,cost,node;

void insert(int ele1,int ele2,int cost) 
{
    struct graph *newnode1,*newnode2;
    newnode1=(struct graph *) malloc (sizeof(struct graph));
    newnode2=(struct graph *) malloc (sizeof(struct graph));
    newnode1->ele=ele1;
    newnode1->next=NULL;
    //newnode1->visited=0;
    newnode1->cost=cost;
    newnode2->ele=ele2;
    newnode2->next=NULL;
    //newnode2->visited=0;
    newnode2->cost=cost;

    if (!hashtable[ele1].head) 
    {
        hashtable[ele1].head = newnode2;
    }
    else
    {
        temp=hashtable[ele1].head;
        while(temp->next!=NULL)
        	temp=temp->next;
        temp->next=newnode2;
        temp=newnode2;

        /*newnode2->next = (hashtable[ele1].head);
        hashtable[ele1].head = newnode2;*/
    }

    if (!hashtable[ele2].head) 
    {
        hashtable[ele2].head = newnode1;
    }
    else
    {
        temp=hashtable[ele2].head;
        while(temp->next!=NULL)
        	temp=temp->next;
        temp->next=newnode1;
        temp=newnode1;
        
        /*newnode1->next = (hashtable[ele2].head);
        hashtable[ele2].head = newnode1;*/
    }

    hashtable[ele1].visited=0;
    hashtable[ele2].visited=0;
}

void push(int ele)
{
	n++;
    stack[n]=ele;
}

int pop()
{
	int z;
	z=stack[n];
	n--;
	return z;
}


void BFS(int node)
{
	printf("%d ",node);
	hashtable[node].visited=1;
    push(node);
	
	/*for(i=0;i<=n;i++)
		{
			printf("%d ",stack[i]);
		}*/
	
    while(n!=-1)
    {
        temp=hashtable[stack[n]].head;
        while(temp!=NULL)
        {
            if(hashtable[temp->ele].visited==0)
            {
                printf("%d ",temp->ele);
                push(temp->ele);
                hashtable[temp->ele].visited=1;
                /*printf("\nPushing %d\n",stack[n]);
                for(i=0;i<=n;i++)
                {
                    printf("%d ",stack[i]);
                }*/
                break;
            }
            else
                temp=temp->next;
        }
        if(temp==NULL)
        {
            pop();
            /*printf("\nPopping %d\n",stack[n+1]);
            for(i=0;i<=n;i++)
            {
                printf("%d ",stack[i]);
            }*/
        }
    }
}

void main() 
{
    scanf("%d%d",&vert,&edge);
    hashtable = (struct hash *)calloc(vert , sizeof (struct hash));
    for(i=0;i<edge;i++)
    {
        scanf("%d%d",&u,&v);
        insert(u,v,cost);
    }


    for(i=0;i<vert;i++)
    {
        temp=hashtable[i].head;
        while(temp!=NULL)
        {
            printf("%d-->",temp->ele);
            temp=temp->next;
        }
        printf("NULL\n");
    }

    scanf("%d",&node);
    //printf("\n node is %d\n",node);
    BFS(node);
    printf("\n");
}