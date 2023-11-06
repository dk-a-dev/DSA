#include <stdio.h>
#include <string.h>
#include <math.h>

int temp_stack[10];
char expr[10];
int top = -1;

void push(char ele)
{
    temp_stack[++top] = (int)ele;
}

int pop()
{
    return temp_stack[top--]; 
}

int operate(double oprnd_1, double oprnd_2, char oprtr)
{
    int psol;
    switch (oprtr)
    {
    case '+':
        psol = oprnd_2 + oprnd_1;
        break;
    case '-':
        psol = oprnd_2 - oprnd_1;
        break;
    case '*':
        psol = oprnd_2 * oprnd_1;
        break;
    case '/':
        psol = oprnd_2 / oprnd_1;
        break;
    default:
        break;
    }
    return psol;
}

void display()
{
    for (int k = 0; k <= top; k++)
        printf("%d", temp_stack[k]);
    printf("\n");
}

int main()
{
    scanf("%s",expr);
    int explen = strlen(expr);
    for (int i = 0; i < explen; i++)
    {
        if (expr[i] >= '0' && expr[i] <= '9')
        {
            push(expr[i] - '0'); // This is because of ASCII,0-9 num can be obtained like this and then typecasted=>('9' - '0') = (57 − 48) = 9
        }
        else
        {
            int op1 = pop();
            int op2 = pop();
            printf("%d,%d,%c\n",op1, op2, expr[i]);
            int res = operate(op1, op2, expr[i]);
            push(res);
        }
        display();
    }
    return 0;
}
