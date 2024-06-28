#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
    char bookname[25];
    int total;
    int tot_res;
    struct node *next;
    struct node *prev;
};
struct node *start = NULL;
void create()
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    printf("enter the book name\n");
    scanf("%s", new->bookname);
    printf("enter the number of copies of books\n");
    scanf("%d", &new->total);
    new->tot_res = 0;
    new->next = NULL;
    new->prev = NULL;
    if (start == NULL)
    {
        start = new;
    }
    else
    {
        struct node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
    }
}
void select_book()
{
    char book_name[25];
    printf("enter the book name that you want to take\n");
    scanf("%s",book_name);
    printf("%s",book_name);
    struct node * temp = start;
    while(temp!=NULL)
    {
        if(!(strcmp(temp->bookname,book_name)) && temp->tot_res!=temp->total)
        {
            temp->tot_res++;
            return;
        }
        temp=temp->next;
    }
    printf("book not available\n");
   
}
void return_book()
{
    char book_name[25];
    printf("enter the book name that you want to return\n");
    scanf("%s",book_name);
    struct node *temp = start;
    while (temp!=NULL)
    {
        if (!(strcmp(temp->bookname,book_name)))
        {
            temp->tot_res--;
            printf("you have rturned the book\n");
            return;
        }
    }
}
void display()
{
    printf("books that we have along with the no.of copies are displayed as below\n");
    struct node *temp = start;
     printf("-------------------------------------------------------------\n");
    while (temp!=NULL)
    {
        printf("book name:%s\n", temp->bookname);
        printf("total no of copies:%d\n", temp->total);
        printf("total no.of copies curently available:%d\n", (temp->total - temp->tot_res));
        printf("-------------------------------------------------------------\n");
        temp = temp->next;
    }
}
void main()
{
    int choice,n;
    printf("***********************************\n");
    printf("welcome to library\n");
    printf("***********************************\n");
    while(1)
    {
        printf("MENU\n1->CREATE\n2->ISSUE\n3->RETURN\n4->DISPLAY\n5->EXIT\n");
        printf("enter the choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("enter the number of book you wnat to enter\n");
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            create();
            break;
        case 2:
            select_book();
            break;
        case 3:
            return_book();
            break;
        case 4:
            display();
            break;
        case 5:
            return;
            break;
        default:printf("invalid choice.TRY AGAIN\n");
            break;
        }
    }
}