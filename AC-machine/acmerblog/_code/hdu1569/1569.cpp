/*
Problem : 1569-方格取数(2)      Judge Status : Accepted
RunId : 6039695    Language : G++    Author : 2010201211
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define E 30000
#define V 2600
#define inf 0x3f3f3f3f
struct Edge
{
    int u,v,c,next;
}edge[E];
int n,m,cnt;
int dist[V];
int head[V];
int que[V];
int sta[V];

int film[25][10];
int week,sum,s,t;

void init(){
    cnt=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int c){
    edge[cnt].u=u;edge[cnt].v=v;edge[cnt].c=c;
    edge[cnt].next=head[u];head[u]=cnt++;

    edge[cnt].u=v;edge[cnt].v=u;edge[cnt].c=0;
    edge[cnt].next=head[v];head[v]=cnt++;
}

int dinic(int s,int t){
    int ans=0;
    while(true){
        int left,right,u,v;

        memset(dist,-1,sizeof(dist));
        left=right=0;
        que[right++]=s;
        dist[s]=0;

        while(left<right){//bfs构造层次网络
            u=que[left++];
            for(int k=head[u];k!=-1;k=edge[k].next){
                u=edge[k].u;
                v=edge[k].v;
                if(edge[k].c>0 && dist[v]==-1){
                    dist[v]=dist[u]+1;
                    que[right++]=v;
                    /*if(v==t){
                        left=right;
                        break;
                    }*/
                }
            }
        }

        if(dist[t]==-1) break;//汇点不在层次网络中,算法结束.

        int top=0;
        int now=s;

        while(true){//层次图中进行一次dfs增广
            if(now!=t){//dfs未到汇点
                int k;
                for(k=head[now];k!=-1;k=edge[k].next){//判断now之后是否有可用点(入度是否为0)
                    if(edge[k].c>0 && dist[edge[k].u]+1==dist[edge[k].v]) break;
                }
                if(k!=-1){//如果now之后有可用点(入度>0)
                    //cout << top << endl;
                    sta[top++]=k;//边入栈
                    now=edge[k].v;
                }
                else{//now之后没有可用点
                    if(top==0) break;
                    dist[edge[sta[--top]].v]=-1;//从p和层次图中删除点u以及u连接的所有边
                    now=edge[sta[top]].u;
                }

            }
            else{//dfs到汇点
                int flow=inf,ebreak;
                //(1)增广p
                for(int i=0;i<top;i++){
                    if(flow>edge[sta[i]].c){
                        flow=edge[sta[i]].c;
                        ebreak=i;
                    }
                }
                ans+=flow;
                for(int i=0;i<top;i++){
                    edge[sta[i]].c-=flow;//正向边减流
                    edge[sta[i]^1].c+=flow;//反向边加流
                }
                //(2)退至p中从源点可到达的最后一个顶点
                now=edge[sta[ebreak]].u;
                top=ebreak;
            }
        }

    }
    return ans;
}
int main(){
    int n,m,i,j,c,sum;
    while(scanf("%d%d",&n,&m)!=EOF){
        init();
        int src=0;
        int end=n*m+1;
        sum=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++){
                scanf("%d",&c);
                sum+=c;
                if((i+j)%2==0){
                    addedge(src,(i-1)*m+j,c);
                    if(i>1) addedge((i-1)*m+j,(i-2)*m+j,inf);
                    if(j>1) addedge((i-1)*m+j,(i-1)*m+j-1,inf);
                    if(i<n) addedge((i-1)*m+j,(i)*m+j,inf);
                    if(j<m) addedge((i-1)*m+j,(i-1)*m+j+1,inf);
                }
                else addedge((i-1)*m+j,end,c);
            }
        int res=dinic(src,end);
        printf("%d\n",sum-res);
    }
}