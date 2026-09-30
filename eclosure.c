#include <stdio.h>
#include <string.h>
int main()
{
    int n, t, i, j, k;
    char states[20][10];
    char from[20][10], input[20][10], to[20][10];

    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter states:\n");
    for (i = 0; i < n; i++)
        scanf("%s", states[i]);

    printf("Enter number of transitions: ");
    scanf("%d", &t);

    printf("Enter transitions (from input to):\n");
    for (i = 0; i < t; i++)
        scanf("%s %s %s", from[i], input[i], to[i]);

    for (i = 0; i < n; i++)
    {
        char closure[20][10];
        int count = 0;

        /* Add the state itself */
        strcpy(closure[count++], states[i]);

        /* Find epsilon transitions */
        for (j = 0; j < t; j++)
        {
            for (k = 0; k < count; k++)
            {
                if (strcmp(from[j], closure[k]) == 0 &&
                    strcmp(input[j], "e") == 0)
                {
                    int found = 0;

                    for (int x = 0; x < count; x++)
                    {
                        if (strcmp(closure[x], to[j]) == 0)
                            found = 1;
                    }

                    if (!found)
                        strcpy(closure[count++], to[j]);
                }
            }
        }

        printf("\nEpsilon closure of %s = { ", states[i]);

        for (j = 0; j < count; j++)
            printf("%s ", closure[j]);

        printf("}\n");
    }

    return 0;
}