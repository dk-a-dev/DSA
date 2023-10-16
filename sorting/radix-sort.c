// Radix Sort
// this is a non-comparison sorting algorithm
// it sorts by grouping elements by their individual digits
// starting from the least significant digit
// and moving towards the most significant digit
// it is a stable sort

#include <stdio.h>
#include <stdlib.h>

void input(int *arr, int n)
{
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void display(int *arr, int n)
{
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void counting_sort(int *arr, int n, int pos)
{
    int *count = (int *)malloc((10) * sizeof(int));  // Create a count array to store count of individual elements
    int *output = (int *)malloc((n) * sizeof(int)); // Create a output array to store sorted elements
    int i;

    // Initialize count array with all zeros
    for (i = 0; i < 10; i++)
        count[i] = 0;

    // Store the count of each element
    for (i = 0; i < n; i++)
        count[(arr[i]/pos)%10]++;

    // Store the cummulative count of each array
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Find the index of each element of the original array in count array, and place the elements in output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i]/pos)%10] - 1] = arr[i];
        count[(arr[i]/pos)%10]--;
    }
    // Copy the sorted elements into original array
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix_sort(int* arr, int size, int max)
{
    // make use of counting_sort() to sort the array
    for(int pos = 1; max/pos > 0; pos *= 10){
        counting_sort(arr, size, pos);
    }      
}

int max(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int main(int argc, char const *argv[])
{
    int size,k;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    input(arr, size);
    k = max(arr, size);
    radix_sort(arr, size, k);
    display(arr, size);
    free(arr);
    return 0;
}
