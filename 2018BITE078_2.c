#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct SingleLL 
{
    int data;
    struct SingleLL *next;
}*start=NULL;
struct SingleLL* addnode(struct SingleLL *start,int data)
{
    struct SingleLL *newnode=(struct SingleLL*)malloc(sizeof(struct SingleLL));
    newnode->data=data;
    struct SingleLL *a=start;
    if(start==NULL)
    {
        start=newnode;
        return start;
    }
    while(a->next!=NULL)
    {
        a=a->next;
    }
    a->next=newnode;
    return start;
}
void display(struct SingleLL *start)
{
    while(start!=NULL)
    {
        printf("%d  ",start->data);
        start=start->next;
    }
}
struct SingleLL* delete(struct SingleLL *start)
{
    struct SingleLL *a=start;
    struct SingleLL *prev=NULL;
    if(start==NULL)
    {
        return NULL;
    }
    while(start->next==NULL)
    {
        free(start);
        return NULL;
    }
    while(a->next->next!=NULL)
    {
        a=a->next;
    }
    printf("Deleted node is %d",a->next->data);
    free(a->next);
    a->next=NULL;
    return start;
}
int count(struct SingleLL* start)
{
    int count=0;
    while(start!=NULL)
    {
        count++;
        start=start->next;
    }
    return count;
}
struct SingleLL* Search(struct SingleLL *start,int p)
{
    struct SingleLL* a=start;
    if(p==1)
    {
        return start;
    }
    for(int i=1;i<p;i++)
    {
        a=a->next;
    }
    return a;
}

int main()
{
    struct SingleLL *start=NULL;
    int choice=1;
    while(choice)
    {
        printf("Enter the choice:- \n");
        printf("1.add ");
        printf("2.display ");
        printf("3.delete ");
        printf("4.search ");
        printf("5.add_pos ");
        printf("6.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                int data;
                scanf("%d",&data);
                start=addnode(start,data);
                break;
            }
            case 2:
            {
                display(start);
                printf("\n");
                break;
            }
            case 3:
            {
                start=delete(start);
                printf("\n");
                break;
            }
            case 4:
            {
                int position;
                printf("Enter the search node position ");
                scanf("%d",&position);
                struct SingleLL* x=Search(start,position);
                printf("%d \n",x->data);
                break;
            }
            case 5:
            {
                int position,key;
                printf("Enter the position and key");
                //scanf("%d %d",&position,&key);
                //start=add_pos(&start,position,key);
                break;   
            }
            case 6:
            {
                exit(0);
                break;
            }
        }
    }
} 