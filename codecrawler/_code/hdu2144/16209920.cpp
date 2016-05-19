#include"stdio.h"
#include"string.h"
const int N=120;
int dp[N][N];
char str[N][N];
int len[N],set[N];
int find(int x)
{
    if(x==set[x])return x;
    set[x]=find(set[x]);
    return set[x];
}
int fun(int x,int y)
{
    int i,j;
    int max;
    memset(dp,0,sizeof(dp));
    max=0;
    for(i=1;i<=len[x];i++)
    {
        dp[i][0]=0;
        for(j=1;j<=len[y];j++)
        {
            if(str[x][i]==str[y][j])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=0;
            if(dp[i][j]>max)max=dp[i][j];
        }
    }
    return max;
}
int main()
{
    int T;
    int a,b;
    int i,j;
    int n,t;
    double p;
    T=1;
    while(scanf("%d%lf",&n,&p)!=-1)
    {
        for(i=0;i<n;i++)
            set[i]=i;
        for(i=0;i<n;i++)
        {
            scanf("%s",str[i]+1);
            str[i][0]=' ';
            len[i]=strlen(str[i])-1;
            for(j=0;j<i;j++)
            {
                a=find(i);
                b=find(j);
                if(a==b)continue;
                t=fun(i,j);
                if(t*100.0/len[i]>p&&t*100.0/len[j]>p)
                    set[a]=b;
            }
        }
        int ans;
        ans=0;
        for(i=0;i<n;i++)
            if(set[i]==i)ans++;
        printf("Case %d:\n",T++);
        printf("%d\n",ans);
    }
    return 0;
}
            

