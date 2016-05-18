#include <stdio.h>

int main()
{
    int t,m,n;
    int i;
    int bb,cnt,f;
    __int64 ans,fj;
    scanf("%d",&t);
    while(t--)
    {
        cnt=ans=f=0;
        fj=10000;
        scanf("%d%d",&m,&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&bb);
            if(cnt==m||f)
            {
                ans+=fj;
                fj<<=1;
            }
            else
            {
                if(bb)
                    f=1;
                else
                    cnt++;
            }
        }
        printf("%I64d RMB\n",ans);
    }
    return 0;
}