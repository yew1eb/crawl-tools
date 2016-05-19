#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL __int64
int main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int ans=0;
        while(n)
        {
            ans+=n/5;
            n=n/5;
        }
        cout<<ans<<endl;
    }
    return 0;
}
