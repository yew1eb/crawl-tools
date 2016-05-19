#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
    char str[500],s[500];
    int hash[500];
    int i,len,l;
    while(gets(s))
    {
        l = 1;
        len = strlen(s);
        memset(hash,0,sizeof(hash));
        for(i = 0;i<len;i++)
        {
            if(s[i]==' ')
            continue;
            str[l] = s[i];
            hash[l++] = 1;
        }
        for(i = 3;i<l;i+=3)
        {
            printf("%c",str[i]);
            hash[i] = 0;
        }
        for(i = 2;i<l;i+=2)
        {
            if(hash[i] == 0)
            continue;
            printf("%c",str[i]);
            hash[i] = 0;
        }
        for(i = 1;i<l;i++)
        {
            if(hash[i] == 0)
            continue;
            printf("%c",str[i]);
        }
        printf("\n");
    }

    return 0;
}
