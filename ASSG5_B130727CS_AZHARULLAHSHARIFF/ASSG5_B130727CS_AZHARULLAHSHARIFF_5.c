#include <stdio.h>
#include <stdlib.h>

struct edges{
	int start,end,weight;
};

struct ds{
	int rank;
	struct ds *p;
	int key;
};

struct dslist{
	struct ds *elem;
	struct dslist *next;
};

struct dslist *first,*last;

void makeset(struct ds *);
void link(struct ds *, struct ds *);
void combine(struct ds *, struct ds *);
void insertionsort(struct edges [], int );

struct ds *find(struct ds *);
struct ds *retpoint(int );

void insertionsort(struct edges e[], int n)
{
int i,j;
struct edges key;

for(i=1; i<n; i++)
	{
	key = e[i];
	j=i-1;
	while((key.weight < e[j].weight) && j>=0)
		{
		e[j+1]=e[j];
		j--;
		}
	e[j+1]=key;
	}
}

void makeset(struct ds *x){
	x->p = x;
	x->rank = 0;
}

void link(struct ds *x, struct ds *y){
	if(x->rank > y->rank)
		{y->p = x; }
	else{ x->p = y;
		if(x->rank == y->rank)
		y->rank = y->rank +1;}
}

void combine(struct ds *x, struct ds *y){
	link(find(x), find(y));
}

struct ds *find(struct ds *x){
	if(x != x->p)
		x->p = find(x->p);
	return x->p;
}

struct ds *retpoint(int key){
	struct dslist *nd;
	nd = first;
	while((nd->elem->key != key) && (nd != NULL))
		nd = nd->next;
	if (nd != NULL)
		return nd->elem;
	else return NULL;
}

void print_matrix(struct edges S[], int vertices){
	int i, j;
	
	int matrix[vertices][vertices];

	for(i=0; i<vertices; i++){
		for(j=0; j<vertices; j++){
			matrix[i][j]=0;}}

	for(i=0; i<vertices; i++){
		for(j=0; j<vertices; j++){
			if((S[j].start == i))
				matrix[i][S[j].end] = S[j].weight;
			if((S[j].end == i))
				matrix[i][S[j].start] = S[j].weight;
			
		}
	}

	for(i=0; i<vertices; i++){
		for(j=0; j<vertices; j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");	
	}
}

int main()
{
	int edges;
	int vertices;
	int i=0, j=0, weight = 0, v1, v2, w;
	scanf("%d%d",&vertices,&edges);
	struct dslist v[vertices];
	struct edges e[edges];
	struct edges S[edges];
	int temp = edges;	
	while(edges){
	--edges;
	scanf("%d%d%d",&v1,&v2,&w);
	e[i].start = v1;
	e[i].end = v2;
	e[i].weight = w;
	i++;
	}
	
	first = NULL;
	last = NULL;
	struct dslist *node;
	node = first;
	for(i=0; i<vertices;  i++)
	{		struct ds *nd;
			nd = (struct ds *) malloc (sizeof (struct ds));
			nd->key = i;
			nd->p = NULL;
			nd->rank = 0;

			struct dslist *ndstr;
			ndstr = (struct dslist *) malloc (sizeof (struct dslist));
			ndstr->elem = nd;
			ndstr->next = NULL;
			if(first == NULL)
				{first = ndstr;
				first->next = NULL;
				last = first;}
			else{
				last->next = ndstr;
				last = ndstr;		
			}
			makeset(nd);
		};
	
	insertionsort(e, temp);
	for(i=0;i<temp; i++)
	{
		if((find(retpoint(e[i].start)))->key != (find(retpoint(e[i].end)))->key)
		{	S[j] = e[i];
			j++;
			combine(retpoint(e[i].start), retpoint(e[i].end));
		}
	}
	//printf("\n SORTED:");
	for(i=0; i<j; i++)
	{	weight += S[i].weight;
		//printf("%d %d",S[i].start,S[i].end);
	}
	
	printf("WEIGHT: %d\n",weight);
	print_matrix(S, vertices);

	return 0;
}
