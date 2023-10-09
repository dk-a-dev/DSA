// Counting Sort
// Not a Comparison Sort
// Sort a/c to the keys
// Counting the elements having distinct key values
// Time Complexity: O(n+k) where n is the number of elements in input array and k is the range of input.
// Auxiliary Space: O(n+k)
// Best case : O(nlogn)
// max ele=O(n) // best case

#include <stdio.h>
#include <stdlib.h>

void countingSort(int *arr, int *n, int *k)
{
    int *count = (int *)malloc((*k) * sizeof(int));  // Create a count array to store count of individual elements and initialize count array as 0
    int *output = (int *)malloc((*n) * sizeof(int)); // Create a output array to store sorted elements
    int i;

    // Initialize count array with all zeros
    for (i = 0; i < *k; i++)
        count[i] = 0;

    // Store the count of each element
    for (i = 0; i < *n; i++)
        count[arr[i]]++;

    // Store the cummulative count of each array
    for (i = 1; i < *k; i++)
        count[i] += count[i - 1];

    // Find the index of each element of the original array in count array, and place the elements in output array
    for (i = *n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements into original array
    for (i = 0; i < *n; i++)
        arr[i] = output[i];
}

void printArray(int* arr, int* n)
{
    int i;
    for (i = 0; i < *n; i++)
        printf("%d ", arr[i]);
}

int max(int *arr, int *n)
{
    int max = arr[0];
    for (int i = 1; i < *n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main()
{
    int size, i, k;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    printf("Enter the elements of the array: ");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    k = max(arr, &size) + 1;
    countingSort(arr, &size, &k);
    printf("Sorted array: ");
    printArray(arr, &size);
}