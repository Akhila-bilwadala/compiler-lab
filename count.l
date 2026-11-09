%{
#include <stdio.h>

int character_count = 0;
int word_count = 0;
int line_count = 0;
int space_count = 0;
%}

%%
[ ]             { space_count++; }
\n              { line_count++; }
[a-zA-Z0-9]+    { word_count++; character_count += yyleng; }
.               { character_count++; }
%%

int yywrap(void)
{
    return 1;
}

int main(void)
{
    yyin = fopen("kit.txt", "r");
    if (yyin == NULL) {
        perror("kit.txt");
        return 1;
    }

    yylex();
    fclose(yyin);

    printf("No. of characters = %d\n", character_count);
    printf("No. of words = %d\n", word_count);
    printf("No. of spaces = %d\n", space_count);
    printf("No. of lines = %d\n", line_count);
    return 0;
}
