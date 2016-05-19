#include<iostream>
#include<string>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
#define MAXN 10005
#define MAXM 200005
#define LL long long
const double INF=1e16;
const double eps = 1e-10;
int n,m,d;
struct node
{
    node(int st=0,int en=0,int next=0,int d=0,double len=0)
    {
        this->st=st;
        this->en=en;
        this->next=next;
        this->d=d;
        this->len=len;
    }
    int st,en,next,d;
    double len;
};
struct node E[MAXM],e[MAXM];//å£°æå­è¾¹æ°ç»ï¼æ­£åè¾¹åæ¹åè¾¹ï¼
struct point
{
    double x,y,z;
}po[MAXN];
double dis1[MAXN],dis2[MAXN];
int vis[MAXN];
int p[MAXN],num,numf,pp[MAXN];
double abss(double x)
{
    if(x<0)
        return -x;
    return x;
}
double min(double x,double y)
{
    return x<y?x:y;
}
double length(point p1,point p2)
{
    double ans;
    ans=(p1.x-p2.x)*(p1.x-p2.x);
    ans+=(p1.y-p2.y)*(p1.y-p2.y);
    ans+=(p1.z-p2.z)*(p1.z-p2.z);
    ans=sqrt(ans);
    return  ans;
}
double length1(point p1,point p2)
{
    double ans;
    ans=(p1.x-p2.x)*(p1.x-p2.x);
    ans+=(p1.y-p2.y)*(p1.y-p2.y);
    ans=sqrt(ans);
    return  ans;
}
int level(point p1,point p2)
{
    if(p1.z>=p2.z)
        return 0;
    double len=length1(p1,p2);
    double high=abss(p1.z-p2.z);
    int ans=(int)((high/len)*100.0);

    return ans;

}
 void add(int st,int en)
{
    E[num].st=st;
    E[num].en=en;
    E[num].next=p[st];
    E[num].len=length(po[st],po[en]);
   //cout<<st<<"->"<<en<<" d:"<<E[num].d<<" len:"<<E[num].len<<endl;
    p[st]=num++;
}
void ADD(int st,int en)
{
    e[numf].st=st;
    e[numf].en=en;
    e[numf].next=pp[st];
    e[numf].len=length(po[st],po[en]);
    pp[st]=numf++;
}
void spfa(int st,double *dis,struct node *ee,int *P)
{
    int i;
    queue<int>q;
    for(i=0;i<MAXN;i++)
          dis[i]=INF;
    dis[st]=0;
    memset(vis,0,sizeof(vis));
    q.push(st);
    vis[st]=1;
    while(!q.empty())
    {
        int tx=q.front();
        q.pop();
        vis[tx]=0;
        for(i=P[tx];i!=-1;i=ee[i].next)
        {
            int enn=ee[i].en;
            double len=ee[i].len;
            if(dis[enn]>dis[tx]+len)
            {

                dis[enn]=dis[tx]+len;
                if(!vis[enn])
                {
                    vis[enn]=1;
                    q.push(enn);
                }
            }
        }
    }
}
int u[MAXM],v[MAXM],a[MAXM],cnt;
int main()
{
    int i;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        memset(p,-1,sizeof(p));
        num=0;
        numf=0;
        memset(pp,-1,sizeof(pp));
        for(i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf",&po[i].x,&po[i].y,&po[i].z);
        }

        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&u[i],&v[i]);
        }
        int st,en;
        scanf("%d%d%d",&st,&en,&d);
        cnt=0;
        for(i=1;i<=m;i++)
        {
            int dd=level(po[u[i]],po[v[i]]);
            if(dd<=d)
            {
                add(u[i],v[i]);//æ­£å
                ADD(v[i],u[i]);//ååè¾¹
            }
            if(dd==d) a[++cnt]=num-1;//å­æ­£å¥½é¾åº¦ä¸ºdçè¾¹çç¼å·

            dd=level(po[v[i]],po[u[i]]);
            if(dd<=d)
            {
                add(v[i],u[i]);
                ADD(u[i],v[i]);//ååè¾¹
            }
            if(dd==d) a[++cnt]=num-1;
        }
        spfa(st,dis1,E,p);
        spfa(en,dis2,e,pp);
        double minx=INF;
        for(i=1;i<=cnt;i++)
        {
            int numm=a[i];
            int qi=E[numm].st,zhong=E[numm].en;
            double temp=E[numm].len;
            temp+=dis1[qi]+dis2[zhong];
            if(minx>temp)
                minx=temp;
        }

        if(minx!=INF)
        printf("%.1lf\n",minx);
        else puts("None");
    }
    return 0;
}
