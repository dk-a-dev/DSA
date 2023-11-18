// Singly linked list and its operations. (2 marks)
// Creation
// Insertion at the end
// Insertion at the beginning
// Insertion at a given position
// Searching for an element
// Deletion of an element
// Displaying the contents of the list
// Reverse the list
// Concatenation of two lists

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;          // current node data
    struct node *next; // pointer to next node(address of next node)
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
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void deletele()
{
    int pos, i;
    struct node *temp, *prev;
    printf("Enter the position of the node to be deleted: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        temp = head;
        for (i = 1; i < pos; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
}

void insert_at_end()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for the new node: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void insert_at_beginning()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for the new node: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

void insert_at_position()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for the new node: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    int pos, i;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp = head;
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void search()
{
    struct node *temp;
    temp = head;
    int key, flag = 0, pos = 0;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    while (temp != NULL)
    {
        pos++;
        if (temp->data == key)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 1)
        printf("Element found at position %d\n", pos);
    else
        printf("Element not found!\n");
}

void reverse()
{
    struct node *prev, *curr, *nextnode;
    prev = NULL;
    curr = nextnode = head;
    while (nextnode != NULL)
    {
        nextnode = nextnode->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }
    head = prev;
}

void display()
{
    struct node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("\nList is empty!\n");
    }
    else
    {
        printf("\nThe list is: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    int choice;
    while (1)
    {
        printf("\n\n1. Create a linked list\n");
        printf("2. Display the contents of the list\n");
        printf("3. Insert at the end\n");
        printf("4. Insert at the beginning\n");
        printf("5. Insert at a given position\n");
        printf("6. Search for an element\n");
        printf("7. Delete an element\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            creator();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_at_end();
            break;
        case 4:
            insert_at_beginning();
            break;
        case 5:
            insert_at_position();
            break;
        case 6:
            search();
            break;
        case 7:
            deletele ();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
