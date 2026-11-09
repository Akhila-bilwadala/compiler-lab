%{
#include <stdio.h>

int vowel_count = 0;
int consonant_count = 0;
%}

%%
[aeiouAEIOU]   { vowel_count++; }
[a-zA-Z]       { consonant_count++; }
%%

int yywrap(void)
{
    return 1;
}

int main(void)
{
    yyin = fopen("hello.txt", "r");
    if (yyin == NULL) {
        perror("hello.txt");
        return 1;
    }

    yylex();
    fclose(yyin);

    printf("Number of vowels are: %d\n", vowel_count);
    printf("Number of consonants are: %d\n", consonant_count);
    return 0;
}
