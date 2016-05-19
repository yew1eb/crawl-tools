#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int ans[14];
void init()
{
    int n,m;
    int l,j;
    int t,hash[30];
    for(n=1;n<14;n++)
    {
        for(m=n+1;;m++)
        {
            memset(hash,0,sizeof(hash));
            t=1;
            l=m%(2*n);
            if(!l)    l=2*n;
            if(l<=n)continue;
            hash[l]=1;
            while(t<n)
            {
                j=m%(2*n-t);
                if(!j)    j=2*n-t;
                while(j)
                {
                    l++;
                    if(l>2*n)    l-=2*n;
                    if(!hash[l])j--;
                }
                if(l<=n)    break;
                else        {hash[l]=1;t++;}
            }
            if(t>=n)    {ans[n]=m;break;}
        }
    }
}
int main()
{
    init();
    int n;
    while(scanf("%d",&n),n)
        printf("%d\n",ans[n]);
    return 0;
}