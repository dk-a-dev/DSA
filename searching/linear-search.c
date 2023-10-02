#include <stdio.h>
#include <stdlib.h>

void input(int *arr,int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void linear_search(int *arr, int size, int key)
{
    int i;
    for (i = 0; i < size; i++)
        if (arr[i] == key)
        {
            printf("Element %d found in position:%d", key, i);
            break;
        }
    if (i == size)
        printf("Key not found\n");
}

int main(int argc, char const *argv[])
{
    int size;
    scanf("%d", &size);
    int *arr=(int *)malloc(size * sizeof(int));

    input(arr,size);

    int key;
    scanf("%d", &key);

    linear_search(arr, size, key);
    return 0;
}
