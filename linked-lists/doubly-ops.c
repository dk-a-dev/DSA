// Doubly linked list and its operations. (2 marks)

// a)     Creation of linked list with numbers 2 9 10 5 6 3 1 and display the contents of the doubly linked list

// b)     Adding a number 11 to the end and display the contents of the doubly linked list

// c)     Adding a number 12 in the beginning and displaying the contents of the doubly linked list

// d)     Adding a number 14 in position 4 and displaying the contents of the doubly linked list

// e)     Searching a number 10 and displaying its position in the doubly linked list

// f)      Deleting a number 9 from the list and display the contents of the doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void create()
{
    struct node *newnode, *temp;
    int n=7, i;
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
}

void display()
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_end()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=11;
    newnode->next = NULL;
    newnode->prev = NULL;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void insert_beg()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=12;
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insert_pos()
{
    struct node *newnode, *temp;
    int pos=3, i;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=14;
    newnode->next = NULL;
    newnode->prev = NULL;
    temp = head;
    for (i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}

void search()
{
    struct node *temp;
    int key=10, pos = 0;
    temp = head;
    while (temp != NULL)
    {
        pos++;
        if (temp->data == key)
        {
            printf("Item 10 Found in position:%d\n",pos);
            return;
        }
        temp = temp->next;
    }
}

void delete(int key)
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            if (temp == head)
            {
                head = temp->next;
                temp->next->prev = NULL;
                free(temp);
                return;
            }
            else if (temp->next == NULL)
            {
                temp->prev->next = NULL;
                free(temp);
                return;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
                return;
            }
        }
        temp = temp->next;
    }
}

int main()
{
    create();
    display();
    insert_end();
    display();
    delete(11);
    insert_beg();
    display();
    insert_pos();
    display();
    search();
    delete(9);
    display();
    return 0;
}