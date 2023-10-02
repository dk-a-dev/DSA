#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 10

int st[10];
int top = -1;
int k = -1;
char s[20];
char ot[20];

int main()
{
    bool Isempty();
    void push(char);
    char pop();
    bool Isfull();
    int precedence(char);
    void display();
    void output();
    int i = 0, n, p1, p2;
    char t;
    printf("Enter a string ", NULL);
    scanf("%s", s);
    printf("U entered %s Length : %d\n", s, strlen(s));
    printf("Itrn\t\tCr.exp\t\tStack\t\tOutput\t\ttop,k\n",NULL);
    while (s[i] != '\0')
    {
        printf("%d\t\t", i);
        printf("%c\t\t", s[i]);
        if (isdigit(s[i])) // if char is digit add it to output
        {
            ot[++k] = s[i];
        }
        else if (s[i] == ')') // If char is ) pop everything till u reach (. Add everything except ( to output.
        {
            t = pop();
            if (t != '(')
            {
                ot[++k] = t;
            }
        }
        else // Isoperator is true. Can be all operators including (
        {
            if (s[i] == '(' && s[i - 1] == '(')
            {
                push(s[i]);
            }
            else if (s[i] == '(' && s[i - 1] != '(')
            {
                push(s[i]);
            }
            else
            {
                while (!Isempty())
                {
                    t = pop();
                    p1 = precedence(s[i]);
                    p2 = precedence(t);
                    if (p2 >= p1)
                    {
                        ot[++k] = t;
                    }
                    else
                    {
                        push(t);
                        break;
                    }
                }
                push(s[i]);
            }
        }
        // end of else
        i++;
        display();
        output();
        printf("%d,%d\n", top, k);
    } // while end
    char temp;
    while (!Isempty())
    {
        temp = pop();
        if (temp != '(')
            ot[++k] = temp;
            printf("%d\t\t", i);
            printf("%c\t\t", temp);
            display();
            output();
            printf("%d,%d\n", top, k);
            i++;
    }
    printf("\n",NULL);
    ot[++k] = '\0';
    printf("\n%s", ot);
    return 0;
}

bool Isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

bool Isfull()
{
    if (top == SIZE - 1)
        return 1;
    else
        return 0;
}

void push(char x)
{
    if (!Isfull())
        st[++top] = x;
    else
    {
        printf("Stack full", NULL);
        exit(0);
    }
    return;
}

char pop()
{
    char y = ' ';
    if (!Isempty())
        y = st[top--];
    return y;
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void display()
{
    int i;
    for (i = 0; i <= top; i++)
        printf("%c", st[i]);
    printf("\t\t",NULL);
    return;
}

void output()
{
    int i;
    for (i = 0; i <= k; i++)
        printf("%c", ot[i]);
    printf("\t\t",NULL);
    return;
}