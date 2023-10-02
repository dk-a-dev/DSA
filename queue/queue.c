#include <stdio.h>
#include <stdbool.h>

int size;
int arr_queue[10];
int front = -1, rear = -1;
bool flag;

void enqueue()
{
    int ele;
    if (flag)
    {
        scanf("%d", &ele);
        arr_queue[++rear] = ele;
    }
    if (front == -1)
        front = 0;
}

void dequeue()
{
    if (!flag)
    {
        ++front;
    }
}

void isEmpty()
{
    if (front == -1 || front >= rear)
    {
        printf("Queue empty");
        flag = true;
        return;
    }
}

void isFull()
{
    if (rear == size - 1)
    {
        flag = false;
        printf("Queue full\n");
    }
}

void display()
{
    for (int k = front; k <= rear; k++)
    {
        printf("%d ", arr_queue[k]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    // Checking is queue is empty
    isEmpty();
    // Taking Inputs of queue size and elements
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        isFull();
        enqueue();
    }
    // displaying stack
    display();
    // Checking is queue is full
    isFull();
    // Dequeuing from queue and displaying
    for (int j = front; j < rear; j++)
    {
        isEmpty();
        dequeue();
        display();
    }
    isEmpty();
    return 0;
}
