
#include<stdio.h>
#include<string.h>

char op[10][5], a[10][10], b[10][10], res[10][10];
int n;

int main()
{
    int i, j;

    printf("Enter number of expressions: ");
    scanf("%d", &n);

    printf("Enter op op1 op2 result:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%s %s %s %s", op[i], a[i], b[i], res[i]);
    }

    for(i = 0; i < n; i++)
    {
        if(strcmp(op[i], "=") == 0)
        {
            for(j = i + 1; j < n; j++)
            {
                if(strcmp(res[i], a[j]) == 0)
                    strcpy(a[j], a[i]);

                if(strcmp(res[i], b[j]) == 0)
                    strcpy(b[j], a[i]);
            }
        }
    }

    printf("\nOptimized code:\n");

    for(i = 0; i < n; i++)
    {
        printf("%s %s %s %s\n", op[i], a[i], b[i], res[i]);
    }

    return 0;
}


/*
Output:
Enter the no of stages: 2
User enters:
+ 2 3 t1
+ t1 b t2

Output:
+ 5 b t2
*/
