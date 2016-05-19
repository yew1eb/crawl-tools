#include<cstdio>
#include<cstring>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
int l[1005],r[1005];
int h[1005];
int main()
{
    int cas,n,m,ans;
    char s[5],c;
    scanf("%d",&cas);
    for(; cas--;)
    {
        ans=0;
        memset(h,0,sizeof(h));
        scanf("%d%d",&n,&m);
        h[0]=h[m+1]=-1;
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=m; ++j)
            {
                scanf("%s",s);//è¿éçè¾å¥æ¯è¾çº ç»ï¼è¦æ³¨æè¾å¥å¯è½ä¼æå¤ä½çåè½¦æèç©ºæ ¼
                if(s[0]=='F') h[j]++;
                else          h[j]=0;
            }
            for(int j=1;j<=m;++j) l[j]=r[j]=j;
            for(int j=1;j<=m;++j)
                for(;h[l[j]-1]>=h[j];l[j]=l[l[j]-1]);
            for(int j=m;j>=1;--j)
                for(;h[r[j]+1]>=h[j];r[j]=r[r[j]+1]);
            for(int j=1;j<=m;++j)
                ans=max(ans,h[j]*(r[j]-l[j]+1));
        }
        printf("%d\n",ans*3);
    }
    return 0;
}
