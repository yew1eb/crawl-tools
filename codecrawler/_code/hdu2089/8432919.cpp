#include <stdio.h>
#include <string.h>
int tot[1000000];
int main()
{
    int n, m;
    char s[20];
    int i;
    tot[0] = 0;
    for(i=1; i<=1000000; i++)
    {
        tot[i] = tot[i-1];
        sprintf(s,"%d",i);
        if(strstr(s,"4")==NULL && strstr(s,"62")==NULL)
            tot[i]++;
    }
    while(scanf("%d%d",&n,&m),n+m)
    {
        printf("%d\n",tot[m]-tot[n-1]);
    }
    return 0;
}
