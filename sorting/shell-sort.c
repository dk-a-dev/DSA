// Shell Sort
// in this algorithm we use insertion sort to sort the sub arrays
// the sub arrays are created by dividing the array into smaller arrays
// gap sequence is used to create the sub arrays
// the gap sequence is created by dividing the array size by 2

#include <stdio.h>
#include <stdlib.h>

void input(int *arr, int size)
{
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void display(int *arr, int size)
{
    printf("The sorted array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void shell_sort(int *arr, int size)
{
    int gap, i, j, temp;
    for (gap = size / 2; gap >= 1; gap /= 2)
    {
        for (j = gap; j < size; j++)
        {
            for (i = j - gap; i >= 0; i -= gap)
            {
                if (arr[i + gap] > arr[i])
                    break;
                else
                {
                    temp = arr[i + gap];
                    arr[i + gap] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    input(arr, size);
    shell_sort(arr, size);
    display(arr, size);
    return 0;
}
