// insertion and deletion in queue allows at both ends
// work both as stack and queue

/*
Types of DeQueue
-> Input restricted DeQueue
1. Insertion at rear end only
2. Deletion at both ends

-> Output restricted DeQueue
1. Insertion at both ends
2. Deletion at front end only

NOTE: All Operations takes Time Complexity of O(1)

Applications:
1. Undo operation in text editors
2. Implementing both stack and queue and their applications
3. Implementing Breadth First Search (BFS) in graph
4. Palindrome checking
5. Multi processor scheduling(A-star algorithm)
*/
#include <stdio.h>
#include <stdlib.h>

int isFull(int front, int rear, int size)
{
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
        return 1;
    return 0;
}

int isEmpty(int front, int rear)
{
    if (front == -1)
        return 1;
    return 0;
}

void insertFront(int *arr, int *front, int *rear, int size, int data)
{
    if (isFull(*front, *rear, size))
    {
        printf("Queue is Full\n");
        return;
    }
    if (*front == -1)
    {
        *front = *rear = 0;
    }
    else if (*front == 0)
    {
        *front = size - 1;
    }
    else
    {
        *front = *front - 1;
    }
    arr[*front] = data;
}

int deleteFront(int *arr, int *front, int *rear, int size)
{
    if (isEmpty(*front, *rear))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    int data = arr[*front];
    if (*front == *rear)
    {
        *front = *rear = -1;
    }
    else if (*front == size - 1)
    {
        *front = 0;
    }
    else
    {
        *front = *front + 1;
    }
    return data;
}

void insetRear(int *arr, int *front, int *rear, int size, int data)
{
    if (isFull(*front, *rear, size))
    {
        printf("Queue is Full\n");
        return;
    }
    if (*front == -1)
    {
        *front = *rear = 0;
    }
    else if (*rear == size - 1)
    {
        *rear = 0;
    }
    else
    {
        *rear = *rear + 1;
    }
    arr[*rear] = data;
}

int deleteRear(int *arr, int *front, int *rear, int size)
{
    if (isEmpty(*front, *rear))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    int data = arr[*rear];
    if (*front == *rear)
    {
        *front = *rear = -1;
    }
    else if (*rear == 0)
    {
        *rear = size - 1;
    }
    else
    {
        *rear = *rear - 1;
    }
    return data;
}

int display(int *arr, int front, int rear, int size)
{
    if (isEmpty(front, rear))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    printf("Queue: ");
    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    else
    {
        for (int i = front; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int size;
    printf("Enter the size of queue: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);
    int front = -1, rear = -1;
    return 0;
}