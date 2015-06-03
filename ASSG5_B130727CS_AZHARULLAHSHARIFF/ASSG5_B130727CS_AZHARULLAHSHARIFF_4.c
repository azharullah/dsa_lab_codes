#include <stdio.h>
#include <stdlib.h>
#define max 100
#define infinite 1000

int vert;

struct dijk
{
	struct dijk *p;
	int vn;
	int d;
	struct dijk *next; 
	int cost;
	int es;
};

int temp; 

void movb(struct dijk a[], int p, int q){
	int i;
	for(i=p-1; i<temp-2; i++)
		a[i] = a[i+1];}

struct dijk extractmin(struct dijk a[]){
	int i=0;
	while(a[i].es != 0 )
		i++;
	int small = i;
	i=0;x
	while((i<temp))
	{	if((a[i].es != 1) && (a[i].d<a[small].d))
			small = i;
		i++;}
	a[small].es = 1;
	return a[small];
}

int queuenotempty(struct dijk a[]){
	int i=0;
	for(i=0;i<temp;i++)
		if(a[i].es == 0) return 1;
	return 0;
}
int w(struct dijk g[], int u, int v)
{
	struct dijk *nd;
	nd = g[u].next;
	while((nd->vn != v) && (nd != NULL))
		nd = nd->next;
	return (nd->cost);
	

}
void relax(struct dijk g[], int u, int v){
	if(g[v].d > g[u].d + w(g,u,v))
	{
		g[v].d = g[u].d + w(g, u, v);	
		g[v].p = &g[u];
	}
}

void dijkstra(struct dijk g[], int S[], int s){
	struct dijk u, *v, *nd, *x;
	int i=0, j, k;
	g[s].p = NULL;
	g[s].d = 0;
	while(queuenotempty(g)){
		u = extractmin(g);
		S[i] = u.vn;
		i++;
		v = u.next;
		while(v != NULL){
			relax(g, u.vn, v->vn);
			v = v->next;
		}
		S[i-1]=g[i].d;
	}
}


int main()
{
	int ver1, ver2, i;
	int strtver, cost, edges;
	scanf("%d%d",&vert,&edges);
	int S[vert];
	temp = vert;
	struct dijk a[vert];
	for(i=0; i<vert; i++)
	{
		a[i].vn = i;
		a[i].p = NULL;
		a[i].d = infinite;
		a[i].cost = infinite;
		a[i].next = NULL;
		a[i].es = 0;
	}
	struct dijk *node1, *nd1, *nd;
	struct dijk *node2, *nd2;
	//inp>>edges;	
	while(edges){
		--edges;		
		scanf("%d%d%d",&ver1,&ver2,&cost);
		/*inp>>ver1;
		inp>>ver2;
		inp>>cost;*/
		node1 =(struct dijk *) malloc (sizeof(struct dijk));
		nd1 = a[ver1].next;
		node1->vn = ver2;
		node1->p = NULL;
		node1->cost = cost;
		node1->d = infinite;
		node1->next = NULL;

		if(nd1 == NULL)
			a[ver1].next = node1;
		else{
			while(nd1->next != NULL)
				nd1 = nd1->next;
			nd1->next = node1;
		}
	}	
	
	for(i=0; i<vert; i++)
	{
		printf("%d,%d -- ",a[i].vn,a[i].cost);
		//cout<< a[i].vn<< ", "<<a[i].cost<<"   --   ";
		nd = a[i].next;
		while(nd != NULL)
		{
			printf("%d,%d ",nd->vn,nd->cost);
			nd= nd->next;
		}
		printf("\n");
	}
	
	//cout<<endl<<"enter start vertex:";
	scanf("%d",&strtver);
 	dijkstra(a, S, strtver);
	
	printf("\n");
	for(i=0;i<vert;i++)
	printf("%d ",S[i]);
	return 0;
}
