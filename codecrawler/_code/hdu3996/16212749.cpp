#include <cstdio>
#include <string.h>

using namespace std;

typedef long long ll;
const int N=3550;
const int M=9000000;
const ll inf=13216546513113211ll;

int head[N];

struct Edge{
    int v,next;
    ll w;
} edge[M];

int cnt,s=0;

void addedge(int u,int v,ll w)//è¿éå­çè¿æ¯ä¸æ¡æåè¾¹
{
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
    edge[cnt].v=u;
    edge[cnt].w=0;
    edge[cnt].next=head[v];
    head[v]=cnt++;
}

ll sap(int t){
    int pre[N],cur[N],dis[N],gap[N];
    ll flow=0,aug=inf,u;
    bool flag;
    for(int i=0; i<=t; i++){
        cur[i]=head[i];
        gap[i]=dis[i]=0;
    }
    gap[s]=t+1;
    u=pre[s]=s;
    while(dis[s]<=t){
        flag=0;
        for(int &j=cur[u]; ~j; j=edge[j].next){
            int v=edge[j].v;
            if(edge[j].w>0&&dis[u]==dis[v]+1){
               flag=1;
               if(edge[j].w<aug) aug=edge[j].w;
               pre[v]=u;
               u=v;
               if(u==t){
                    flow+=aug;
                    //printf("%d\n",flow);
                    while(u!=s){
                       u=pre[u];
                       edge[cur[u]].w-=aug;
                       edge[cur[u]^1].w+=aug;//å¼ææ¯æ¾ä¸å¶éå¯¹çè¾¹
                    }
                    aug=inf;
                }
                break;
            }
        }
        if(flag) continue;
        int mindis=t+1;
        for(int j=head[u]; ~j; j=edge[j].next){
            int v=edge[j].v;
            if(edge[j].w>0&&dis[v]<mindis){
                mindis=dis[v];
                cur[u]=j;
            }
        }
        if((--gap[dis[u]])==0)
            break;
        gap[dis[u]=mindis+1]++;
        u=pre[u];
    }
    return flow;
}

ll value[N];
void init()
{
    memset (head , -1 , sizeof(head));
    cnt=0;
}

int main ()
{
    int cas;
    int n,lay,c;
    ll a,b;
    ll sum=0;
    int u,v;
    scanf("%d",&cas);
    for (int I=1 ; I<=cas ; ++I)
    {
        init();
        sum=0;
        scanf("%d",&lay);
        for (int i=0 ; i<lay ; ++i)
        {
            scanf("%d",&n);
            for (int j=0 ; j<n ; ++j)
            {
                scanf("%I64d%I64d%d",&a,&b,&c);
                value[i*25+j+1]=b-a;
                for (int k=0 ; k<c ; ++k)
                {
                    scanf("%d%d",&u,&v);
                    u--;v--;
                    addedge(i*25+j+1,u*25+v+1,inf);
                }
                if(value[i*25+j+1]>0)
                    addedge(0,i*25+j+1,value[i*25+j+1]),sum+=value[i*25+j+1];
                if(value[i*25+j+1]<0)
                    addedge(i*25+j+1,2550,-value[i*25+j+1]);
            }
        }
        ll  ans=sum-sap(2550);
        //printf("%d\n",sum);
        printf("Case #%d: %I64d\n",I,ans);
    }
    return 0;
}
