#include <stdio.h>

int main()
{
    char ch;
    while(scanf("%c", &ch) != EOF){
        if(ch >= 'A' && ch <= 'Z') ch = ch - 'A' + 'a';
        putchar(ch);
    }
    return 0;
}