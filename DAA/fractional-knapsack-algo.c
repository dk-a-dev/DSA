#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    double *profit = (double *)malloc(n * sizeof(double));
    double *weight = (double *)malloc(n * sizeof(double));
    double *ratio = (double *)malloc(n * sizeof(double));
    printf("Enter the profit and weight of the items: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &profit[i], &weight[i]);
        ratio[i] = profit[i] / weight[i];
    }
    double capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%lf", &capacity);
    double total_profit = 0;
    double *x = (double *)malloc(n * sizeof(double));
    for (i = 0; i < n; i++)
    {
        x[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                double temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (weight[i] > capacity)
        {
            break;
        }
        else
        {
            x[i] = 1;
            total_profit += profit[i];
            capacity -= weight[i];
        }
    }
    if (i < n)
    {
        x[i] = capacity / weight[i];
        total_profit += x[i] * profit[i];
    }

    printf("Set of items in knapsack: {");
    for (i = 0; i < n; i++)
    {
        printf("%c", 65 + i);
        if (i < n - 1)
        {
            printf(", ");
        }
    }

    printf("}=[");
    for (i = 0; i < n; i++)
    {
        printf("%lf", x[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    
    printf("]\n");

    printf("Total value of items taken into knapsack: %lf\n", total_profit);
    return 0;
}