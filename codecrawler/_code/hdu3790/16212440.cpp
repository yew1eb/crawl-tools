#include<stdio.h>
#define FINITY 0x7fffffff
#define M 1005
int n;//å¾çå¤§å°
typedef struct edge_t{
    int d;//è·ç¦»
    int p;//è±è´¹
}edge_t;
edge_t m[M][M];
void dijkstra(int v0,int d[M],int p[M]){
    int fin[M];//è®°å½èç¹æ¯å¦å å¥äºSéå
    int i,j,k,v=0,min,min_p;
    /**åå§å*/
    for(;v<n;v++){
        fin[v]=0;//0è¡¨ç¤ºvèç¹æªå å¥Séå
        d[v]=m[v0][v].d;//åå§åè·ç¦»è®°å½æ°ç»
        p[v]=m[v0][v].p;//åå§åè±è´¹è®°å½æ°ç»
    }
    fin[v0]=1;//è¡¨ç¤ºv0èç¹å å¥Séå
    d[v0]=0;//åå§åv0å°v0çè·ç¦»ä¸º0
    /**ä¾æ¬¡æ¾åºn-1ä¸ªèç¹å å¥Séå*/
    for(i=1;i<n;i++){
        min_p=min=FINITY;
        for(k=0;k<n;k++){//æ¾æå°è¾¹èç¹
            if(!fin[k]&&d[k]<min){//!fin[k]è¡¨ç¤ºkè¿å¨V-Sä¸­
                v=k;
                min=d[k];
                min_p=p[k];
            }
        }
        if(min==FINITY)return;
        fin[v]=1;//vå å¥S
        /**ä¿®æ¹Sä¸V-Sä¸­åèç¹çè·ç¦»*/
        for(k=0;k<n;k++){
            if(!fin[k]&&m[v][k].d!=FINITY){
                if(min+m[v][k].d<d[k]){
                    d[k]=min+m[v][k].d;
                    p[k]=min_p+m[v][k].p;
                }
                else if(min+m[v][k].d==d[k]&&p[k]>min_p+m[v][k].p){
                    p[k]=min_p+m[v][k].p;
                }
            }
        }
    }
}
int main(){
    int i,j,t;
    int dis[M],pp[M];
    int x,a,b,d,p,max[M],Min;
    while(scanf("%d%d",&n,&x)&&(n||x)){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                m[i][j].d=m[i][j].p=FINITY;
        for(i=0;i<x;i++){
            scanf("%d%d%d%d",&a,&b,&d,&p);
            if(m[a-1][b-1].d>d){
                m[b-1][a-1].d=m[a-1][b-1].d=d;
                m[b-1][a-1].p=m[a-1][b-1].p=p;
            }
            else if(m[a-1][b-1].d==d&&m[a-1][b-1].p>p){
                m[b-1][a-1].p=m[a-1][b-1].p=p;
            }
        }
        scanf("%d%d",&a,&b);
        dijkstra(a-1,dis,pp);
        printf("%d %d\n",dis[b-1],pp[b-1]);
    }
}
