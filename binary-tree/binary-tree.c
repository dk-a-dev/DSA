#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root){
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void inorder(struct node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


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
    printf("Preorder traversal of binary tree is:");
    preorder(root);
    printf("\n");
    printf("Preorder traversal of binary tree is:");
    postorder(root);
    printf("\n");
    printf("Preorder traversal of binary tree is:");
    inorder(root);
    printf("\n");
    return 0;
}
