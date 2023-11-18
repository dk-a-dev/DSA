// convert postorder expression: 23*42/+6- to expression tree

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
} node;

typedef struct stack
{
    node *data;
    struct stack *next;
} stack;

node *createNode(char data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isEmpty(stack *top)
{
    return top == NULL;
}

void push(stack **top, node *data)
{
    stack *newNode = (stack *)malloc(sizeof(stack));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

node *pop(stack **top)
{
    if (isEmpty(*top))
    {
        printf("Stack underflow\n");
        return NULL;
    }
    stack *temp = *top;
    node *data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

void printTree(node *root)
{
    if (root != NULL)
    {
        printTree(root->left);
        printf("%c ", root->data);
        printTree(root->right);
    }
}

node *createExpressionTree(char *postfix)
{
    stack *s = NULL;
    node *t, *t1, *t2;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            t = createNode(postfix[i]);
            push(&s, t);
        }
        else
        {
            t = createNode(postfix[i]);
            t1 = pop(&s);
            t2 = pop(&s);
            t->right = t1;
            t->left = t2;
            push(&s, t);
        }
    }
    return pop(&s);
}

int main()
{
    char postfix[] = "23*42/+6-";
    node *root = createExpressionTree(postfix);
    printTree(root);
    printf("\n");
    return 0;
}