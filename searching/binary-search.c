#include <stdio.h>
#include <stdlib.h>

void input(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void binary_search(int *arr, int size, int key)
{
    int low = 0, high = size - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            printf("Key Element %d found in position:%d", key, mid);
            return;
        }
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    printf("Key not found\n");
}

int main()
{
    int size;
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));

    input(arr, size);

    int key;
    scanf("%d", &key);
    binary_search(arr, size, key);
    return 0;
}