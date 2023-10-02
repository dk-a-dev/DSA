#include <stdio.h>
#include <stdbool.h>

int size;
int top = -1;
int book_stack[5];
bool flag;

void push_book()
{
    if (flag)
    {
        return;
    }
    else
    {
        int book_id;
        scanf("%d", &book_id);
        book_stack[++top] = book_id;
        return;
    }
}

void pop_book()
{
    if (flag)
    {
        return;
    }
    else
    {
        book_stack[top--];
    }
}

void isFull()
{
    if (top == size - 1)
    {
        printf("Stack full\n");
        flag = true;
    }
    else
    {
        flag = false;
    }
}

void isEmpty()
{
    if (top == -1)
    {
        printf("Stack empty");
        flag = true;
    }
    else
    {
        flag = false;
    }
}

void display()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", book_stack[i]);
    }
    top == -1 ? printf("") : printf("\n");
}

int main(int argc, char const *argv[])
{
    isEmpty();
    // Input of number of books
    scanf("%d", &size);
    // Input of book ids and calling push function
    for (int i = 0; i < size; i++)
    {
        isFull();
        push_book();
    }
    // displaying stack
    display();
    // checking if stack is full
    isFull();
    // issuing books using pop function
    for (int j = 0; j <= size; j++)
    {
        isEmpty();
        pop_book();
        display();
    }
    return 0;
}