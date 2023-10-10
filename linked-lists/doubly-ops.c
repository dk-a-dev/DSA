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
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for node:");
    scanf("%d", &newnode->data); // or *(newnode).data
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
            delete ();
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
