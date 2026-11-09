%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "calc.tab.h"
    extern int yylval;
%}
%%
[0-9]+ {yylval=atoi(yytext);return NUMBER;}
[ \t\n] ;
. {return yytext[0];}
%%
int yywrap()
{
    return 1;
}
