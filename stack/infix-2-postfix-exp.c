#include <stdio.h>

#define max 100
char stack[max];
int top = -1;

void push(char e)
{
    stack[++top] = e;
}

char pop()
{
    return stack[top--];
}

int isoperator(char e)
{
    if (e == '+' || e == '-' || e == '/' || e == '*' || e == '^')
    {
        return 1;
    }
    return 0;
}

int precedence(char e)
{
    if (e == '^')
    {
        return 3;
    }
    else if (e == '/' || e == '*')
    {
        return 2;
    }
    else if (e == '+' || e == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char infix[max], postfix[max];
    int i = 0, j = 0;

    scanf("%s", infix);

    while (infix[i] != '\0')
    {
        if (isoperator(infix[i]))
        {
            if (stack[top] != '^' && infix[i] != '^')
            {
                while (precedence(stack[top]) >= precedence(infix[i]) && top != -1)
                {
                    postfix[j++] = pop();
                }
            }
            push(infix[i]);
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (stack[top] != '(' && top != -1)
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else
        {
            postfix[j++] = infix[i];
        }
        i++;
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    for (int k = 0; postfix[k] != '\0'; k++)
    {
        printf("%c ", postfix[k]);
    }

    return 0;
}