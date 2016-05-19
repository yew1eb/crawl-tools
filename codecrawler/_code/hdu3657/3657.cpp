#include<iostream>
using namespace std;
#define N 2550
#define M 2000000
#define inf 0x7fffffff
struct Graph{    
    struct node{    
        int v,next,flow;    
        node(){}; 
        node(int a,int b,int c):next(a),v(b),flow(c){};    
    }E[M];    
    int pre[N];   
    int head[N];    
    int cur[N];  
    int dis[N];   
    int NV,NE;    
    int gap[N];  
    void init(int n){    
        memset(head,-1,sizeof(head));    
        NE=0;    
        NV=n;    
    }    
    void insert(int u,int v,int w){    
        E[NE]=node(head[u],v,w);    
        head[u]=NE++;    
        E[NE]=node(head[v],u,0);  
        head[v]=NE++;  
    }    
    int SAP(int s,int t){  
        memset(dis,0,sizeof(dis));  
        memset(gap,0,sizeof(gap));  
        for(int i=0;i<NV;i++)   
            cur[i]=head[i];  
        int u=pre[s]=s;  
        int maxflow=0,aug=INT_MAX;  
        gap[0]=NV;  
        while(dis[s]<NV){  
    loop:   for(int &i=cur[u];i!=-1;i=E[i].next){  
                int v=E[i].v;  
                if(E[i].flow&&dis[u]==dis[v]+1){  
                    if(aug>E[i].flow)  
                        aug=E[i].flow;  
                    pre[v]=u;  
                    u=v;  
                    if(v==t){  
                        maxflow+=aug;  
                        for(u=pre[u];v!=s;v=u,u=pre[u]){  
                            E[cur[u]].flow-=aug;  
                            E[cur[u]^1].flow+=aug;  
                        }  
                        aug=INT_MAX;  
                    }  
                    goto loop;  
                }  
            }  
            int mindis=NV;  
            for(int i=head[u];i!=-1;i=E[i].next){  
                int v=E[i].v;  
                if(E[i].flow&&mindis>dis[v]){  
                    cur[u]=i;  
                    mindis=dis[v];  
                }  
            }  
            if(--gap[dis[u]]==0)  
                break;  
            gap[dis[u]=mindis+1]++;  
            u=pre[u];  
        }  
        return maxflow;  
    }  
}G;
int map[55][55];
int main(void){
	int n,m,k;
	while(~scanf("%d%d%d",&n,&m,&k)){
		int beg=n*m+1,end=beg+1;
		G.init(end);
		int s=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				scanf("%d",&map[i][j]);
				s+=map[i][j];
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				int u=(i-1)*m+j;
				if((i+j)%2){
					G.insert(beg,u,map[i][j]);
					if(i>1) G.insert(u,u-m,2*(map[i][j]&map[i-1][j]));
					if(j>1) G.insert(u,u-1,2*(map[i][j]&map[i][j-1]));
					if(i<n) G.insert(u,u+m,2*(map[i][j]&map[i+1][j]));
					if(j<m) G.insert(u,u+1,2*(map[i][j]&map[i][j+1]));
				}
				else
					G.insert(u,end,map[i][j]);
			}
		while(k--){
			int x,y;
			scanf("%d%d",&x,&y);
			int u=(x-1)*m+y;
			if((x+y)%2){
				for(int i=G.head[beg];i!=-1;i=G.E[i].next)
					if(G.E[i].v==u){
						G.E[i].flow=inf;
						break;
					}
			}
			else{
				for(int i=G.head[u];i!=-1;i=G.E[i].next)
					if(G.E[i].v==end){
						G.E[i].flow=inf;
						break;
					}
			}
		}
		printf("%d\n",s-G.SAP(beg,end));
	}
}
			