#include <stdio.h>
#include <iostream>
#define MAX 1000000+50
#define N 1000000
using namespace std;
int value[MAX],prime[MAX];
int dp[MAX][9];
void Isprime()
{
    int flag = 0;
    prime[2]=1;
    for(int i=3; i<=N; i++)
    {
        if(i%2==0)
            flag=1;
        else
            for(int j=3; j*j<=i; j=j+2)
                if(i%j==0)
                {
                    flag = 1;
                    break;
                }
        if(flag==0)
            prime[i]=1;
        flag=0;
    }
}
void getValue()
{
    for(int i = 2; i<=N; i++) //éè¿æä¸¾å¨é¨æ°ï¼ä¸å±ä¸å±éå ä¸å»ï¼æåå¯ä»¥å¾å°valueå­æ¾çä¸º1-1000000æ°å¯¹åºä¸éå¤è´¨å æ°çä¸ªæ°
        if(prime[i])
            for(int j=i; j<=N; j+=i)
                value[j]++;
    // cout<<value[j]<<" ";
    // cout<<endl;
}
void solve()
{
    for(int i=2; i<=N; i++)
        dp[i][value[i]]++;  //åå§ådp
    //for(int i = 2;i<=n;i++)
    //{
    //  cout<<dp[i][value[i]]<<" ";
    //}
    for(int i=2; i<=N; i++) //æä¸¾æææ°ï¼å¹¶ä¸å ä¸ºåªæ7ä¸ªå¯è½å¼ï¼æä»¥ç¨dpæ¥å­æ¾7ä¸ªå¯¹åºå¼çä¸ªæ°
        for(int j=1; j<8; j++)
            dp[i][j]+=dp[i-1][j];
    //if(i==99)
    //  for(int j = 1;j<8;j++)
    //    cout<<dp[i][j]<<" ";
}
void init()
{
    Isprime();
    getValue();
    solve();
}
int main()
{
    init();
    int T,i,j,L,R,flag;
    scanf("%d",&T);
    while(T--)
    {
        flag=-1;
        scanf("%d%d",&L,&R);
        for(j=2; j<8; j++) //jå¼åªè½ä¸º7ä¸ªæ°
            if(dp[R][j]-dp[L-1][j]>=2)//dpå­æ¾çä¸ºRä¸æ ä»¥åå¼ä¸ºjçä¸ªæ°ï¼æä»¥ç¸ååå¯å¾åºé´åå¯¹åºjå¼çä¸ªæ°ï¼ç¶ååªè¦å»æå¤§çå°±è¡
                flag=max(flag,j);
        printf("%d\n",flag);
    }
    return 0;
}