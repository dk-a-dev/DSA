// Best Case: O(n)
// Worst case: O(n^2)
#include <stdio.h>
#include <stdlib.h>

void input(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int temp;
        scanf("%d", &arr[i]);
    }
}

void bubble_sort(int *arr, int size)
{
    int temp, flag = 0;
    for (int i = 0; i < size - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < size - 1 - i; j++) // to avoid unecessary comparison size-1-i
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                flag = 1; // checks for isSorted
            }
        }
        if (flag == 0)
            break;
    }
}

void display(int *arr, int size)
{
    printf("After Bubble Sort: ");
    for (int l = 0; l < size; l++)
    {
        printf("%d ", arr[l]);
    }
}

int main(int argc, char const *argv[])
{
    int size;
    scanf("%d", &size);
    int *arr = (int *)malloc(size * (sizeof(int)));
    input(arr, size);
    bubble_sort(arr, size);
    display(arr, size);
    free(arr);
    return 0;
}
