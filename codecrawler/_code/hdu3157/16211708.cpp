/*
hdu 3157
poj 3801
é¢æï¼ä¸ä¸ªçµè·¯æ¿ï¼ä¸é¢æNä¸ªæ¥çº¿æ±(æ å·1~N)   è¿æä¸¤ä¸ªçµæºæ¥çº¿æ±  +  -
ç¶åæ¯ ç»åºMä¸ªé¨ä»¶æ­£è´æçæ¥çº¿æ±åæå°çµæµ
æ±ä¸ä¸ªå¯ä»¥è®©ææé¨ä»¶æ­£å¸¸å·¥ä½çæ»çµæµ  æ²¡æåè¾åºimpossible

å¶å®å°±æ¯ä¸ä¸ª ææºæ± æä¸ä¸ç æå°æµ é®é¢

å¤çææºæ±æä¸ä¸çæå¤§æµé®é¢æ¯ï¼
1.æé éå ç½ç»
2.å¯¹ssãttæ±æå¤§æµ(ssãttæ»¡æµåæè§£)
3.è¥æè§£ï¼å¯¹sãtæ±æå¤§æµ

èææºæ±æä¸ä¸çæå°æµé®é¢åæ¯ï¼
1.æé éå ç½ç»(ä¸æ·»å [t,s]è¾¹)
2.å¯¹ssãttæ±æå¤§æµ
3.æ·»å [t,s]è¾¹
4.å¯¹ssãttæ±æå¤§æµ
5.è¥ssãttæ»¡æµï¼å[t,s]çæµéå°±æ¯æå°æµ

è¿ä¸ªä»£ç å¤§é¨åé½æ¯ä»å«çé¢ä¸æè¿æ¥çï¼æ³¨éæç¹ä¹±
*/
#include<stdio.h>
#include<string.h>
#define inf 0x7fffffff
struct edge//è¾¹  
{  
    int u,v,f,next,b,c;//è¾¹ç åèç¹ åèç¹ å¯ç¨æµ ä¸æ¡è¾¹çç¼å·  åæ¥è¾¹ä¸æµçä¸ä¸ç  
}e[1500];  
int head[70],in[70],s,t,ss,tt,yong,sum;
int n,m;
void ini()
{
    memset(head,-1,sizeof(head));
    yong=0;
    memset(in,0,sizeof(in));
    s=0,t=n+1,ss=t+1,tt=ss+1;//åèç¹ç¼å·çå®æ
    sum=0;
}
void adde(int from,int to,int xia,int shang)//å è¾¹  
{    //å è¾¹  
    e[yong].u=from,e[yong].v=to,e[yong].f=shang-xia,e[yong].b=xia,e[yong].c=shang;  
    e[yong].next=head[from],head[from]=yong++;  
    //åæ¶å å®çéè¾¹  
    e[yong].u=to,e[yong].v=from,e[yong].f=0,e[yong].b=xia,e[yong].c=shang;  
    e[yong].next=head[to],head[to]=yong++;  
} 
void build()
{
    int i;  
    for(i=0;i<=t;++i)  
    {  
        if(in[i]>0)  
            adde(ss,i,0,in[i]);  
        else  
        {  
            adde(i,tt,0,-in[i]);  
            sum+=(-in[i]);  
        }  
    } 
}
int d[1000],num[1000];
int min(int a,int b){return a<b?a:b;}  
int sap_gap(int u,int f,int s,int t)//éå½sap  
{  
    if(u==t)  
        return f;  
    int i,v,mind=t,last=f,cost;  
    for(i=head[u];i!=-1;i=e[i].next)  
    {  
        v=e[i].v;  
        int flow=e[i].f;  
        if(flow>0)//åèæ¨¡çåçæ¶åæflowåæäºf  
        {  
            if(d[u]==d[v]+1)  
            {  
                cost=sap_gap(v,min(last,flow),s,t);  
                e[i].f-=cost;  
                e[i^1].f+=cost;  
                last-=cost;  
  
                if(d[s]>=t+1)  
                    return f-last;  
  
                if(last==0)  
                    break;  
            }  
            if(d[v]<mind)  
                mind=d[v];  
        }  
    }  
  
    if(last==f)  
    {  
        --num[d[u]];  
        if(num[d[u]]==0)  
            d[s]=t+1;  
        d[u]=mind+1;  
        ++num[d[u]];  
    }  
    return f-last;  
}  
int max_f(int s,int t)
{
    int f=0;  
    memset(d,0,sizeof(d));  
    memset(num,0,sizeof(num));  
    for(num[s]=t+1;d[s]<t+1;)  
        f+=sap_gap(s,inf,s,t);  
    return f; 
}
int main()
{
    int i,dat,u,v,f1,f2,p;
    char from[10],to[10];
    while(scanf("%d%d",&n,&m),n+m)
    {
        ini();
        for(i=1;i<=m;++i)
        {
            scanf("%s%s%d",from,to,&dat);
            if(from[0]=='+') u=s;
            else sscanf(from,"%d",&u);
            if(to[0]=='-') v=t;
            else sscanf(to,"%d",&v);
            adde(u,v,dat,inf);
            in[u]-=dat,in[v]+=dat;
        }
        build();

        f1=max_f(ss,tt);
        p=yong;
        adde(t,s,0,inf);
        f2=max_f(ss,tt);
        if(f1+f2!=sum) printf("impossible\n");
        else printf("%d\n",e[p^1].f);
    }
    return 0;
}