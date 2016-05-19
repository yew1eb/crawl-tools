#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e6+10;
map<int,int>mm;
bool judge(int x)
{
    int s=0;
    while(x)
    {
        if(x&1)s++;
        x=x>>1;
    }
    if(s%2)return true;
    return false;
}
int find(int x)
{
    if(judge(2*x))return 2*x;
    return 2*x+1;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        mm.clear();
        int ans=0,i,j,a;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(mm[a]==0)//å»é
            ans=ans^find(a);
            mm[a]=1;
        }
        if(ans==0)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}