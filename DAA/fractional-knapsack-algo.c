// fractional knapsack algorithm uing greedy method
// Time Complexity: O(nlogn)

#include <stdio.h>
#include <stdlib.h>

struct item
{
    int weight;
    int profit;
    float ratio;
    float fraction;
};

void swap(struct item *a, struct item *b)
{
    struct item temp = *a;
    *a = *b;
    *b = temp;
}

float fractionalKnapsack(struct item *arr, int n, int W)
{

    float profit = 0;
    float weight = 0;
    for (int i = 0; i < n; i++)
    {
        // sorting
        int max = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].ratio > arr[max].ratio)
            {
                max = j;
            }
        }
        swap(&arr[i], &arr[max]);
        // end of sorting

        // calculating profit
        if (weight + arr[i].weight <= W)
        {
            weight += arr[i].weight;
            profit += arr[i].profit;
            arr[i].fraction = 1;
        }
        else
        {
            int remain = W - weight;
            profit += arr[i].ratio * remain;
            weight += remain;
            arr[i].fraction = (float)remain / arr[i].weight;
        }

        printf("\n");
        printf("%d %d %d %f %f\n", i + 1, arr[i].profit, arr[i].weight, arr[i].ratio, arr[i].fraction);
    }
    return profit;
}

int main()
{
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct item *arr = (struct item *)malloc(n * sizeof(struct item));
    printf("Enter the profit and weight of each item:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &arr[i].profit, &arr[i].weight);
        arr[i].ratio = (float)arr[i].profit / arr[i].weight;
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    printf("Maximum profit: %.2f\n", fractionalKnapsack(arr, n, W));
    return 0;
}