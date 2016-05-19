#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;
typedef long long LL;

const LL INF=1e18+300;
const LL T=(LL)1<<31;

LL num[105];

LL multi(LL a,LL b)
{
    LL ans=1;
    while(b)
    {
        if(b&1)
        {
            double judge=1.0*INF/ans;
            if(a>judge) return -1;
            ans*=a;
        }
        b>>=1;
        if(a>T&&b>0) return -1;
        a=a*a;
    }
    return ans;
}

LL find(LL x,LL k)
{
    LL r=(LL)pow(x,1.0/k);
    LL t,p;
    p=multi(r,k);
    if(p==x) return r;
    if(p>x||p==-1) r--;
    else
    {
        t=multi(r+1,k);
        if(t!=-1&&t<=x) r++;
    }
    return r;
}

LL Solve(LL n)
{
    int i,k=0;
    memset(num,0,sizeof(num));
    if(n<=3) return n;
    num[1]=n;
    for(i=2;i<63;i++)
    {
        num[i]=find(n,i)-1;
        if(!num[i]) break;
    }
    k=i;
    for(int i=k-1;i>0;i--)
        for(int j=1;j<i;j++)
            if(i%j==0) num[j]-=num[i];
    LL ans=num[1];
    for(int i=2;i<k;i++)
        ans+=(i*num[i]);
    return ans;
}

int main()
{
    LL n,m;
    while(cin>>m>>n)
    {
        if(m==0&&n==0) break;
        cout<<Solve(n)-Solve(m-1)<<endl;
    }
    return 0;
}
