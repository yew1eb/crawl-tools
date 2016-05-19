#include <iostream>
#include <cstdio>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
map<string,int> mp;
int n,m;
char ss[1005],ss2[1005];
string s1,s2;
struct node
{
    int c;
    int q;
}t;
vector<node> v[1005];
int top;
bool isok(int qq)
{
    long long tot=0;
    for(int i=1;i<top;i++)
    {
        int nc=0x7fffffff;
        for(int j=0;j<v[i].size();j++)
        {
            if(v[i][j].q>=qq)
            {
                nc=min(nc,v[i][j].c);
            }
        }
        if(nc==0x7fffffff) return false;
        tot+=nc;
        if(tot>m) return false;
    }
    return tot<=m;
}
int main()
{
    int T;
    scanf("%d",&T);

    while(T--)
    {
        top=1;
        mp.clear();
        int l=0,r=0x7fffffff,mid;
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++)
        {
            v[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%s%s%d%d",ss,ss2,&t.c,&t.q);
            s1=ss;
            int id=mp[s1];
            if(!id)
            {
                mp[s1]=top++;
                v[top-1].push_back(t);
            }
            else
            {
                v[id].push_back(t);
            }
        }
        for(int i=1;i<top;i++)
        {
            int tzf=0;
            for(int j=0;j<v[i].size();j++)
            {
                tzf=max(tzf,v[i][j].q);
            }
            r=min(tzf,r);
        }
        int ans;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(isok(mid)) {ans=mid;l=mid+1;}
            else r=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
