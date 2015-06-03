#include <stdio.h>
#include <stdlib.h>

struct hash *hashtable = NULL;
struct node *nodes = NULL;
int size = 0;

struct graph 
{
    int ele,cost;
    struct graph *next;
}*temp;

int queue[1000],n=-1,disp;

struct hash 
{
    int visited;
    struct graph *head;
};

struct node
{
    int u,v;
};

int u,v,i,j,m,vert,edge,cost,node,p=0,count1=0,count2=0,count=0,count3=0;

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

void enqueue(int ele)
{
	n++;
	for(i=n;i>=0;i--)
		queue[i+1]=queue[i];
	queue[0]=ele;
}

int dequeue()
{
	int z;
	z=queue[n];
	n--;
	return z;
}


void BFS(int node)
{
    //printf("%d ",node);
	hashtable[node].visited=1;
	temp=hashtable[node].head;

	/*for(i=0;i<=n;i++)
		{
			printf("%d ",queue[i]);
		}*/
	
	while(temp!=NULL)
	{
		if(hashtable[temp->ele].visited==0)
			{
				enqueue(temp->ele);
				/*printf("\n Enqueueing %d\n",temp->ele);
				for(i=0;i<=n;i++)
				{
					printf("%d ",queue[i]);
				}*/
				hashtable[temp->ele].visited=1;
			}
		temp=temp->next;
	}
	
	while(n!=-1)
	{
		disp=dequeue();
		/*printf("\n Dequeueing %d\n",disp);
		for(i=0;i<=n;i++)
		{
			printf("%d ",queue[i]);
		}*/
		//printf("%d ",disp);
		temp=hashtable[disp].head;
		while(temp!=NULL)
		{
			if(hashtable[temp->ele].visited==0)
				{
					enqueue(temp->ele);
					/*printf("\n Enqueueing %d\n",temp->ele);
					for(i=0;i<=n;i++)
					{
						printf("%d ",queue[i]);
					}*/
					hashtable[temp->ele].visited=1;
				}
			temp=temp->next;
		}
	}
}

void main() 
{
    scanf("%d%d",&vert,&edge);
    if(vert==0 || edge==0)
    {
        printf("Enter valid number of edges or vertices\n");
        exit(1);
    }
    hashtable = (struct hash *)calloc(vert , sizeof (struct hash));
    nodes = (struct node *) calloc (edge , sizeof (struct node));

    for(i=0;i<edge;i++)
    {
        scanf("%d%d",&u,&v);
        //insert(u,v,0);
        nodes[i].u=u-1;
        nodes[i].v=v-1;
    }

    for (i = 0; i < vert; i++)
    {
        hashtable[i].visited=0;
        hashtable[i].head=NULL;
    }

    for(i=0;i<edge;i++)
        insert(nodes[i].u,nodes[i].v,0);

    count1=0;
    BFS(0);
    count1++;
    for(j=0;j<vert;j++)
    {
        if(hashtable[j].visited==0)
        {
            BFS(j);
            count1++;
        }
    }

    for(m=0;m<edge;m++)
    {
        //printf("%d***\n",count1);
        count2=0;
        for(p=0;p<vert;p++)
        {
            hashtable[p].head=NULL;
            hashtable[p].visited=0;
        }

        for(j=0;j<edge;j++)
        {
           if(j!=m)
           {
               insert(nodes[j].u,nodes[j].v,0);
               //printf("inserting %d and %d \n",nodes[j].u,nodes[j].v);
           }
        }

        BFS(0);
        count2++;
        for(j=0;j<vert;j++)
        {
            if(hashtable[j].visited==0)
            {
                BFS(j);
                count2++;
            }
        }

        //printf("count1=%d,count2=%d\n",count1,count2);
        if(count1!=count2)
        {
            printf("%d--%d\n",nodes[m].u+1,nodes[m].v+1);
            count3++;
        }
    }
    printf("Total number of bridges is %d\n",count3);
}