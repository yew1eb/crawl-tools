/*
题目大意：求最大生成树。

     题目分析：转换一下思维，将最小改为最大就可以了，题目数据有重边，使用kruskal算法无影响，
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int maxn=120002;
int n,m,k,flag,father[maxn],vis[maxn],col[maxn];
long long ans,sum;
struct node
{
    int u,v,cost;
} p[maxn];
int cmp(node a,node b)
{
    return a.cost>=b.cost;
}
int find(int i)
{

    return father[i]==i?i:find(father[i]);
}
set<int>s[maxn];
int main()
{
    int i,j,u,v,t;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ans=sum=0;
        for(i=0; i<=n; i++)father[i]=i;
        memset(vis,0,sizeof(vis));
        memset(col,0,sizeof(col));
        for(i=1; i<=n-1; i++)
        {
            scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].cost);
        }
        while(m--)
        {
            cin>>k;
            vis[k]=1;
        }
        sort(p+1,p+n,cmp);
        for(i=1; i<=n-1; i++)
        {
            int x=find(p[i].u);
            int y=find(p[i].v);

            // cout<<"idx "<<i<<" fx "<<fx<<" fy "<<fy<<" u "<<p[i].u<<" v "<<p[i].v<<" cost "<<p[i].cost<<endl;
            if(vis[x]&&vis[y])
            {
                sum+=p[i].cost;
            }else father[y]=x,vis[x]=(vis[x]||vis[y]);

        }
        cout<<sum<<endl;
    }
    return 0;
}
/*
2
5 3
2 1 8
1 0 5
2 4 5
1 3 4
2
4
0
5 3
2 1 5
1 0 8
2 4 5
1 3 4
2
4
0
*/
