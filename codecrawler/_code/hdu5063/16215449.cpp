//218ms
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100000+1000;
int a[maxn];//å¥å¶æåºæä½
int q[maxn];//å­å¨æä½ç±»åï¼1æ¯å¥å¶æåºï¼2æ¯éç½®
int c[maxn];//éç½®
const int mod=1000000007;
int solve(int cur,int x)//æ¾å°å¨åå¼å§çä½ç½®
{
    int ans=x;
    for(int i=cur-1;i>=0;i--)
    {
        if(q[i]==1)
        {
           ans=a[ans];
        }
        else
        {
            ans=c[ans];
        }
    }
    return ans;
}
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
       int index=1;
       for(int i=1; i<=n; i +=2)
       a[index++]=i;
       for(int i=2; i<=n; i +=2)
        a[index++]=i;
       for(int i=1;i<=n;i++)
       c[i]=n+1-i;
        char s[10];
        int p;
        int cur=0;
        int cou=0;
        for(int i=0;i<m;i++)
        {
            scanf("%s%d",s,&p);
            if(s[0]=='O')
            {
                if(p==3)
                cou++;
                else
                q[cur++]=p;
            }
            else
            {
                long long ans=solve(cur,p);

                for(int i=0;i<cou;i++)
                {
                    ans=ans*ans%mod;
                }
                printf("%I64d\n",ans);
            }
        }
    }
    return 0;
}
