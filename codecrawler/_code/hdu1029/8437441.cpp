#include <stdio.h>
#include <string.h>
int f[1000000];
int main()
{
    int n,i;
    int num, tot, x;
    while(~scanf("%d",&n))
    {
        memset(f,0,sizeof(f));
        tot = 0;
        i = 0;
        while(i++<n)
        {
            scanf("%d",&x);
            f[x]++;
            if(f[x]>tot){ tot = f[x];num = x;}
        }
        if(tot>n/2) printf("%d\n",num);
    }
    return 0;
}
