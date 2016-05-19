#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
set<LL> s;
bool judge(int j,LL n)
{
    return (1LL<<j-1)-1<=n&&n<(1LL<<j)-1;
}
void dfs(LL n)
{
    if(n<=0)
        return ;
    s.insert(n);
    --n;
    int i=1;
    while((1LL<<i)-1<=n)
    {
        LL x=(1LL<<i)-1;
        LL y=n-x;
        if(x!=0)
            s.insert(x);
        if(judge(i+1,y)||judge(i,y))
            break;
        ++i;
    }
    dfs(n-((1LL<<i)-1));
}
int main()
{
    LL n;
    while(cin>>n)
    {
        s.clear();
        dfs(n);
        cout<<s.size()<<endl;
    }
    return 0;
}
