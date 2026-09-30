#include <stdio.h>
#include <string.h>
char input[20];
int i = 0, error = 0;
void E();
void Eprime();
void T();
void Tprime();
void F();
int main()
{
    printf("Enter expression: ");
    scanf("%s", input);
    E();
    if (input[i] == '\0' && error == 0)
        printf("Accepted\n");
    else
        printf("Rejected\n");
    return 0;
}
void E()
{
    T();
    Eprime();
}
void Eprime()
{
    if (input[i] == '+')
    {
        i++;
        T();
        Eprime();
    }
}
void T()
{
    F();
    Tprime();
}
void Tprime()
{
    if (input[i] == '*')
    {
        i++;
        F();
        Tprime();
    }
}
void F()
{
    if (input[i] >= 'a' && input[i] <= 'z')
    {
        i++;
    }
    else if (input[i] == '(')
    {
        i++;
        E();

        if (input[i] == ')')
            i++;
        else
            error = 1;
    }
    else
    {
        error = 1;
    }
}