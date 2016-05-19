#include <string.h>
#include <iostream>
#include <stdio.h>

char str[1000005];
int next[1000005];

void getnext()
{
    int i = 0,j = -1;
    memset(next,0,sizeof(next));
    next[0] = -1;
    while (str[i])
    {
        if(j == -1 || str[i] == str[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        j = next[j];
    }
}

void kmp()
{
    int i,t;
    for(i = 2;str[i-1];i++)
    {
        t = i-next[i];
        if(i%t == 0 && i/t>1)
        printf("%d %d\n",i,i/t);
    }
}

int main()
{
    int n,cnt = 1;

    while(scanf("%d",&n)!=EOF && n)
    {
        scanf("%s",str);
        printf("Test case #%d\n",cnt++);
        getnext();
        kmp();
        putchar(10);
    }

    return 0;
}


