// BST implementation- Construct binary search tree and perform the following operations.
// Read the number of elements and the elements. Perform addition, deletion and perform pre-order, in-order and post-order traversals.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *root = NULL;

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node *insertBST(struct node *root, int data)
{
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insertBST(root->left, data);
    else if (data > root->data)
        root->right = insertBST(root->right, data);
    return root;
}

struct node *findMin(struct node *root)
{
    if (root == NULL)
        return NULL;
    else if (root->left != NULL)
        return findMin(root->left);
    return root;
}

struct node *deleteBST(struct node *root, int data)
{
    if (root == NULL)
        return NULL;
    else if (data < root->data)
        root->left = deleteBST(root->left, data);
    else if (data > root->data)
        root->right = deleteBST(root->right, data);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct node *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            struct node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteBST(root->right, temp->data);
        }
    }
    return root;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    int size;
    scanf("%d", &size);
    int ele;
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &ele);
        root = insertBST(root, ele);
    }
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    deleteBST(root, 6);
    inorder(root);
    printf("\n");
    insertBST(root, 8);
    inorder(root);
    printf("\n");
    deleteBST(root, 5);
    inorder(root);
    return 0;
}