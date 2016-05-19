#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define inf 0x3f3f3f3f
#pragma comment(linker, "/STACK:16777216")
#define eps 1e-6
#define ll long long
using namespace std;

bool judge(ll x)
{
    ll odd=0,even=0,flag=0;
    while(x>0)
    {
        if(flag)
        {
            odd+=x%10;
            flag=0;
        }
        else
        {
            even+=x%10;
            flag=1;
        }
        x/=10;
    }
    return (even-odd==3);
}

int main()
{
    ll l,r;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cin>>l>>r;
        while(l<=r)
        {
            if((l%11==3)^judge(l))
                break;
            l++;
        }
        if(l>r) printf("-1\n");
        else cout<<l<<endl;
    }
    return 0;
}
