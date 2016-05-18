#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

#define Maxn 30
#define Maxm 2005

struct Point
{
    int vis;
    int lchild,rchild;
    int child;
    
}point[Maxn];

int vis[Maxn];
int ma[Maxn][Maxn];

vector <int> v[Maxm];
int vnum = 0;
map <int,int> just;
map <int,int> to;

bool cmp(vector<int> a,vector<int> b)
{
    if(a.size() == b.size())
    {
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i]) return a[i]<b[i];
        }    
    }
    else return a.size() < b.size();
}
void print(vector<int> has)
{
    int flag = 1;
    for(int i = has.size()-1;i>0;i--)
    {
        flag = flag & ma[has[i]][has[i-1]];
        ma[has[i]][has[i-1]] = 1;
    }
    if(flag) return;
    for(int i=0;i<has.size();i++)
    {
        v[vnum].push_back(to[has[i]]);
    }
    vnum++;
}
void dfs(int s,vector<int> has)
{
    if(point[s].vis == 0)
    {
        point[s].vis = 1;
        if(point[s].rchild!=-1 && point[s].lchild!=-1)
        {
            vector<int> t1 = has;
            t1.push_back(point[s].rchild);
            dfs(point[s].rchild,t1);
            vector<int> t2 = has;
            t2.push_back(point[s].lchild);
            dfs(point[s].lchild,t2);
        }
        else if(point[s].child!=-1)
        {
            vector<int> t3 = has;
            t3.push_back(point[s].child);
            dfs(point[s].child,t3);
        }
        else print(has);
        point[s].vis = 0;
    }
    else print(has);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    int s;
    char str[20];
    int a,b;
    char d;
    while(scanf(" %d",&s)!=EOF)
    {
        for(int i=0;i<Maxn;i++)
        {
            point[i].vis = 0;
            point[i].lchild = point[i].rchild = point[i].child = -1;
        }
        memset(ma,0,sizeof(ma));
        for(int i=0;i<Maxm;i++)
        {
            v[i].clear();
        }
        vnum = 0;
        just.clear();
        to.clear();
        int hh = 0;
        if(just.find(s) == just.end()) just[s] = ++hh;
        to[just[s]] = s;
        s = just[s];
        while(scanf(" %s",str)!=EOF && str[0]!='E')
        {
            sscanf(str,"%d->%d,%c",&a,&b,&d);
            if(just.find(a) == just.end()) just[a] = ++hh;
            if(just.find(b) == just.end()) just[b] = ++hh;
            to[just[a]] = a;
            a = just[a];
            to[just[b]] = b;
            b = just[b];
            if(d == 'T') point[a].lchild = b;
            else if(d == 'F') point[a].rchild = b;
            else point[a].child = b;
        }
        vector <int> has;
        has.push_back(s);
        dfs(s,has);
        sort(v,v+vnum,cmp);
        printf("CC=%d\n",vnum);
        for(int i=0;i<vnum;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                if(j == v[i].size()-1) printf("%d\n",v[i][j]);
                else printf("%d,",v[i][j]);
            }
        }
    }
    return 0;
}