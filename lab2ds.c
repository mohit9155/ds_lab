#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node
{
    char name[100];
    int type;
    char status[100];
    struct node *next;
};
struct node *head = NULL;
void view_admins()
{
    struct node *p;
    p = head;
    if (p == NULL)
        printf("so far no admin Available!\n");
    else
    {
        while (p != NULL)
        {
            if (p->type == 1)
                puts(p->name);
            p = p->next;
        }
    }
}
void view_all_users()
{

    struct node *p;
    p = head;
    if (p == NULL)
        printf("so far there is no user Available!!\n");
    else
    {
        while (p != NULL)
        {
            puts(p->name);
            printf("\t");
            if (p->type == 1)
                printf("Admin");
            printf("\t");
            puts(p->status);
            p = p->next;
        }
    }
}
void view_count()
{
    char s[] = {'a', 'v', 'a', 'i', 'l', 'a', 'b', 'l', 'e', '\0'};
    int c = 0;
    struct node *p;
    p = head;
    if (p == NULL)
        printf("List is empty!\n");
    else
    {
        while (p != NULL)
        {
            if (strcmp(strlwr(p->status), s) == 0)
                c++;
            p = p->next;
        }
        printf("Count of users with status:available,is %d\n", c);
    }
}
void insert()
{
    struct node *p, *q, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter your name:");
    gets(temp->name);
    printf("Press 1 to make admin. Else press 0:");
    scanf("%d", &temp->type);
    fflush(stdin);
    printf("Enter status:");
    gets(temp->status);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        p = head;
        q = p->next;
        while (q != NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = temp;
        temp->next = NULL;
    }
}
void delete ()
{
    char n[100];
    struct node *p, *q;
    printf("Enter the name of the member you want to remove:");
    gets(n);
 
    printf("\n");
    if (head == NULL)
        printf("List is empty!\n");
    else if (strcmp(n, head->name) == 0)
    {
        
        printf("%s has been removed.\n", head->name);
        head = head->next;
    }
    else
    {
        p = head;
        q = p->next;
        while (strcmp(strlwr(n), strlwr(q->name)) != 0)
        {
            p = p->next;
            q = q->next;
        }

        printf("%s has been removed.\n", q->name);
        p->next = q->next;
    }
}
void display()
{
    int ch, c = 1;
    while (c != 0)
    {
        printf("\t---Display Menu---");
        printf("\n1.View Admins only\n2.View All users\n3.View total number of users\n");
        printf("Enter Your Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            view_admins();
            break;
        case 2:
            view_all_users();
            break;
        case 3:
            view_count();
            break;
        default:
            printf("Invalid choice!\n");
        }
        printf("Do you want to continue?Press 1-Yes or 0-No:");
        scanf("%d", &c);
    }
}
int main()
{
    int ch, c = 1;
    while (c != 0)
    {
        printf("\t---MAIN MENU---\n");
        printf("1. Insert \n2.Delete \n3.Display");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        //printf("hi");
        fflush(stdin);
        switch (ch)
        {
        case 1: //printf("hi");
            insert();

            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        }
        printf("Go back to Main Menu?Press 1-Yes or 0-No:");
        scanf("%d", &c);
        if (c == 0)
        {
            printf("Thank you for usin the program :)");
        }
        printf("\n");
    }
}
