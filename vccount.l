%{
#include <stdio.h>
int vowels = 0;
int consonants = 0;
%}
%%
[aeiouAEIOU] { vowels++; }
[a-zA-Z] { consonants++; }
%%
int yywrap()
{
    return 1;
}
int main()
{
    yyin = fopen("kit.txt", "r");
    yylex();
    printf("Vowels = %d\n", vowels);
    printf("Consonants = %d\n", consonants);
    return 0;
}