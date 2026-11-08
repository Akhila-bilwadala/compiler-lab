%{
    #include<stdio.h>
    int flag=0;
    void yyerror(const char *s);
    int yylex();
%}
%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%%
AE:
E
{
  printf("result:%d",$$);
}
;
E:
E'+'E {$$=$1+$3;}
|E'*'E{$$=$1*$3;}
|E'/'E{$$=$1/$3;}
|E'-'E{$$=$1-$3;}
|'('E')'{$$=$2;}
|NUMBER {$$=$1;}
;
%%
int main()
{
    printf("enter the expression:");
    yyparse();
    if(flag==0)
    {
      printf("valid expression...!");
    }
    return 0;
}
void yyerror(const char *s)
{
    flag=1;
    printf("invalid expression...!");
}
