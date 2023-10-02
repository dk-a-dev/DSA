#include <stdio.h>
#include <stdlib.h>

void input(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
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
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
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
