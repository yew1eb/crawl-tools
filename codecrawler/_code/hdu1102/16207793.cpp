#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

struct edge
{
    int u;
    int v;
    int w;
   
};


edge e[1000050];
int  fa[1005];

int  find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
bool  edge_cmp(edge a,edge b)
{
    return a.w<b.w;
}

int n,m;

int cc;



int   kruskal()
{
    int  ans=0;
    sort(e,e+m,edge_cmp);
    for(int i=0;i<m;i++)
    {
       
        
        int x=find(e[i].u);
        int y=find(e[i].v);
        
        if(x!=y)
        {
            fa[x]=y;
            ans+=e[i].w;
            cc--;
        }
    }
    
    return ans;
}

int a[10005];
int b[10005];
int d[105][105];
bool  done[105][105];

void   init()
{
    for(int i=0;i<n;i++)
    {
        fa[i]=i;
    }
    cc=n;
    memset(done, 0, sizeof(done));
}

int main()
{
   
    
    while(cin>>n)
    {
        init();
        int cnt=0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                scanf("%d",&d[i][j]);
             
            }
        int Q;
        cin>>Q;
        
        
        int a,b;
        for(int i=0;i<Q;i++)
        {
            scanf("%d%d",&a,&b);
            d[a-1][b-1]=0;
        }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                
                e[cnt].u=i;
                e[cnt].v=j;
                e[cnt].w=d[i][j];
                cnt++;
            }
        
        m=cnt;

    
        int  ans=kruskal();
        if(cc==1)
        {
            printf("%d\n",ans);
        }
        
        
    }
    
}