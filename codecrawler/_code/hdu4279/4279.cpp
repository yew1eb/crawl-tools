#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;
typedef long long LL;

LL Solve(LL n)
{
    LL ans=0;
    if(n<6) return 0;
    ans+=n/2-2;
    if((LL)sqrt(1.0*n)&1) ans++;
    return ans;
}

int main()
{
    LL a,b,t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<Solve(b)-Solve(a-1)<<endl;
    }
    return 0;
}
