#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<cstdio>
#define maxn 30000+5 
using namespace std;
vector<vector<int> >mapp;
//char visit[maxn][maxn];
int n,m;
int head[maxn];
int re[maxn]; 
void topo()
{
    int t=n;
    priority_queue<int>root;
    for(int i=1;i<=n;i++)
    {
        if(!head[i]) root.push(i); 
    }
    while(root.size())
    {
        int x=root.top();
        re[--t]=x;
        root.pop();
        for(int i=0;i<mapp[x].size();i++)
        {
            head[mapp[x][i]]--;
            if(!head[mapp[x][i]]) root.push(mapp[x][i]);
        }
    }
}
void print()
{
    printf("%d",re[0]);
    for(int i=1;;i++)
    {
        if(!re[i]){break;}
        printf(" %d",re[i]);
    }
    printf("\n");
}
int main()
{
    int t;
    cin>>t;
    cin.sync_with_stdio(false);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        mapp.resize(n+1);
        for(int i=0;i<n+1;i++) head[i]=0,re[i]=0,mapp[i].clear();
        int x,y;
        while(m--)
        {
            scanf("%d%d",&x,&y);
            mapp[y].push_back(x); 
            head[x]++;
        }
        topo();
        print();
    }
    return 0;
}  