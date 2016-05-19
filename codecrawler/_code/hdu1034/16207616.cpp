#include <stdio.h>

#define N 100
int main()
{
    int s[N],n,i,j,k,t,p;
    while(scanf("%d",&n) == 1 && n)
    {
        for(i = 0; i < n; ++i)
            scanf("%d",s + i);
        for(k = 1; ; ++k)
        {
            t = s[n-1]/2;
            for(i = 0; i < n;++i)
            {
                p = s[i] / 2;
                s[i] = s[i] / 2 + t;
                t = p;
                if(s[i]&1)
                    ++s[i];
            }
            t = s[0];
            for(i = 1; i < n && t == s[i]; ++i);
            if(i == n)
                break;
        }
        printf("%d %d\n",k,t);
    }
    return 0;
}
