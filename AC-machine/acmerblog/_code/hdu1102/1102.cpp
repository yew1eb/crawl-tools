#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

/*
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
*/

int n,m;//n个点，总共有m跳边，单向边
int xh[105][105];
int parent[105];//父亲节点
struct se
{
    int x,y,w;
}edge[5055];

bool emp(se a,se b)
{
    return a.w<b.w;
}

void UFset()
{
    for(int i=0;i<=n;i++)
        parent[i]=i;
}

int find(int x)
{
    int r=x;
    while(x!=parent[x])
        x=parent[x];
    while(r!=x)//剪枝
    {
        int j=parent[r];
        parent[r]=x;
        r=j;
    }
    return x;
}

void Kruskal()
{
    int sum=0,i,count=0;
    UFset();
    for(i=0;i<m;i++)
    {
        int x=edge[i].x;
        int y=edge[i].y;
        int fx=find(x),fy=find(y);
        if(fx!=fy)
        {
            count++;
            parent[fx]=fy;
            sum+=edge[i].w;
            if(count==n-1)
                break;
        }
    }
    cout<<sum<<endl;
}

int main()
{
    int i,j,k,x;
    while(cin>>n)
    {
        m=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                scanf("%d",&x);
                if(i<j)//因为是单向的，所以只用i<j右上角那一边就行了
                {
                    edge[m].x=i;
                    edge[m].y=j;
                    edge[m].w=x;
                    xh[i][j]=m;//记录i和j是第几条边
                    m++;
                }
            }
        cin>>k;
        while(k--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(a>b)//和上面一样，始终保持edge[i][j],i<j
                swap(a,b);
            edge[xh[a][b]].w=0;//已经有路了，w就记为0
        }
        sort(edge,edge+m,emp);//边从小到大排序
        Kruskal();
    }
    return 520;
}