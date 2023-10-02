// we can use circular queue to avoid the waste of space

#include <stdio.h>
#include <stdlib.h>

int isFull(int *queue, int *front, int *rear, int size)
{
    if ((*rear + 1) % size == *front)
    {
        printf("Queue is full\n");
        return 1;
    }
    else
        return 0;
}

int isEmpty(int *queue, int *front, int *rear, int size)
{
    if (*front == -1 && *rear == -1)
    {
        printf("Queue is empty\n");
        return 1;
    }
    else
        return 0;
}

void enqueue(int *queue, int *front, int *rear, int size, int data)
{
    if (isFull(queue, front, rear, size))
        return;
    else if (isEmpty(queue, front, rear, size))
        *front = *rear = 0;
    else
        *rear = (*rear + 1) % size;
    queue[*rear] = data;
}

void dequeue(int *queue, int *front, int *rear, int size)
{
    if (isEmpty(queue, front, rear, size))
        return;
    else if (*front == *rear)
        *front = *rear = -1;
    else
    {
        printf("Deleted element is %d\n", queue[*front]);
        *front = (*front + 1) % size;
    }
}

void display(int *queue, int *front, int *rear, int size)
{
    if (isEmpty(queue, front, rear, size))
        return;
    else
    {
        int i = *front;
        while (i != *rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % size;
        }
        printf("%d\n", queue[i]);
    }
}

int main(int argc, char const *argv[])
{
    int size;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    int *queue = (int *)malloc(size * sizeof(int));
    int front = -1, rear = -1;
    return 0;
}
