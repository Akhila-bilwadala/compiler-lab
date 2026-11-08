
#include <stdio.h>

int main()
{
    int state[10], input[10];
    int transition[10][10];

    int s, n, i, j;
    int finalState, currentState;
    int length, str[20];
    int statePos, inputPos;

    // Read number of states
    printf("Enter number of states: ");
    scanf("%d", &s);

    // Read number of input symbols
    printf("Enter number of inputs: ");
    scanf("%d", &n);

    // Read states
    for(i = 0; i < s; i++)
    {
        printf("Enter state %d: ", i + 1);
        scanf("%d", &state[i]);
    }

    // Read final state
    printf("Enter final state: ");
    scanf("%d", &finalState);

    // Read input symbols
    printf("Enter input symbols:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
    }

    // Read transition table
    printf("\nEnter transition states:\n");

    for(i = 0; i < s; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("(q%d, %d) = q", state[i], input[j]);
            scanf("%d", &transition[i][j]);
        }
    }

    // Read input string
    printf("\nEnter length of string: ");
    scanf("%d", &length);

    printf("Enter input string:\n");

    for(i = 0; i < length; i++)
    {
        scanf("%d", &str[i]);
    }

    // Start from initial state
    currentState = state[0];

    // Process the input string
    for(i = 0; i < length; i++)
    {
        statePos = -1;
        inputPos = -1;

        // Find current state position
        for(j = 0; j < s; j++)
        {
            if(state[j] == currentState)
            {
                statePos = j;
                break;
            }
        }

        // Find input symbol position
        for(j = 0; j < n; j++)
        {
            if(input[j] == str[i])
            {
                inputPos = j;
                break;
            }
        }

        // Check invalid state or input
        if(statePos == -1 || inputPos == -1)
        {
            printf("\nString Rejected");
            return 0;
        }

        // Move to next state
        currentState = transition[statePos][inputPos];
    }

    // Check final state
    if(currentState == finalState)
        printf("\nString Accepted");
    else
        printf("\nString Rejected");

    return 0;
}

/*
Output:
Enter number of states: 2
Enter number of inputs: 2
Enter state 1: 0
Enter state 2: 1
Enter final state: 1
Enter input symbols:
0 1
Enter transition states:
(q0, 0) = q0
(q0, 1) = q1
(q1, 0) = q0
(q1, 1) = q1
Enter length of string: 1
Enter input string:
1

String Accepted
*/
