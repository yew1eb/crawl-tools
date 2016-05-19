#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <deque>
#include <map>
#define cler(arr, val)    memset(arr, val, sizeof(arr))
typedef long long  LL;
const int MAXN = 110;
const int MAXM = 140000;
const int INF = 0x3f3f3f3f;
const LL mod = 10000007;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int f[48];
LL x;
vector<LL>v;
void dfs(LL x,int dep)
{
    v.push_back(x);
    if(dep>43) return ;
    for(int i=dep; i<=43; i++)
    {
        LL tmp=x*f[i];
        if(tmp>(LL)1000000000) break;
        dfs(tmp,i);
    }
}
int main()
{
    f[0]=1,f[1]=1;
    for(int i=2; i<=43; i++)
        f[i]=f[i-1]+f[i-2];
    int n;
    v.clear();
    v.push_back(0);
    dfs(1,2);
    sort(v.begin(),v.end());
    cin>>n;
    vector<LL>::iterator it;
    while(n--)
    {
        cin>>x;
        it=lower_bound(v.begin(),v.end(),x);
        if(it!=v.end()&&*it==x)
            puts("Yes");
        else puts("No");
    }
    return 0;
}
