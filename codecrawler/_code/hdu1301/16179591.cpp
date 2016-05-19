#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int f[102];
struct edge
{
    int u,v;
    int w;
}e[102];
bool cmp(edge e1,edge e2)
{
    return e1.w<e2.w;
}
int find(int x)
{
    if(f[x]==-1)
        return x;
    return find(f[x]);
}
int kruskal(int n,int ne)
{
    sort(e,e+ne,cmp);
    int x,y,cost(0);
    for(int i=0;i<ne;i++)
        {
            x=find(e[i].u);
            y=find(e[i].v);
            if(x!=y)
            {
                f[y]=x;
                cost+=e[i].w;
            }
        }
    return cost;
}
int main()
{
    int n;
    while(cin>>n,n)
    {
        int m=n-1,cnt=0,k;
        char u,v;
        memset(f,-1,sizeof(f));
        while(m--)
        {
            cin>>u>>k;
            while(k--)
            {
                e[cnt].u=u-'A';
                cin>>v>>e[cnt].w;
                e[cnt].v=v-'A';
                cnt++;
            }
        }
        cout<<kruskal(n,cnt)<<endl;
    }
    return 0;
}