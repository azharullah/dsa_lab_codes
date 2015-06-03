#include <stdio.h>
#include <stdlib.h>

struct hash *hashtable = NULL;
int size = 0;

struct node 
{
    int ele;
    struct node *next;
};

struct hash 
{
    struct node *head;
    int count;
};

struct node * createNode(int ele) 
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->ele = ele;
    newnode->next = NULL;
    return newnode;
}

void insert();
void search();

int get_hash_value(int ele,int size)
{
    return ele%size;
}

void insert(int ele) 
{
    int hashvalue = get_hash_value(ele,size);
    struct node *newnode =  createNode(ele);
    if (!hashtable[hashvalue].head) 
    {
        hashtable[hashvalue].head = newnode;
        hashtable[hashvalue].count = 1;
        printf("%d\n",hashvalue);    
        return;
    }
    newnode->next = (hashtable[hashvalue].head);
    hashtable[hashvalue].head = newnode;
    hashtable[hashvalue].count++;
    printf("%d\n",hashvalue);
    return;
}

void search(int ele) 
{
    int hashvalue = get_hash_value(ele,size), flag = 0;
    struct node *temp;
    temp = hashtable[hashvalue].head;
    if (!temp) 
    {
        printf("%d NOT FOUND\n",hashvalue);
        return;
    }
    while (temp != NULL) 
    {
        if (temp->ele == ele) 
        {
            printf("%d FOUND \n",hashvalue);
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (!flag)
        printf("%d NOT FOUND\n",hashvalue);
    return;
}

void main() 
{
    int ch, ele;
    scanf("%d", &size);
    size = size;
    hashtable = (struct hash *)calloc(size, sizeof (struct hash));
    while (1) 
    {
        scanf("%d", &ch);
        switch (ch) 
        {
            case 0: printf("\nExiting from the program \n");
                    exit(1);
            
            case 1: scanf("%d", &ele);
                    insert(ele);
                    break;

            case 2: scanf("%d", &ele);
                    search(ele);
                    break;
                    
            default: printf("Entered option is incorrect!!\n");
                    break;
        }
    }
}