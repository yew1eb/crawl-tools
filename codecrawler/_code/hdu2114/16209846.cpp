#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    __int64 N,ans;
    while(cin >> N)
    {
        N %= 10000;
        ans = (N*(N+1)/2)%10000 * (N*(N+1)/2)%10000;
        printf("%04I64d\n",ans);
    }

    return 0;
}
