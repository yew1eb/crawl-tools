#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=100;
long long ans[maxn]={0,0,1};
void init()
{
    long long tmp=4;
    for(int i=3;i<maxn;i++)
    {
        ans[i]=2*ans[i-1]+tmp-1;
        tmp*=2;
    }
}

int main()
{
#ifdef LOCAL
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif  
    init();
    int n;
    while(cin>>n)
    {
        cout<<ans[n]<<endl;
    }
    return 0;
}