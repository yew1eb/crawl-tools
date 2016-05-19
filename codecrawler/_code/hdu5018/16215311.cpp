#include <iostream>
#include <cstdio>
using namespace std;

long long a,b,c;
void solve()
{
    if(c == a || c == b) printf("Yes\n");
    else
    {
        long long ans;
        for(ans = a+b; ans < c; )
        {
            ans += b; b = ans - b;
        }
        if(ans == c) printf("%Yes\n");
        else printf("No\n");
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        solve();
    }
    return 0;
}
