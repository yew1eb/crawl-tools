#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int main()
{
    LL k, p;
    while(~scanf("%I64d%I64d", &k, &p))
    {
        LL loop = p - 1;
        LL total = k / loop;
        if(total&1) puts("YES");
        else puts("NO");
    }
    return 0;
}