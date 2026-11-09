%{
#include <stdio.h>
%}

%%
[a-zA-Z]+ {
    for (int i = 0; i + 2 < yyleng; i++) {
        if (yytext[i] == 'a' && yytext[i + 1] == 'b' && yytext[i + 2] == 'c') {
            yytext[i] = 'A';
            yytext[i + 1] = 'B';
            yytext[i + 2] = 'C';
        }
    }
    ECHO;
}
.|\n        { ECHO; }
%%

int yywrap(void)
{
    return 1;
}

int main(void)
{
    yyin = fopen("abcip.txt", "r");
    if (yyin == NULL) {
        perror("abcip.txt");
        return 1;
    }

    yylex();
    fclose(yyin);
    return 0;
}
