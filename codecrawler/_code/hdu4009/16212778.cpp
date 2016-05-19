/*
å¾è£¸çæ±åç®æ³ï¼åææ¨å¤©æ¯èµåæ²¡çè¿æ±åç®æ³ï¼æ©é¢å¤§å­~~
æ½è±¡ä¸ä¸ªè¶çº§èµ·ç¹ï¼è¿æ¹ç¹å°æ¯ä¸ªç¹çååè¾¹ï¼è¾¹æä¸ºç¹èªèº«çå»ºäºçä»£ä»·
å¦æå¯ä»¥ä»iè¿æ°´ç®¡å°vï¼å»ºä¸æ¡iå°vçåé¡¹è¾¹ï¼è¾¹æä¸ºä¿®æ°´ç®¡çä»£ä»·
ç¶åå°±æ¯ç¨æ±åç®æ³æ±æå°æ å½¢å¾äºãæ±åç®æ³è¯¦è§ï¼http://blog.csdn.net/wsniyufang/article/details/6747406
*/
#include <cstdio>
#include <iostream>
#include<queue>
#include<set>
#include<ctime>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
const double eps=1e-10;
#define M 1009
#define type __int64
const type inf=(1LL)<<60;
struct point 
{
    int x,y,h;
}p[M];

struct Node{
    int u , v;
    type cost;
}E[M*M+5];
int pre[M],ID[M],vis[M];
type In[M]; 
int n,X,Y,Z;
type Directed_MST(int root,int NV,int NE) {
    type ret = 0;
    while(true) {
        //1.æ¾æå°å¥è¾¹
        for(int i=0;i<NV;i++) In[i] = inf;
        for(int i=0;i<NE;i++){
            int u = E[i].u;
            int v = E[i].v;
            if(E[i].cost < In[v] && u != v) {
                pre[v] = u;
                In[v] = E[i].cost;
            }
        }
        for(int i=0;i<NV;i++) {
            if(i == root) continue;
            if(In[i] == inf)    return -1;//é¤äºè·ä»¥å¤æç¹æ²¡æå¥è¾¹,åæ ¹æ æ³å°è¾¾å®
        }
        //2.æ¾ç¯
        int cntnode = 0;
    memset(ID,-1,sizeof(ID));
    memset(vis,-1,sizeof(vis));
        In[root] = 0;
        for(int i=0;i<NV;i++) {//æ è®°æ¯ä¸ªç¯
            ret += In[i];
            int v = i;
            while(vis[v] != i && ID[v] == -1 && v != root) {
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && ID[v] == -1) {
                for(int u = pre[v] ; u != v ; u = pre[u]) {
                    ID[u] = cntnode;
                }
                ID[v] = cntnode ++;
            }
        }
        if(cntnode == 0)    break;//æ ç¯
        for(int i=0;i<NV;i++) if(ID[i] == -1) {
            ID[i] = cntnode ++;
        }
        //3.ç¼©ç¹,éæ°æ è®°
        for(int i=0;i<NE;i++) {
            int v = E[i].v;
            E[i].u = ID[E[i].u];
            E[i].v = ID[E[i].v];
            if(E[i].u != E[i].v) {
                E[i].cost -= In[v];
            }
        }
        NV = cntnode;
        root = ID[root];
    }
    return ret;
}
type get_cost(point a,point b)
{
    type cost=(fabs(a.x-b.x)+fabs(a.y-b.y)+fabs(a.h-b.h))*Y;
    if(a.h<b.h)
    cost+=Z;
    return cost;
}
int main()
{
    int tmp,num,v;
    type sum;
    while(scanf("%d%d%d%d",&n,&X,&Y,&Z),n+X+Y+Z)
    {
        num=0;
        sum=0;
        for(int i=1;i<=n;i++)
        scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].h);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&tmp);
            while(tmp--)
            {
                scanf("%d",&v);
                E[num].u=i;
                E[num].v=v;
                if(v!=i)
                E[num].cost=get_cost(p[i],p[v]);
                else 
                E[num].cost=inf;
                sum+=E[num].cost;
                num++;
            }
        }
        sum++;
        for(int i=1;i<=n;i++)
        {
            E[num].u=0;
            E[num].v=i;
            E[num].cost=p[i].h*X;
            num++;
        }
        type ans=Directed_MST(0,n+1,num);
        if(ans==-1)
        puts("poor XiaoA");
        else 
        printf("%I64d\n",ans);
    }
    return 0;
}