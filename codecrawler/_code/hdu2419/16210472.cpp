#include <iostream>
#include<string>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<set>
using namespace std;
const int maxnum=20010;
struct query
{
    char a;
    int b;
    int c;
}query[300050];
multiset<int>map1[maxnum];
multiset<int>var[maxnum];
int fa[maxnum];
int cost[maxnum];
int find(int x)
{
    if(fa[x]==x)
        return x;
    else
        return fa[x]=find(fa[x]);
}
void Merge(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
        return ;
    if(x>y)
      swap(x,y);
    fa[x]=y;
    multiset<int>::iterator it;
    for(it=var[x].begin();it!=var[x].end();it++)
    {
        var[y].insert(*it);
    }
}
int main()
{
    int cas=0;
    int n,m,p;
    while(scanf("%d%d%d",&n,&m,&p)!=EOF)
    {
        int i;
        for(i=1;i<=n;i++)
        {
            fa[i]=i;
            map1[i].clear();
            var[i].clear();
            scanf("%d",&cost[i]);
        }
        for(i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(a>b)
                swap(a,b);
            map1[b].insert(a);
        }
        for(i=1;i<=p;i++)
        {
            int a;
            int b;
            cin>>query[i].a>>a>>b;
            query[i].b = a,query[i].c = b;
            char c=query[i].a;
            if(c=='U')
            {
                query[i].c=cost[a];
                cost[a]=b;
            }
            if(c=='E')
            {
                if(a>b)
                    swap(a,b);
                map1[b].erase(map1[b].find(a));
            }
        }
        for(i=1;i<=n;i++)
            var[i].insert(cost[i]);
        multiset<int>::iterator it;
        for(i=1;i<=n;i++)
        {
            for(it=map1[i].begin();it!=map1[i].end();it++)
                Merge(i,*it);
        }
        double ans=0,time=0;
        for(i=p;i>=1;i--)
        {
            if(query[i].a=='F')
            {
                time++;
               int pa=find(query[i].b);
               it=var[pa].lower_bound(query[i].c);
               if(it!=var[pa].end())
                  ans+=*it;
                  //cout<<ans<<endl;
            }
            else
            {
                if(query[i].a=='U')
                {
                   int pa=find(query[i].b);
                   var[pa].erase(var[pa].find(cost[query[i].b]));
                   var[pa].insert(query[i].c);
                   cost[query[i].b]=query[i].c;
                }
                else
                {
                    Merge(query[i].b,query[i].c);
                }
            }

        }
         printf("Case %d: %.3lf\n",++cas,ans/time);
    }
    return 0;
}
