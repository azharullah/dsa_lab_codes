#include<stdio.h>
#include<stdlib.h>
 typedef struct node 
 {
    int eno;
    struct node *down;
    struct node *next;
 } node;
    
 struct node *first,*temp,*ptr1,*ptr2;    

node* combine( node* nd1, node* nd2 )
{
    if (nd1 == NULL)
        return nd2;
    if (nd2 == NULL)
        return nd1;
    node* result;
    if( nd1->eno < nd2->eno )
    {
        result = nd1;
        result->down = combine( nd1->down, nd2 );
    }
    else
    {
        result = nd2;
        result->down = combine( nd1, nd2->down );
    }
    return result;
}
 
node* flatten (node* first)
{
    if ( first == NULL || first->next == NULL )
        {
          return first;
        }
    return combine( first, flatten(first->next) );
}
   
void display (node *first)
{
    while(first!= NULL)
    {
        printf("%d", first->eno);
        printf("-->");
        first = first->down;
    }
    printf("NULL \n");
}
   
int main()
{
  int cnt=0,i,a[1000],j=0;
  char ch;
  first=(struct node*)malloc(sizeof(struct node*));
  first->next=NULL;
  first->down=NULL;
  temp=(struct node*)malloc(sizeof(struct node*));
  temp=first;
  
  while(1)
  {
    cnt++;
    scanf("%d",&temp->eno);
    a[j]=temp->eno;
    j++;
    scanf("%c",&ch);
    if(ch=='\n')
    {
       temp->next=NULL;
       break;
    } 
    temp->next=(struct node*)malloc(sizeof(struct node*));
    temp=temp->next; 
  }
  
    ptr1=(struct node*)malloc(sizeof(struct node*));
        ptr1->next=NULL;
        ptr1->down=NULL;
    ptr2=(struct node*)malloc(sizeof(struct node*));
        ptr2->next=NULL;
        ptr2->down=NULL;
        ptr1=first;

 for(i=0;i<cnt;i++)
  {
    ptr2=ptr1;
    while(1)
     {
       scanf("%d",&ptr2->eno);
       a[j]=ptr2->eno;
	j++;
       scanf("%c",&ch);
       if(ch=='\n')
       {
         
        ptr2->down=NULL;
        break;
       }
       ptr2->down=(struct node*)malloc(sizeof(struct node*));
       ptr2=ptr2->down; 
     }
       ptr1->next=(struct node*)malloc(sizeof(struct node*));
       ptr1=ptr1->next;
  }

    for(i=0;i<j;i++)
	{
		if(a[i]<0)
			{
				printf("\nElements entered are invalid\n");
				exit(1);
			}
	}

    first = flatten(first);

    first=first->down;
    display (first);


    return 0;

}    
