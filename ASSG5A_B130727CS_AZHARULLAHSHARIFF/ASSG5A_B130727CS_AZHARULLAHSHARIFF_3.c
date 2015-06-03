#include <stdio.h>
#include <stdlib.h>

struct hash *hashtable = NULL;
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
    char color;
    struct graph *head;
};

int u,v,i,j,vert,edge,cost,node;

void insert(int ele1,int ele2) 
{
    struct graph *newnode1,*newnode2;
    newnode1=(struct graph *) malloc (sizeof(struct graph));
    newnode2=(struct graph *) malloc (sizeof(struct graph));
    newnode1->ele=ele1;
    newnode1->next=NULL;
    //newnode1->visited=0;
    //newnode1->cost=cost;
    newnode2->ele=ele2;
    newnode2->next=NULL;
    //newnode2->visited=0;
    //newnode2->cost=cost;

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


int BFS(int node)
{
	//printf("%d ",node);
	hashtable[node].visited=1;
    hashtable[node].color='r';
    //printf("coloring %d with red\n",node);
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
                hashtable[temp->ele].color='b';
                //printf("coloring %d with blue\n",temp->ele);
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
                    if(hashtable[disp].color=='r')
                    {
                        hashtable[temp->ele].color='b';
                        //printf("coloring %d with blue\n",temp->ele); 

                        /*if(hashtable[temp->ele].color=='r')
                            {
                                //return 0;
                                printf("exiting as %d has red",temp->ele);
                                return 0;
                            }
                        else
                            {
                                hashtable[temp->ele].color='b';
                                printf("coloring %d with blue\n",temp->ele);
                            }*/
                    }
                    else
                    {   
                        hashtable[temp->ele].color='r';
                        //printf("coloring %d with red\n",temp->ele);
                        /*if(hashtable[temp->ele].color=='b')
                            {
                                printf("exiting as %d has blue",temp->ele);
                                return 0;
                            }
                        else
                            {
                                hashtable[temp->ele].color='r';
                                printf("coloring %d with red\n",temp->ele);
                            }*/
                    }
				}
			temp=temp->next;
		}
	}
    for(i=0;i<vert-1;i++)
    {
        temp=hashtable[i].head;
        while(temp!=NULL)
        {
            if(hashtable[i].color==hashtable[temp->ele].color)
                return 0;
            temp=temp->next;
        }
    }

    return 1;
}

void main() 
{
    int ch;
    scanf("%d%d",&vert,&edge);
    if(vert==0 || edge==0)
    {
        printf("Enter valid number of edges or vertices\n");
        exit(1);
    }
    hashtable = (struct hash *)calloc(vert , sizeof (struct hash));
    for(i=0;i<edge;i++)
    {
        scanf("%d%d",&u,&v);
        //printf("inserting %d %d\n",u-1,v-1);
        insert(u-1,v-1);
    }


    /*for(i=0;i<vert;i++)
    {
        temp=hashtable[i].head;
        while(temp!=NULL)
        {
            printf("%d-->",temp->ele);
            temp=temp->next;
        }
        printf("NULL\n");
    }*/

    //printf("starting with %d\n",hashtable[0].head->ele);
    ch=BFS(hashtable[0].head->ele);

    if(ch==1)
        printf("Yes\n");
    else
        printf("No\n");
}
