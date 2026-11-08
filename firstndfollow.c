
#include <stdio.h>
#include <ctype.h>

char p[50][100];
int n;

int first[26][128] = {0};
int follow[26][128] = {0};

// Function to find FIRST
void findFirst()
{
    int change, i, j, k, x, a, nullable;
    char c;

    do
    {
        change = 0;

        for(i = 0; i < n; i++)
        {
            a = p[i][0] - 'A';
            nullable = 1;

            for(j = 2; p[i][j] != '\0'; j++)
            {
                c = p[i][j];

                if(c == 'e')
                {
                    if(!first[a]['e'])
                    {
                        first[a]['e'] = 1;
                        change = 1;
                    }
                    break;
                }

                if(!isupper((unsigned char)c))
                {
                    if(!first[a][(unsigned char)c])
                    {
                        first[a][(unsigned char)c] = 1;
                        change = 1;
                    }

                    nullable = 0;
                    break;
                }

                k = c - 'A';

                for(x = 0; x < 128; x++)
                {
                    if(first[k][x] && x != 'e' && !first[a][x])
                    {
                        first[a][x] = 1;
                        change = 1;
                    }
                }

                if(!first[k]['e'])
                {
                    nullable = 0;
                    break;
                }
            }

            if(nullable && !first[a]['e'])
            {
                first[a]['e'] = 1;
                change = 1;
            }
        }

    } while(change);
}

// Function to find FOLLOW
void findFollow()
{
    int change, i, j, k, x, a, b;
    char c, next;

    // Add $ to start symbol
    follow[p[0][0] - 'A']['$'] = 1;

    do
    {
        change = 0;

        for(i = 0; i < n; i++)
        {
            a = p[i][0] - 'A';

            for(j = 2; p[i][j] != '\0'; j++)
            {
                c = p[i][j];

                if(!isupper((unsigned char)c))
                    continue;

                k = c - 'A';

                // Check symbols after the non-terminal
                for(int t = j + 1; ; t++)
                {
                    next = p[i][t];

                    // If at the end, add FOLLOW of LHS
                    if(next == '\0')
                    {
                        for(x = 0; x < 128; x++)
                        {
                            if(follow[a][x] && !follow[k][x])
                            {
                                follow[k][x] = 1;
                                change = 1;
                            }
                        }
                        break;
                    }

                    if(next == 'e')
                        continue;

                    // If next symbol is a terminal
                    if(!isupper((unsigned char)next))
                    {
                        if(!follow[k][(unsigned char)next])
                        {
                            follow[k][(unsigned char)next] = 1;
                            change = 1;
                        }
                        break;
                    }

                    // If next symbol is a non-terminal
                    b = next - 'A';

                    for(x = 0; x < 128; x++)
                    {
                        if(first[b][x] && x != 'e' && !follow[k][x])
                        {
                            follow[k][x] = 1;
                            change = 1;
                        }
                    }

                    // Stop if next non-terminal cannot produce epsilon
                    if(!first[b]['e'])
                        break;
                }
            }
        }

    } while(change);
}

// Main function
int main()
{
    int i, j, a;
    int done[26] = {0};

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (use e for epsilon):\n");

    for(i = 0; i < n; i++)
        scanf("%99s", p[i]);

    findFirst();
    findFollow();

    // Display FIRST sets
    printf("\nFIRST SETS:\n");

    for(i = 0; i < n; i++)
    {
        a = p[i][0] - 'A';

        if(done[a])
            continue;

        done[a] = 1;

        printf("FIRST(%c) = { ", p[i][0]);

        for(j = 0; j < 128; j++)
        {
            if(first[a][j])
                printf("%c ", j);
        }

        printf("}\n");
    }

    // Reset done array
    for(i = 0; i < 26; i++)
        done[i] = 0;

    // Display FOLLOW sets
    printf("\nFOLLOW SETS:\n");

    for(i = 0; i < n; i++)
    {
        a = p[i][0] - 'A';

        if(done[a])
            continue;

        done[a] = 1;

        printf("FOLLOW(%c) = { ", p[i][0]);

        for(j = 0; j < 128; j++)
        {
            if(follow[a][j])
                printf("%c ", j);
        }

        printf("}\n");
    }

    return 0;
}

/*
Output:
Enter number of productions: 7
Enter productions (use e for epsilon):
S=ABC
A=DEF
B=e
C=e
D=e
E=e
F=e

FIRST SETS:
FIRST(S) = { e }
FIRST(A) = { e }
FIRST(B) = { e }
FIRST(C) = { e }
FIRST(D) = { e }
FIRST(E) = { e }
FIRST(F) = { e }

FOLLOW SETS:
FOLLOW(S) = { $ }
FOLLOW(A) = { $ }
FOLLOW(B) = { $ }
FOLLOW(C) = { $ }
FOLLOW(D) = { $ }
FOLLOW(E) = { $ }
FOLLOW(F) = { $ }
*/
