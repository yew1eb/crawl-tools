/******************************************************
* @author:xiefubao
*******************************************************/
#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string.h>
//freopen ("in.txt" , "r" , stdin);
using namespace std;

#define eps 1e-8
#define zero(_) (abs(_)<=eps)
const double pi=acos(-1.0);
typedef long long LL;
const int Max=100010;
const LL INF=1000000007;
LL ans[Max];
LL sum[Max];
LL powa(LL t,LL p)
{
    LL ans=1;
    while(p)
    {
        if(p&1)
            ans=(ans*t)%INF;
        t=(t*t)%INF;
        p>>=1;
    }
    return ans;
}
LL getreverse(LL t)
{
    return powa(t,INF-2)%INF;
}
LL getans(int t)
{
    int l=t/2;
    LL rem=((ans[l]*((ans[l]-1+INF)%INF)%INF*getreverse((LL)2))%INF+ans[l])%INF;
    //cout<<ans[l]<<" "<<rem<<endl;
    if(t&1)
    {
        rem=(rem*sum[l-1])%INF;
        rem=(rem+ans[l])%INF;
        rem=(rem+ans[l]*(ans[l]-1)%INF)%INF;
        rem=(rem+ans[l]*((ans[l]-1+INF)%INF)%INF*((ans[l]-2+INF)%INF)%INF*getreverse(6)%INF)%INF;
        return rem;
    }
    else
    {
        return rem;
    }
}
LL geter(int t)
{
    return (ans[t-1]*sum[t-2]%INF+ans[t-1]*((ans[t-1]-1+INF)%INF)%INF*getreverse(2)%INF+ans[t-1])%INF;
}
void init()
{
    ans[0]=1;
    ans[1]=1;
    ans[2]=2;
    sum[0]=1;
    sum[1]=2;
    sum[2]=4;

    for(int i=3; i<Max; i++)
    {
        ans[i]=geter(i);
        sum[i]=(sum[i-1]+ans[i])%INF;
    }

}
int main()
{
    init();
    int n;
    while(cin>>n&&n)
    {
        cout<<getans(n)<<endl;
    }
    return 0;
}