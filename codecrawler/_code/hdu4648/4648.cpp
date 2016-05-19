#include <cstdio>
#include <cstring>
int max(int x,int y)
{
    return x>y?x:y;
}
#define LL long long
LL num[100010];
int p[100010];
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        num[0]=0;
        memset(p,-1,sizeof(int)*(m+1));
        for(int i=1; i<=n; ++i)
        {
            scanf("%I64d",&num[i]);
            num[i]+=num[i-1];
            LL c=num[i]/m;
            if(num[i]<0) num[i]=(1-c)*m+num[i];
            else num[i]=num[i]%m;
            if(p[m-num[i]]==-1||p[m-num[i]]>i) p[m-num[i]]=i;
        }
        int ans=0;
        for(int i=1; i<=n; ++i)
            if(num[i]%m==0) ans=max(i,ans);
            else ans=max(ans,i-p[m-num[i]]);
        printf("%d\n",ans);
    }
    return 0;
}