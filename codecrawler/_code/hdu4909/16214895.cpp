#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;

const int maxn=2e4+10;
char a[maxn],b[maxn];
struct Map{
    int head[maxn],next[maxn],key[maxn],val[maxn],tt;
    Map(){tt=0;}
    void clear()
    {
        memset(head,-1,sizeof(head));
        tt=0;
    }
    int &get(int v)
    {
        int i,j,k,u=v%maxn;
        for(i=head[u];i!=-1;i=next[i])
            if(key[i]==v)return val[i];
        key[tt]=v;
        val[tt]=0;
        next[tt]=head[u];
        head[u]=tt;
        return val[tt++];
    }
    int get2(int v)
    {
        int i,j,k,u=v%maxn;
        for(i=head[u];i!=-1;i=next[i])
            if(key[i]==v)return val[i];
        return 0;
    }
}mm;
int fun(int p,int n)
{
    mm.clear();
    int i,j,k=0,ans=0;
    mm.get(0)++;
    for(i=p;i<n;i++)
    {
        k^=(1<<(a[i]-'a'));
        ans+=mm.get2(k);mm.get(k)++;
    }
    return ans;
}
int fun2(int p,int n)
{
    mm.clear();
    int i,j,k=0,ans=0;
    mm.get(0)++;
    for(i=0;i<p;i++)
    {
        k^=(1<<(a[i]-'a'));
        mm.get(k)++;
    }
    ans+=mm.get2(k);
    for(j=0;j<26;j++)
        ans+=mm.get2(k^(1<<j));
    for(i=p+1;i<n;i++)
    {
        k^=(1<<(a[i]-'a'));
        ans+=mm.get2(k);
        for(j=0;j<26;j++)
            ans+=mm.get2(k^(1<<j));
    }
    return ans;
}
int main()
{
    //freopen("D:\\in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,k,n,ans=0,p=-1;
        scanf("%s",a);
        n=strlen(a);
        for(i=0;i<n;i++)
            if(a[i]=='?')p=i;
        if(p==-1)ans=fun(0,n);
        else
        {
            ans+=fun(0,p)+fun(p+1,n);
            ans+=fun2(p,n);
        }
        printf("%d\n",ans);
    }
    return 0;
}
