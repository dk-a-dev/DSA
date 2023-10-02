// Singly linked list and its operations. (2 marks)

// a)     Creation of linked list with numbers 2 9 10 5 6 3 1 and display the contents of the singly linked list

// b)     Adding a number 11 to the end and display the contents of the singly linked list

// c)     Adding a number 12 in the beginning and displaying the contents of the singly linked list

// d)     Adding a number 14 in position 4 and displaying the contents of the singly linked list

// e)     Searching a number 10 and displaying its position in the singly linked list

// f)      Deleting a number 9 from the list and display the contents of the singly linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create()
{
    struct node *newnode, *temp;
    int n=7;
    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
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

void add_end()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=11;
    newnode->next = NULL;
    temp = head;
    // Traversing to the last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void add_beg()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=12;
    newnode->next = head;
    head = newnode;
}

void add_pos()
{
    // Adding a number 14 in position 4
    struct node *newnode, *temp;
    int pos=3;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=14;
    newnode->next = NULL;
    temp = head;
    // Traversing to the node before the position
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void search()
{
    struct node *temp;
    int pos = 0;
    temp = head;
    while (temp != NULL)
    {
        pos++;
        // Searching a number 10
        if (temp->data == 10)
        {
            printf("Item 10 Found in position:%d\n",pos);
            return;
        }
        temp = temp->next;
    }
}

void delete(int data)
{
    struct node *temp, *prev;
    temp = head;
    while (temp != NULL)
    {
        // Deleting a number 9
        if (temp->data == data)
        {
            if (temp == head)
            {
                head = temp->next;
                free(temp);
                return;
            }
            else
            {
                prev->next = temp->next;
                free(temp);
                return;
            }
        }
        prev = temp;
        temp = temp->next;
    }
}

int main()
{

    create();
    display();
    add_end();
    display();
    delete(11);
    add_beg();
    display();
    add_pos();
    display();
    search();
    delete(9);
    display();
    return 0;
}