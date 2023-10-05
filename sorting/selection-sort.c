// Selection Sort
// we consider a sorted array and an unsorted array.
// We find the smallest element in the unsorted array and swap it with the first element of the unsorted array.
// We repeat this process until the unsorted array becomes empty.
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Best Case = Worst Case = O(n^2)

#include <stdio.h>
#include <stdlib.h>

void input(int *arr, int size)
{
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = *a;
}

void selectionSort(int *arr, int size)
{
    int min, temp;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i; j < size; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i) // optimization
            swap(&arr[i], &arr[min]);
    }
}

int main(int argc, char const *argv[])
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    input(arr, size);
    return 0;
}
