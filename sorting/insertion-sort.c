// Given array is divided into two parts
// Sorted and Unsorted Sublists
// Initially sorted sublist contains only one element at index 0
// Unsorted sublist contains rest of the elements
// We pic j an element from unsorted sublist and insert it into sorted sublist
// We repeat this process until unsorted sublist is empty
// Space Complexity: O(1)
// Best Case: O(n)
// Worst Case: O(n^2)(descending order)

#include <stdio.h>
#include <stdlib.h>

void input(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

void insertion_sort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp=arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main(int argc, char const *argv[])
{
    int size;
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    input(arr, size);
    insertion_sort(arr, size);
    display(arr, size);
    free(arr);
    return 0;
}
