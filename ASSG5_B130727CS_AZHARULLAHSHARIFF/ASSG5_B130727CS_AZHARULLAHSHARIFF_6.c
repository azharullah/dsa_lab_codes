void prim() {
   int i, j, startVertex, endVertex;
   int k, nr[10], temp, minimumCost = 0, tree[10][3];
   int cost[100][100],n;
 
   /* For first smallest edge */
   temp = cost[0][0];
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         if (temp > cost[i][j]) {
            temp = cost[i][j];
            startVertex = i;
            endVertex = j;
         }
      }
   }
   /* Now we have fist smallest edge in graph */
   tree[0][0] = startVertex;
   tree[0][1] = endVertex;
   tree[0][2] = temp;
   minimumCost = temp;
 
   /* Now we have to find min dis of each vertex from either
    startVertex or endVertex by initialising nr[] array
    */
 
   for (i = 0; i < n; i++) {
      if (cost[i][startVertex] < cost[i][endVertex])
         nr[i] = startVertex;
      else
         nr[i] = endVertex;
   }
 
   /* To indicate visited vertex initialise nr[] for them to 100 */
   nr[startVertex] = 100;
   nr[endVertex] = 100;
 
   /* Now find out remaining n-2 edges */
   temp = 99;
   for (i = 1; i < n - 1; i++) {
      for (j = 0; j < n; j++) {
         if (nr[j] != 100 && cost[j][nr[j]] < temp) {
            temp = cost[j][nr[j]];
            k = j;
         }
      }
      /* Now i have got next vertex */
      tree[i][0] = k;
      tree[i][1] = nr[k];
      tree[i][2] = cost[k][nr[k]];
      minimumCost = minimumCost + cost[k][nr[k]];
      nr[k] = 100;
 
      /* Now find if k is nearest to any vertex
       than its previous near value */
 
      for (j = 0; j < n; j++) {
         if (nr[j] != 100 && cost[j][nr[j]] > cost[j][k])
            nr[j] = k;
      }
      temp = 99;
   }
   /* Now i have the answer, just going to print it */
   //printf("\nThe min spanning tree is:- ");
   //for (i = 0; i < n - 1; i++) {
      //for (j = 0; j < 3; j++)
         //printf("%d", tree[i][j]);
      //printf("\n");
}
 


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
   {     struct ds *nd;
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
      {  S[j] = e[i];
         j++;
         combine(retpoint(e[i].start), retpoint(e[i].end));
      }
   }
   //printf("\n SORTED:");
   for(i=0; i<j; i++)
   {  weight += S[i].weight;
      //printf("%d %d",S[i].start,S[i].end);
   }
   
   printf("WEIGHT: %d\n",weight);
   print_matrix(S, vertices);

   return 0;
}
