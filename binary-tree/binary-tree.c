#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *createNode()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }
    newNode->data = x;
    printf("Enter left child of %d:\n", x);
    newNode->left = createNode();
    printf("Enter right child of %d:\n", x);
    newNode->right = createNode();
    return newNode;
}

int main(int argc, char const *argv[])
{
    struct node *root = createNode();
    return 0;
}
