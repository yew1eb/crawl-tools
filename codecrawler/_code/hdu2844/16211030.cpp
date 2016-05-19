#include"stdio.h"
#include"string.h"
#include"stdlib.h"
const int N=111;
const int M=100111;

int n,m;
int val[N],c[N],flag[M];
int main()
{
    int i,l;
    int k,t,temp;
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(i=0;i<n;i++)    scanf("%d",&val[i]);
        for(i=0;i<n;i++)    scanf("%d",&c[i]);

        memset(flag,0,sizeof(flag));
        flag[0]=1;
        for(i=0;i<n;i++)
        {
            //å®å¨èå
            if(c[i]*val[i]>=m)
            {
                for(l=val[i];l<=m;l++)
                    flag[l]=flag[l] || flag[l-val[i]];
            }
            //0-1èå
            else
            {
                k=1;
                t=c[i];
                while(k<t)
                {
                    temp=k*val[i];
                    for(l=m;l>=temp;l--)
                        flag[l]=flag[l] || flag[l-temp];
                    t-=k;
                    k<<=1;
                }
                if(t)
                {
                    temp=t*val[i];
                    for(l=m;l>=temp;l--)
                        flag[l]=flag[l] || flag[l-temp];
                }
            }
        }

        int ans=0;
        for(i=1;i<=m;i++)    if(flag[i])    ans++;
        printf("%d\n",ans);
    }
    return 0;
}