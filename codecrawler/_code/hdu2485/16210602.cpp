#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
#define captype int

const int MAXN = 1010;   //ç¹çæ»æ°
const int MAXM = 400010;    //è¾¹çæ»æ°
const int INF = 1<<30;
struct EDG{
    int to,next;
    captype cap,flow;
} edg[MAXM];
int eid,head[MAXN];
int gap[MAXN];  //æ¯ç§è·ç¦»(æå¯è®¤ä¸ºæ¯é«åº¦)ç¹çä¸ªæ°
int dis[MAXN];  //æ¯ä¸ªç¹å°ç»ç¹eNode çæç­è·ç¦»
int cur[MAXN];  //cur[u] è¡¨ç¤ºä»uç¹åºåå¯æµç» cur[u] å·è¾¹
int pre[MAXN];
int fromeS[MAXN],fromeT[MAXN];

void init(){
    eid=0;
    memset(head,-1,sizeof(head));
}
//æåè¾¹ ä¸ä¸ªåæ°ï¼æ åè¾¹4ä¸ªåæ°
void addEdg(int u,int v,captype c,captype rc=0){
    edg[eid].to=v; edg[eid].next=head[u];
    edg[eid].cap=c; edg[eid].flow=0; head[u]=eid++;

    edg[eid].to=u; edg[eid].next=head[v];
    edg[eid].cap=rc; edg[eid].flow=0; head[v]=eid++;
}
captype maxFlow_sap(int sNode,int eNode, int n,int maxtime){//næ¯åæ¬æºç¹åæ±ç¹çæ»ç¹ä¸ªæ°ï¼è¿ä¸ªä¸å®è¦æ³¨æ
    memset(gap,0,sizeof(gap));
    memset(dis,0,sizeof(dis));
    memcpy(cur,head,sizeof(head));
    memset(fromeS,-1,sizeof(fromeS));
    fromeS[sNode]=0;
    pre[sNode] = -1;
    gap[0]=n;
    captype ans=0;  //æå¤§æµ
    int u=sNode ;
    while(dis[sNode]<n){   //å¤æ­ä»sNodeç¹ææ²¡ææµåä¸ä¸ä¸ªç¸é»çç¹
        if(u==eNode){   //æ¾å°ä¸æ¡å¯å¢æµçè·¯
            captype Min=INF ;
            int inser;
            for(int i=pre[u]; i!=-1; i=pre[edg[i^1].to])    //ä»è¿æ¡å¯å¢æµçè·¯æ¾å°æå¤å¯å¢çæµéMin
            if(Min>edg[i].cap-edg[i].flow){
                Min=edg[i].cap-edg[i].flow;
                inser=i;
            }
            for(int i=pre[u]; i!=-1; i=pre[edg[i^1].to]){
                edg[i].flow+=Min;
                edg[i^1].flow-=Min;  //å¯åæµçè¾¹çæµé
                //printf("<-%d ",edg[i].to);
            }
            ans+=Min;
            u=edg[inser^1].to;
            continue;
        }
        bool flag = false;  //å¤æ­è½å¦ä»uç¹åºåå¯å¾ç¸é»ç¹æµ
        int v , add ;
        for(int i=cur[u]; i!=-1; i=edg[i].next){
            v=edg[i].to; 
            
            //------------------å¯»æ¾ä¸æ¡å¯æ»¡è¶³æ¡ä»¶çå¢å¹¿æµ------------------------
            add=0;
            if(u!=v-n/2) add=1; //å¦æä»u-->væ¯æ­£åæµï¼ä¸ä¸æ¯ç»è¿ç¹èªèº«çåé¨æµï¼åéè¦è±ä¸ä¸ªæ¶é´åä½ï¼å¦ææ¯åæµï¼è¯´æåæµçæµéå¯»æ¾å¶ä»å¯å¢æµè·¯
            if(edg[i].cap>0&&fromeS[u]+add+fromeT[v]>maxtime)
                continue;
            else if(edg[i].cap>0) 
                fromeS[v]=fromeS[u]+add;//printf("(%d,%d,%d) ",u,v,add);
            //---------------------------------------------------------------------
            
            if(edg[i].cap-edg[i].flow>0 && dis[u]==dis[v]+1){
                flag=true;
                cur[u]=pre[v]=i;
                break;
            }
        }
        if(flag){
            u=v;
            continue;
        }
        //å¦æä¸é¢æ²¡ææ¾å°ä¸ä¸ªå¯æµçç¸é»ç¹ï¼åæ¹ååºåç¹uçè·ç¦»ï¼ä¹å¯è®¤ä¸ºæ¯é«åº¦ï¼ä¸ºç¸é»å¯æµç¹çæå°è·ç¦»+1
        int Mind= n;
        for(int i=head[u]; i!=-1; i=edg[i].next){
            v = edg[i].to;  add=0;
            if(u!=v-n/2) add=1;
            if(edg[i].cap>0&&fromeS[u]+add+fromeT[v]>maxtime)
                continue;
            else if(edg[i].cap>0)
                fromeS[v]=fromeS[u]+add;
            if(edg[i].cap-edg[i].flow>0 && Mind>dis[edg[i].to]){
                Mind=dis[edg[i].to];
                cur[u]=i;
            }
        }

        gap[dis[u]]--;
        if(gap[dis[u]]==0) return ans;  //å½dis[u]è¿ç§è·ç¦»çç¹æ²¡æäºï¼ä¹å°±ä¸å¯è½ä»æºç¹åºåæ¾å°ä¸æ¡å¢å¹¿æµè·¯å¾
                                        //å ä¸ºæ±ç¹å°å½åç¹çè·ç¦»åªæä¸ç§ï¼é£ä¹ä»æºç¹å°æ±ç¹å¿ç¶ç»è¿å½åç¹ï¼ç¶èå½åç¹åæ²¡è½æ¾å°å¯æµåçç¹ï¼é£ä¹å¿ç¶æ­æµ
        dis[u]=Mind+1;//å¦ææ¾å°ä¸ä¸ªå¯æµçç¸é»ç¹ï¼åè·ç¦»ä¸ºç¸é»ç¹è·ç¦»+1ï¼å¦ææ¾ä¸å°ï¼åä¸ºn+1
        gap[dis[u]]++;
        if(u!=sNode) u=edg[pre[u]^1].to;  //éä¸æ¡è¾¹
    }//printf("# %d ",fromeS[2]);
    return ans;
}
void spfa(int s,int t,int n){
    queue<int>q;
    int inq[MAXN]={0};
    for(int i=1; i<=n; i++)
        fromeT[i] = INF;
    fromeT[t]=0;
    q.push(t);
    while(!q.empty()){
        int u=q.front(); q.pop();
        inq[u]=0;
        for(int i=head[u]; i!=-1; i=edg[i].next){
            int v=edg[i].to , add = 0;
            if(u!=v+n/2) add=1;
            if(edg[i].cap==0&&fromeT[edg[i].to]>fromeT[u]+add){//é½åååè¾¹
                fromeT[edg[i].to]=fromeT[u]+add;
                if(!inq[v])
                    inq[v]=1,q.push(v);
            }
        }
    }
}
int main(){
    int n,m,k;
    int u,v;
    while(scanf("%d%d%d",&n,&m,&k)>0){
        if(n==0&&m==0&&k==0)
            break;
        init();
        for(int i=1; i<=n; i++)
            addEdg(i,i+n,1);
        while(m--){
            scanf("%d%d",&u,&v);
            addEdg(u+n,v,1);
        }
        spfa(1+n,n,n*2);//printf("%d  ",fromeT[1+n]);
        int ans=maxFlow_sap(1+n , n , n*2, k);
        printf("%d\n",ans);
    }
}
