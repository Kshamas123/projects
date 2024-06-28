#include<stdio.h>
#include<stdlib.h>
struct node
{
    char title[50],date[15];
    int priority;
    struct node *next;
};struct node *start=NULL;
struct node *insert(struct node *start)
{
    struct node* new=(struct node *)malloc(sizeof(struct node));
    printf("enter the title of the task,due date,and its priority\n");
    scanf("%s%s%d",new->title,new->date,&new->priority);
    new->next=NULL;
    if(start==NULL || new->priority<start->priority)
    {  new->next=start;
       start=new;
    }
    else
    {
        struct node*p=start;
        while(p->next!=NULL && p->next->priority<=new->priority)
        p=p->next;
        new->next=p->next;
        p->next=new;
    }
    return start;
}

void display(struct node *temp)
{
    if(temp==NULL)
    printf("there is no task\n");
    else
    {
        while(temp!=NULL)
        {
            printf("task= %s\t",temp->title);
            printf("due date=%s\t",temp->date);
            printf("\n");
            temp=temp->next;
        }
    }
}
void main()
{
    int choice;
    while(1)
    {
        printf("1.add a task\n2.display as per the priority\n3.delete the task with higher priority\n4.exit\n");
        printf("enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            start=insert(start);
            break;
        case 2:display(start);
            break;
        case 3:return;
        break;
        default:printf("invalid\n");
            break;
        }
    }
}
