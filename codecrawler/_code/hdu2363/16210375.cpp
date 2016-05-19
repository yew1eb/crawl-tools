#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int INF = 0x7fffffff;
const int VN  = 120;
const int EN  = 10005;

int n;
int m;
int size;
int head[VN];
int h[VN];
int order[VN];
int d[VN];
int up;  // ä¸ç
int low; // ä¸ç
bool inq[VN];

struct Edge{
    int v,next;
    int w;
}E[EN];

void addEdge(int u,int v,int w){
    E[size].v=v;
    E[size].w=w;
    E[size].next=head[u];
    head[u]=size++;
}

int SPFA(int src){
    memset(inq, 0, sizeof(inq));
    for(int i=0; i<=n; ++i)d[i]=INF;
    d[src]=0;
    if(h[src]<low || h[src]>up) return INF;  // èµ·ç¹ä¸ç¬¦åæ¡ä»¶ç´æ¥è¿åINF
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int u=q.front();  q.pop();
        if(h[u]<low || h[u]>up) continue;  // æé¤ç¬¦ååéå¶ç
        inq[u] = false;
        for(int e=head[u]; e!=-1; e=E[e].next)if(h[E[e].v]>=low&&h[E[e].v]<=up){//æéå¶
            int tmp=d[u]+E[e].w;
            if(d[E[e].v] > tmp){
                d[E[e].v] = tmp;
                if(!inq[E[e].v]){
                    inq[E[e].v]=true;
                    q.push(E[e].v);
                }
            }
        }
    }
    return d[n];
}

int main(){
    int T, u, v;
    int len, Min, Max;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        size=0;
        memset(head, -1, sizeof(head));
        for(int i=1; i<=n; ++i){
            scanf("%d", &h[i]);
            order[i]=h[i];
            if(h[i]<Min)Min=h[i];
            if(h[i]>Max)Max=h[i];
        }
        for(int i=0; i<m; ++i){
            scanf("%d%d%d",&u,&v,&len);
            addEdge(u,v,len);
            addEdge(v,u,len);
        } 

        sort(order+1, order+1+n);
        int left=0, right=Max-Min+1, mid;
        int ans, dif=INF, minlen=INF;
        while(left < right){ // äºåâé«åº¦å·®â
            mid = (left+right)>>1;
            bool flag=false;
            for(int i=1; i<=n; ++i){ // æä¸¾æä½æµ·æ
                low=order[i];
                up=order[i]+mid; // å¾å°æµ·æä¸é
                int tmp=SPFA(1);
                if(tmp!=INF){
                    flag=true;
                    ans=tmp;
                    break;
                }
            } 
            if(flag){
                right=mid;
                if(mid<dif){
                    dif=mid;
                    minlen=ans;
                }
                else if(mid==dif && ans<minlen){
                    minlen=ans;
                }
            }
            else{
                left=mid+1;
            } 
        }
        printf("%d %d\n", dif, minlen);
    }
    return 0;
}