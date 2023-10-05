// Quick Sort or Partition Exchange Sort
/*
Quick Sort is a Divide and Conquer algorithm.
It picks an element as pivot and partitions the given array around the picked pivot.
There are many different versions of quickSort that pick pivot in different ways.
1. Always pick first element as pivot. (implemented below)
2. Always pick last element as pivot.
3. Pick a random element as pivot.
4. Pick median as pivot.
*/
// The key process in quickSort is partition().
// Target of partitions is, given an array and an element x of array as pivot,
// put x at its correct position in sorted array and put all smaller elements (smaller than x) before x,
// and put all greater elements (greater than x) after x.
// All this should be done in linear time.
// Time Complexity: O(n^2) in worst case and O(nlogn) in average case.
// Space Complexity: O(1)

#include <stdio.h>
#include <stdlib.h>

void input(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = *a;
}

void quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        // partition
        int pivot = arr[low];
        int i = low, j = high;
        // i is the index of the element greater than pivot
        while (i < j)
        {
            // find the element greater than pivot
            while (arr[i] <= pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            // swap the elements
            if (i < j)
                swap(&arr[i], &arr[j]);
        }
        // swap the pivot element
        arr[low] = arr[j];
        arr[j] = pivot;
        quick_sort(arr, low, j - 1);
        quick_sort(arr, j + 1, high);
    }
}

// display the array
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main(int argc, char const *argv[])
{
    int size;
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    input(arr, size);

    quick_sort(arr, 0, size - 1);
    display(arr, size);
    return 0;
}
