/*
http://hi.baidu.com/bin183/blog/item/45c37950ece4475f1138c273.html
æå°æ å½¢å¾(æåå¾çæå°çææ )ææ³ï¼å¯¹äºææ ¹çå¾ï¼é¦åæ±åºæ¯ä¸ªç¹è´¹ç¨æå°çåé©±è¾¹ï¼å¦æè¿äºåé©±è¾¹ææäºåè·¯ï¼
       é£ä¹ç¼©ç¹ï¼åæ¶ä»¥è¿ä¸ªå¤§ç¹ä¸­çæä¸ªç¹ä¸ºç»ç¹çè¾¹çæå¼åå»è¿ä¸ªç¹å¨åä¸­çåé©±è¾¹çæå¼ãä¸æ­éå¤è¿è¿ç¨ï¼ç´è³æ²¡æåè·¯ã
    å¯¹äºæ²¡ææ ¹çå¾ï¼å¦å ä¸ä¸ªæ ¹ï¼æå¼ä¸ºæææå¼çåï¼è¿æ ·çè¯ï¼ä¸æ ¹ç¸è¿çè¾¹åªä¼éæ©ä¸æ¡ï¼æä»¥æ±çå¼ååå»å³å¯ã
é¢æï¼æä¸äºæåºï¼ç°è¦æ±ä½¿æææåºé½ææ°´çæå°è´¹ç¨ãæ¯ä¸ªæåºå¯ä»¥éè¿æäºï¼ä»å«çæåºææ°´ç®¡çæ¹å¼ä½¿æåºææ°´ã
åæï¼å ä¸ºæ¯ä¸ªæåºé½å¯ä»¥æäºï¼æä»¥æ²¡æä¸å¯è½çæåµãç¶åæ°å ä¸ä¸ªç»ç¹ï¼è¡¨ç¤ºæäºçè´¹ç¨ï¼èååæ ¹æ®è¾å¥æå¾ãæ±æå°æ å½¢å¾å³å¯
å ä¸ºæ°æ®è¾å¤§ï¼è¦ç¨é»æ¥è¡¨çå®ç°ãæ¶é´å¤æåº¦ä¸ºO(V*E)
*/
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<iostream>

const int maxn=1100;
const int maxm=1100000;
const int maxint=0x3fffffff;

struct edge
{
    int u,v,w;
    edge(){}
    edge(int u1,int v1,int w1):u(u1),v(v1),w(w1){}
}e[maxm];
int root,n,edgeNum,vis[maxn],pre[maxn],belong[maxn],in[maxn];
int a[maxn],b[maxn],c[maxn];
int Abs(int a)
{
    return a>0? a:-a;
}
int Dis(int i,int j)
{
    return Abs(a[i]-a[j])+Abs(b[i]-b[j])+Abs(c[i]-c[j]);
}

int solve()
{
    int i,j,k,num,sum=0;

    n++;//å¼å§æ¯0è³nï¼n+1ä¸ªç¹
    while(1)//ä¸æ­ç¼©ç¹ï¼ç´è³ä¸å«å
    {
        for(i=0;i<n;i++)
            in[i]=maxint;
        for(i=0;i<edgeNum;i++)//æ¾æ¯ä¸ªç¹çåé©±è¾¹
        {
            if(in[e[i].v]>e[i].w&&e[i].u!=e[i].v)
            {
                pre[e[i].v]=e[i].u;
                in[e[i].v]=e[i].w;
            }
        }

        memset(vis,-1,sizeof(vis));
        memset(belong,-1,sizeof(belong));
        in[root]=0;
        for(num=0,i=0;i<n;i++)
        {
            sum+=in[i];//å ä¸æ¯ä¸ªç¹çåé©±è¾¹
            j=i;
            while(vis[j]!=i&&belong[j]==-1&&j!=root)//å¤æ­æ¯å¦æå
            {
                vis[j]=i;
                j=pre[j];
            }
            if(vis[j]==i)//jä¸å®å¨åä¸ï¼èiä¸ä¸å®
            {
                for(k=pre[j];k!=j;k=pre[k])//ç¬¬numä¸ªåï¼ç¼©ç¹
                    belong[k]=num;
                belong[j]=num++;
            }
        }

        if(!num) return sum;//ä¸å«åï¼åç»æ
        for(i=0;i<n;i++)
            if(belong[i]==-1)//ä¸å±äºæä¸ªåçæ¯ç¬ç«çç¹
                belong[i]=num++;

        for(i=0;i<edgeNum;i++)
        {
            int j=e[i].v;
            e[i].u=belong[e[i].u];
            e[i].v=belong[e[i].v];
            e[i].w-=in[j];//æ³¨ææ¯åå»ç¼©ç¹åçåé©±è¾¹ï¼èä¸æ¯in[e[i].v]
        }
        n=num;
        root=belong[root];
    }
    return sum;
}
int main()
{
    int x,y,z,i,j,k,ii,d;
    while(scanf("%d%d%d%d",&n,&x,&y,&z)!=EOF)
    {
        if(!n&&!x&&!y&&!z) break;
        for(edgeNum=0,i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            e[edgeNum++]=edge(0,i,c[i]*x);
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&k);
            while(k--)
            {
                scanf("%d",&ii);
                if(i==ii) continue;
                d=Dis(i,ii);
                if(c[i]>=c[ii])//iåiiæä¾æ°´
                    e[edgeNum++]=edge(i,ii,d*y);
                else
                    e[edgeNum++]=edge(i,ii,d*y+z);
            }
        }

        root=0;
        printf("%d\n",solve());
    }
    return 0;
}