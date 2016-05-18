#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <map>

using namespace std;
const int N = 50000009;
int ans[N];
int find(int n)
{
    if(n<N)
    {
        if(n==1) return 1;
        if(ans[n]) return ans[n];
        if(n&1) ans[n] = find(n*3+1);
        else
        {
            int t = find(n>>1);
            ans[n] = max(n,t);
            return ans[n];
        }
        return ans[n];
    }else
    {
        if(n&1) return find(n*3+1);
        else return max(n,find(n>>1));
    }
    return n;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    ans[1] = 1;
    int cas,n,a;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&a,&n);
        printf("%d %d\n",a,find(n));
    }
    return 0;
}
