#include <stdio.h>

void main()
{
    int a[10];
    int i, j, n, pos, key, x, item;
    void display(int num_ele, int arr[]);

    // Array Creation
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    display(n, a);

    // Array Insertion
    scanf("%d", &pos);
    scanf("%d", &key);
    for (i = n - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos] = key;
    display(++n, a);

    // Array Deletion
    scanf("%d", &x);
    // determines position of ele to be deleted
    for (i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            pos = i;
            break;
        }
    }
    for (i = pos; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    display(n - 1, a);

    // Array Searching
    scanf("%d", &item);
    pos = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == item)
        {
            pos = i + 1;
            printf("Item %d Found in position:%d", item, pos);
            break;
        }
    }
    if (pos == 0)
    {
        printf("Item %d not found", item);
    }
}

// Printing Array
void display(int num_ele, int arr[])
{
    int i;
    for (i = 0; i < num_ele; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}