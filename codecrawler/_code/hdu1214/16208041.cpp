#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL __int64
const int maxn=1e4+10;
int fun(int n)
{
    return n*(n-1)/2;
}
int main()
{
    int n;
    while(cin>>n)
    {
        cout<<fun(n/2)+fun(n-n/2)<<endl;;
    }
    return 0;
}
