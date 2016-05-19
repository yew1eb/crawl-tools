#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
//å°±æ¯è¿å¥äºï¼çå¿äº®åï¼ï¼ï¼
#pragma comment(linker, "/STACK:1024000000,1024000000")

#define find_min(a,b) a<b?a:b
using namespace std;

const int N = 100010;
const int MAX = 10000000;

struct Edge{
    int s,e,next;
    int v;
}edge[2*N];

int n,e_num,head[N],d[N],sp,tp;

void AddEdge(int a,int b,int c){
    edge[e_num].s=a; edge[e_num].e=b; edge[e_num].v=c;
    edge[e_num].next=head[a]; head[a]=e_num++;

    edge[e_num].s=b; edge[e_num].e=a; edge[e_num].v=c;
    edge[e_num].next=head[b]; head[b]=e_num++;
}

int bfs(){
    queue <int> q;
    memset(d,-1,sizeof(d));
    d[sp]=0;
    q.push(sp);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=head[cur];i!=-1;i=edge[i].next){
            int u=edge[i].e;
            if(d[u]==-1 && edge[i].v>0){//æ²¡ææ è®°,ä¸å¯è¡æµå¤§äº0
                d[u]=d[cur]+1;
                q.push(u);
            }
        }
    }
    return d[tp] != -1;//æ±ç¹æ¯å¦æåæ å·,ä¹å°±æ¯è¯´æ¯å¦æ¾å°å¢å¹¿è·¯
}

int dfs(int a,int b){//aä¸ºèµ·ç¹
    double r=0;
    if(a==tp)return b;
    for(int i=head[a];i!=-1 && r<b;i=edge[i].next){
        int u=edge[i].e;
        if(edge[i].v>0 && d[u]==d[a]+1){
            double x=find_min(edge[i].v,b-r);
            x=dfs(u,x);
            r+=x;
            edge[i].v-=x;
            edge[i^1].v+=x;
        }
    }
    if(!r)d[a]=-2;
    return r;
}

int dinic(int sp,int tp){
    int total=0,t;
    while(bfs()){
        while(t=dfs(sp,MAX))
        total+=t;
    }
    return total;
}

int main()
{
    int t,i,n,m,a,b,c;
    int x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int min_x=MAX,max_x=-MAX;
        int min_id=1,max_id=1;
        for(i=1;i<=n;i++){
            scanf("%d%d",&x,&y);
            if(x<min_x){
                min_x = x;
                min_id = i;
            }
            if(x>max_x){
                max_x = x;
                max_id = i;
            }
        }

        sp=min_id; tp=max_id;

        e_num=0;
        memset(head,-1,sizeof(head));
        for(i=1;i<=m;i++){
            scanf("%d%d%d",&a,&b,&c);
            AddEdge(a,b,c);
        }

        int ans=dinic(sp,tp);
        printf("%d\n",ans);
    }
    return 0;
}