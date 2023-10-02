#include <stdio.h>
#include <stdlib.h>

void input(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void merge(int *arr, int low, int mid, int high)
{
    // merge the two sorted arrays
    int i = low, j = mid + 1, k = low;
    int* temp=(int*)malloc((high+1)*sizeof(int));
    // copy the elements to the temporary array
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    // copy the remaining elements
    while (i <= mid)
        temp[k++] = arr[i++];
    // copy the remaining elements
    while (j <= high)
        temp[k++] = arr[j++];
    // copy the elements back to the original array
    for (int i = low; i <= high; i++)
        arr[i] = temp[i];
}

void merge_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        // divide
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        // conquer
        merge(arr, low, mid, high);
    }
}


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

    merge_sort(arr, 0, size - 1);
    display(arr, size);
    return 0;
}
