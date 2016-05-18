#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
#define LL __int64
#define maxn 100011
int t[maxn],c[maxn],n,q,m[maxn],vis[maxn],a[maxn],b[maxn];
map<int,map<int,int> >nn;
map<int,int>mm;
map<int,int>ll;
int bb[1001];
int flag[maxn],s[maxn],ss[maxn];
void find(int x)
{
    ll.clear();
    int tt=1,i,j,k,y,z,d;
    s[0]=0;s[1]=c[x];ll[x]=1,ss[1]=x;
    for(i=2;;i++)
    {
        vis[x]=1;
        x=t[x];
        ss[i]=x;
        if(ll[x])
            break;
        if(vis[x])
        {
            for(j=i-1;j>=1;j--)
            {
                a[ss[j]]=s[i-1]-s[j-1]+a[x];
                b[ss[j]]=b[x];
            }
            return;
        }
        ll[x]=++tt;
        s[i]=s[i-1]+c[x];
        //cout<<s[i]<<endl;
    }
    d=s[i-1]-s[ll[x]-1];
    for(j=1;j<i;j++)
    {
        if(j<=ll[x])
            a[ss[j]]=s[ll[x]-1]-s[j-1];
        else
            a[ss[j]]=s[i-1]-s[j-1];
        b[ss[j]]=d;
    }
}
int main()
{
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        int i,j,k;
        for(i=1;i<=n;i++)
            scanf("%d",&t[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&c[i]);
        for(i=1;i<=q;i++)
            scanf("%d",&m[i]);
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)
        {
            if(!vis[i])
            find(i);
        }
       // for(i=1;i<=n;i++)
        //    cout<<i<<" "<<a[i]<<" "<<b[i]<<endl;
        mm.clear();
        nn.clear();
        int tt=0;
        for(i=1;i<=n;i++)
        {
            if(mm[b[i]]==0)
            {
                mm[b[i]]=++tt;
                bb[tt]=b[i];
            }
            nn[tt][a[i]]=1;
        }
        //cout<<nn[1][0]<<endl;
        memset(flag,0,sizeof(flag));
        for(j=1;j<=q;j++)
        {
            if(m[j]<=0)continue;
            for(i=1;i<=tt;i++)
            if(nn[i][m[j]%bb[i]]){flag[j]=1;break;}
        }
        for(i=1;i<=q;i++)
            if(flag[i])printf("YES\n");
            else printf("NO\n");
    }
    return 0;
}
/*
    由于t[i]<=n,t(xi-1)=xi.所以必定会出现循环。枚举x1=i(1<=i<=n)可求出a[i],b[i]
    a[i],b[i]表示，在经过a[i]长度后会进入b[i]长度的循环，所以符合a[i]+b[i]*k==m[i]的m[i]都是YES
    直接暴力的话就是对于每个m[i]逐次匹配是否能在a[i],b[i]的循环中出现。最坏情况需要O(n^2)，会超时；
    我们可以发现有很多数的b[i]是相同的，所以我们可以枚举b[i]减少时间(在一个循环中出现的数b[i]肯定相同)
    
    由于t(xi-1)=xi，所以在枚举的i中循环出现过j，
    a[j]=a[i]-s[j'-1](s[i]表示在枚举过程中前i个数的c[i]和,j'表示j所在位置),b[i]=b[j];
    所以可以再O(n)时间内，找出所有a[i],b[i]
*/