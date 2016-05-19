#include <stdio.h>
#include <string.h>

char str[56];

bool f()
{
    int len = strlen(str), i = 0, j;
    j = len - 1;
    while(i <= j){
        if(str[i] == str[j]){
            ++i; --j;
        }else return 0;
    }
    return 1;
}

int main()
{
    int cas = 1;
    while(scanf("%s", str) != EOF){
        if(!strcmp(str, "STOP")) break;
        printf("#%d: ", cas++);
        if(f()) puts("YES");
        else puts("NO");
    }
    return 0;
}