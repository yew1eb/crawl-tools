#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const long long mod=1000000007;
long long s[2002][2002],c[2002][2002];
int main()
{
    memset(s,0,sizeof(s));
    memset(c,0,sizeof(c));
    for(int i=1;i<=2000;i++)
    {
        c[i][0]=1;
        s[i][0]=0;
    }
    s[1][1]=1;c[1][1]=1;
    for(int i=2;i<=2000;i++)
     for(int j=1;j<=i;j++)
     {
        c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        s[i][j]=(s[i-1][j-1]+(i-1)*s[i-1][j])%mod;
     }
    int sec,x,y,n;
    scanf("%d",&sec);
    for(int z=1;z<=sec;z++)
    {
        scanf("%d%d%d",&n,&x,&y);
        long long ans;
        if(x+y-2<=2000)ans=(s[n-1][x+y-2]*c[x+y-2][x-1])%mod;else ans=0%mod;//é²æ­¢RE
        printf("%I64d\n",ans);
    }
   return 0;
}
