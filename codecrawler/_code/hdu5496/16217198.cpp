#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include<cmath>
#include<climits>
#include<cfloat>
#include<cctype>
#include<string>
#include<queue>
#define LL long long
using namespace std;
const LL mod= 1e9 + 7;
const LL N=1e5+10;
int n,a[N],bin[N];
map<int,int> mp;
int main()
{
    int tt;
    bin[0]=1;
    for(int i=1;i<N;i++)
        bin[i]=bin[i-1]*2%mod;
    cin>>tt;
    while(tt--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int sum=1,ans=0;
        mp.clear();
        for(int i=1;i<=n;i++)
        {
            ans=(ans+(LL)a[i]*(sum-mp[a[i]])%mod*bin[n-i]%mod)%mod;
            sum=(sum+bin[i-1])%mod;
            mp[a[i]]=(mp[a[i]]+bin[i-1])%mod;
        }
        cout<<(ans+mod)%mod<<endl;
    }
    return 0;
}
