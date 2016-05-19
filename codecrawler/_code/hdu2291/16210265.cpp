#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>

using namespace std;

#define Max(a,b) a>b?a:b

int dp[(1<<12)+2];//DP[i]æ¯èµè¿çäººç¶æä¸ºiï¼è·å¾çæå¤§å
int n;
struct node
{
    int w;
    int e;
    int s;
}arr[20];

void in()
{
    int tmp,i;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&(arr[i].e));
    for(i=n; i<n*n; i++)//æ ç¨æ°æ®
        scanf("%d",&tmp);
    for(i=0; i<n; i++)
        scanf("%d",&(arr[i].w));
    for(i=n; i<n*n; i++)//æ ç¨æ°æ®
        scanf("%d",&tmp);
    for(i=0; i<n; i++)
        scanf("%d",&(arr[i].s));
}
int get_bit(int num, int index)//ånumä¸­çindexä½
{
    return (num>>(index))&1;
}
int getE(int k)
{
    int sumE=0;
    for(int i=0;i<n;i++)
    {
        if(get_bit(k,i))
            sumE+=arr[i+1].e;
    }
    return sumE+arr[0].s;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        in();
        //DP å¿½ç¥srr[i]ä¸æ ä¸º0ç
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        //
        for(int i=0;i<(1<<(n-1));i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if( !(i&(1<<j)) )//æ ¹æ®iå¾å°ä»æè·å¾çç»éªï¼æ­¤å¤å¯ä»¥æè¡¨
                {
                    if( getE(i)>arr[j+1].s)
                        dp[i|(1<<j)]=Max(dp[i|(1<<j)],dp[i]+arr[j+1].w);
                }
            }
        }
        printf("%d\n",dp[(1<<(n-1))-1]);
    }
    return 0;
}
