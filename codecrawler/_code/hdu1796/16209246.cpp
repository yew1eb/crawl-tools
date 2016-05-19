#include <stdio.h>
#include <algorithm>

using namespace std;

typedef __int64 LL;

int fac[12],top,ans,n;

int gcd(int a,int b)
{
    return b ? gcd(b,a%b) : a;
}

int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}

void dfs(int i,int cnt,int num,int m)
{
    if(cnt == m)
    {
        int sum = (n-1)/num;
        m&1 ? ans += sum : ans -= sum;
        return ;
    }
    if(top-i < m-cnt)
        return ;
    int LCM = lcm(num,fac[i]);
    if(LCM <= n-1)
        dfs(i+1,cnt+1,LCM,m);
    dfs(i+1,cnt,num,m);
}

int sovle()
{
    ans = 0;
    for(int m=1;m<=top;m++)
        dfs(0,0,1,m);
    return ans;
}

int main()
{
    while(~scanf("%d%d",&n,&top))
    {
        for(int i=0;i<top;i++)
        {
            scanf("%d",&fac[i]);
            if(!fac[i])
                i--,top--;
        }
        printf("%d\n",sovle());
    }
    return 0;
}
