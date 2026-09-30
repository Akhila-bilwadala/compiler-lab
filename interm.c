#include <stdio.h>
#include <ctype.h>

char opStack[50];
char valStack[50][10];

int topOp = -1;
int topVal = -1;
char temp = 't';

int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

void process()
{
    char op = opStack[topOp--];
    char right[10], left[10];

    sprintf(right, "%s", valStack[topVal--]);
    sprintf(left, "%s", valStack[topVal--]);

    printf("%c = %s %c %s\n", temp, left, op, right);

    valStack[++topVal][0] = temp;
    valStack[topVal][1] = '\0';

    temp++;
}

int main()
{
    char str[100];
    int i;

    printf("Enter expression: ");
    scanf("%s", str);

    printf("\nIntermediate Code:\n");

    for (i = 0; str[i] != '\0'; i++)
    {
        /* Operand */
        if (isalnum(str[i]))
        {
            valStack[++topVal][0] = str[i];
            valStack[topVal][1] = '\0';
        }

        /* '(' */
        else if (str[i] == '(')
        {
            opStack[++topOp] = str[i];
        }

        /* ')' */
        else if (str[i] == ')')
        {
            while (opStack[topOp] != '(')
                process();

            topOp--;
        }

        /* Operator */
        else
        {
            while (topOp >= 0 &&
                   opStack[topOp] != '(' &&
                   precedence(opStack[topOp]) >= precedence(str[i]))
            {
                process();
            }

            opStack[++topOp] = str[i];
        }
    }

    /* Remaining operators */
    while (topOp >= 0)
        process();

    return 0;
}