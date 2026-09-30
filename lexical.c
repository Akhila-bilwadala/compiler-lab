







#include<stdio.h>
#include<string.h>
#include<ctype.h>
int iskeyword(char str[])
{
    char keywords[][10]={"auto", "break", "case", "char", "const",
        "continue", "default", "do", "double", "else",
        "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "return", "short",
        "signed", "sizeof", "static", "struct", "switch",
        "typedef", "union", "unsigned", "void", "volatile",
        "while"
    };
    for(int i=0;i<32;i++)
    {
        if(strcmp(str,keywords[i])==0)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int i=0;
    char word[50],ch;
    FILE *fp;
    char operators[]="+-*/%&!^~";
    char special[]="{}[]().,;?";
    fp=fopen("program.txt","r");
    if(fp==NULL)
    {
        printf("cannot open the file");
    }
    while((ch=fgetc(fp))!=EOF)
    {
        if(strchr(operators,ch))
        {
            printf("%c:operator",ch);
        }
        else if(strchr(special,ch))
        {
            printf("%c:special charectors",ch);
        }
        else if(isalnum(ch))
        {
            word[i++]=ch;
        }
         else if (i > 0)
        {
            word[i] = '\0';
            i = 0;

            if (iskeyword(word))
                printf("%s : Keyword\n", word);
            else if (isdigit(word[0]))
                printf("%s : Constant\n", word);
            else
                printf("%s : Identifier\n", word);
        }
    }

    /* Process last word */
    if (i > 0)
    {
        word[i] = '\0';

        if (iskeyword(word))
            printf("%s : Keyword\n", word);
        else if (isdigit(word[0]))
            printf("%s : Constant\n", word);
        else
            printf("%s : Identifier\n", word);
    }

    fclose(fp);

    return 0;
}

