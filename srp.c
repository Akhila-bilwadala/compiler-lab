#include <stdio.h>
#include <string.h>

char stack[20], input[20];
int top = -1;

void print(int i, char action[])
{
    stack[top + 1] = '\0';
    printf("$%-10s %-10s %s\n", stack, input + i, action);
}

void reduce(int i)
{
    /* i -> E */
    if (stack[top] == 'i')
    {
        stack[top] = 'E';
        print(i, "REDUCE E->i");
    }

    /* E+E -> E */
    if (top >= 2 &&
        stack[top-2] == 'E' &&
        stack[top-1] == '+' &&
        stack[top] == 'E')
    {
        top -= 2;
        stack[top] = 'E';
        print(i, "REDUCE E->E+E");
    }

    /* E*E -> E */
    if (top >= 2 &&
        stack[top-2] == 'E' &&
        stack[top-1] == '*' &&
        stack[top] == 'E')
    {
        top -= 2;
        stack[top] = 'E';
        print(i, "REDUCE E->E*E");
    }

    /* (E) -> E */
    if (top >= 2 &&
        stack[top-2] == '(' &&
        stack[top-1] == 'E' &&
        stack[top] == ')')
    {
        top -= 2;
        stack[top] = 'E';
        print(i, "REDUCE E->(E)");
    }
}

int main()
{
    int i, n;

    printf("Grammar:\n");
    printf("E->E+E\nE->E*E\nE->(E)\nE->i\n");

    printf("\nEnter input: ");
    scanf("%s", input);

    n = strlen(input);
    input[n] = '$';
    input[n + 1] = '\0';

    printf("\nSTACK       INPUT       ACTION\n");
    printf("--------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        stack[++top] = input[i];

        if (input[i] == 'i')
            print(i + 1, "SHIFT i");
        else
            print(i + 1, "SHIFT");

        reduce(i + 1);
    }

    if (top == 0 && stack[0] == 'E')
    {
        print(n, "ACCEPT");
        printf("\nACCEPTED\n");
    }
    else
        printf("\nREJECTED\n");

    return 0;
}