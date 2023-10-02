#include <stdio.h>
#include <stdlib.h>

struct node
{
    int pow;
    int coeff;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *head3 = NULL;

void create(struct node **head)
{
    struct node *newnode, *temp;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d %d", &newnode->pow, &newnode->coeff);
        newnode->next = NULL;
        if (*head == NULL)
        {
            *head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void display(struct node *head)
{
    // output
    /*
    10 3
    11 2
    3 1
    */
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d %d\n", temp->pow, temp->coeff);
        temp = temp->next;
    }
}

void add_poly()
{
    struct node *temp1, *temp2, *temp3, *newnode;
    temp1 = head1;
    temp2 = head2;
    // while both of the lists have elements
    while (temp1 != NULL && temp2 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        // if power of 1st list is greater than 2nd list
        if (temp1->pow > temp2->pow)
        {
            newnode->coeff = temp1->coeff;
            newnode->pow = temp1->pow;
            temp1 = temp1->next;
        }
        // if power of 2nd list is greater than 1st list
        else if (temp1->pow < temp2->pow)
        {
            newnode->coeff = temp2->coeff;
            newnode->pow = temp2->pow;
            temp2 = temp2->next;
        }
        // if power of both the lists are equal
        else
        {
            newnode->coeff = temp1->coeff + temp2->coeff;
            newnode->pow = temp1->pow;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        // if head3 is empty
        if (head3 == NULL)
        {
            head3 = newnode;
            temp3 = newnode;
        }
        // if head3 is not empty
        else
        {
            temp3->next = newnode;
            temp3 = newnode;
        }
    }
    // if one of the list is empty
    // then copy the remaining elements of the other list
    while (temp1 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->coeff = temp1->coeff;
        newnode->pow = temp1->pow;
        newnode->next = NULL;
        temp1 = temp1->next;
        temp3->next = newnode;
        temp3 = newnode;
    }
    // if one of the list is empty
    // then copy the remaining elements of the other list
    while (temp2 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->coeff = temp2->coeff;
        newnode->pow = temp2->pow;
        newnode->next = NULL;
        temp2 = temp2->next;
        temp3->next = newnode;
        temp3 = newnode;
    }
}

int main()
{
    create(&head1);
    create(&head2);
    add_poly();
    display(head3);
    return 0;
}
