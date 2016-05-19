#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define eps 1e-8
#define mod 258280327
const int INF=0x3f3f3f3f;
const int maxn=1000000+10;

bool is_prime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0)return false;
    return x!=1;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        if(n==2)printf("1\n");
        else if(n==3||n==4) printf("2\n");
        else if(is_prime(n))printf("%d\n",n-1);
        else printf("0\n");
    }
    return 0;
}