#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=1000+10;
int n,m,size,index,sum;
int head[MAX],dist[MAX];
int num[MAX];
map<string,int>mp;

struct Edge{
    int v,next;
    Edge(){}
    Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*20];

void Init(int num){
    memset(head,-1,sizeof head);
    size=sum=0;
}

void InsertEdge(int u,int v){
    edge[size]=Edge(v,head[u]);
    head[u]=size++;
}

void BFS(int u){
    queue<int>q;
    q.push(u);
    for(int i=0;i<=n;++i)dist[i]=INF;
    dist[u]=1;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int i=head[u];i != -1;i=edge[i].next){
            int v=edge[i].v,d=dist[u]+1;
            if(d>=dist[v])continue;
            dist[v]=d;
            q.push(v);
            if(dist[v]>sum)sum=dist[v],index=v;
            if(dist[v] == sum && num[v]<num[index])index=v;
        }
    }
}

int main(){
    char name[12],name2[12];
    int u,v;
    while(scanf("%d",&n),n){
        memset(num,0,sizeof num);
        mp.clear();
        Init(n);
        int k=0;
        for(int i=0;i<n;++i){
            scanf("%s",name);
            mp[name]=++k;
        }
        cin>>m;
        for(int i=0;i<m;++i){
            scanf("%s%s",name,name2);
            u=mp[name];
            v=mp[name2];
            InsertEdge(u,v);
            InsertEdge(v,u);
            ++num[u];
            ++num[v];
        }
        index=1;
        //for(int i=1;i<=n;++i)
        BFS(1);
        BFS(index);
        for(int i=1;i<=n;++i)if(dist[i] == INF)sum=0;
        cout<<sum-1<<endl;
    }
    return 0;
}