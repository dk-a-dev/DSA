// Doubly linked list and its operations
// Creation
// Insertion
// Deletion
// Displaying the contents of the list
// Reverse the list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;          // current node data
    struct node *next; // pointer to next node(address of next node)
    struct node *prev; // pointer to previous node(address of previous node)
};

struct node *head = NULL; // pointer to head node(address of head node)

void creator()
{
    int n, i;
    struct node *temp, *newnode;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
}

void deletele ()
{
    struct node *temp;
    int pos, i = 1;
    printf("Enter the position to delete the node: ");
    scanf("%d", &pos);
    if (head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void insert_begin()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for node:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode->next;
        head = newnode;
    }
}

void insert_end()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for node:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void insert_pos()
{
    struct node *newnode, *temp;
    int pos, i = 1;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for node:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    printf("Enter the position to insert the node: ");
    scanf("%d", &pos);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode->next;
        temp->next = newnode;
    }
}



void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

void reverse()
{
    struct node *temp, *prevnode;
    if (head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            prevnode = temp->prev;
            temp->prev = temp->next;
            temp->next = prevnode;
            temp = temp->prev;
        }
        if (prevnode != NULL)
        {
            head = prevnode->prev;
        }
    }
}

int main(int argc, char const *argv[])
{
    int choice;
    while (1)
    {
        printf("\n\n1. Create a doubly linked list\n");
        printf("2. Insert a node at the beginning\n");
        printf("3. Insert a node at the end\n");
        printf("4. Insert a node at a given position\n");
        printf("5. Delete a node from a given position\n");
        printf("6. Display the contents of the list\n");
        printf("7. Reverse the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            creator();
            break;
        case 2:
            insert_begin();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            insert_pos();
            break;
        case 5:
            deletele ();
            break;
        case 6:
            display();
            break;
        case 7:
            reverse();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice!\n");
            break;
        }
    }

    return 0;
}
