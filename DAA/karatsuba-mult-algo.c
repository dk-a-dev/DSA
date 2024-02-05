// Divide and Conquer Algorithm
// Karatsuba Faster Integer Mutliplication Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getLength(int num)
{
    int len = 0;
    while (num > 0)
    {
        num /= 10;
        len++;
    }
    return len;
}

long int karatsuba(int x, int y)
{
    int n = max(getLength(x), getLength(y));
    if (n == 1)
    {
        return x * y;
    }
    else
    {
        long int 
    }
}

int main()
{
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    printf("Product: %d * %d = %d\n", x, y, karatsuba(x, y));
    return 0;
}