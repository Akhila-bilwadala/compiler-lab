#include <stdio.h>
#include <string.h>

int main(void)
{
    char icode[10][30], str[20], opr[10];
    int i = 0;

    printf("\nEnter the set of intermediate code(terminated by EXIT):\n");
    do
    {
        scanf("%29s", icode[i]);
    } while (strcmp(icode[i++], "EXIT") != 0 && i < 10);

    printf("\nTarget code generation");
    printf("\n************************");

    i = 0;
    while (strcmp(icode[i], "EXIT") != 0)
    {
        strcpy(str, icode[i]);

        switch (str[3])
        {
            case '+':
                strcpy(opr, "ADD");
                break;
            case '-':
                strcpy(opr, "SUB");
                break;
            case '*':
                strcpy(opr, "MUL");
                break;
            case '/':
                strcpy(opr, "DIV");
                break;
            default:
                opr[0] = '\0';
                break;
        }

        printf("\nMOV %c,R%d", str[2], i);
        printf("\n%s %c,R%d", opr, str[4], i);
        printf("\nMOV R%d,%c", i, str[0]);
        i++;
    }

    printf("\n");
    return 0;
}

/*
Input:
Enter the set of intermediate code(terminated by EXIT):
a=z*B
b=x+y
c=m-n
d=p/q
EXIT

Output:
Target code generation
************************
MOV z,R0
MUL B,R0
MOV R0,a
MOV x,R1
ADD y,R1
MOV R1,b
MOV m,R2
SUB n,R2
MOV R2,c
MOV p,R3
DIV q,R3
MOV R3,d
*/
