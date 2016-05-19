#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10003
#define MAX2 2800000
int visit[MAX],list[MAX*2],sum,Top;
int Hash[MAX2+1];

struct snode{
    int w,next;
}Tree[MAX];

int BKDRHash(int k)   //Hashå¤æ­è¾¹æ¯å¦æ¯ä¸è½èµ°ç
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
    while(k)
    {
        hash = (hash * seed + (k%10))%MAX2;
        k/=10;
    }
    return (hash % MAX2);
}

void BFS(int Star)  //ä»ç¬¬ä¸ç¹å¼å§BFS
{
    int i,j,e,s,tempv,tempvv,a,b;
    e=s=0;
    list[s++]=Star;
    visit[Star]=1;
    while(e!=s)
    {
        tempv=list[e++];
        for(i=Top,j=Top;i!=-1;i=Tree[i].next)
        {
            tempvv=Tree[i].w;
            a=(tempv<tempvv)?tempv:tempvv;
            b=(tempv<tempvv)?tempvv:tempv;
            if(Hash[BKDRHash(a+b*10000)]!=1&&!visit[tempvv])  //è¥è¯¥è¾¹è½èµ°ä¸è¯¥ç¹ä¸ºè¢«è®¿é®
            {
                visit[tempvv]=1;
                sum++;
                if(i==Top)              //æ¯é¾è¡¨å¤´åå»æ
                {
                    Top=Tree[i].next;
                }
                else                    //ä¸æ¯è¡¨å¤´åè·³è¿
                {
                    Tree[j].next=Tree[i].next;
                }
                list[s++]=tempvv;
            }
            else if(i!=Top)
            {
                j=Tree[j].next;
            }
        }
    }
    return ;
}

int main()
{
    int n,m,t=0,i,a,b,temp;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        sum=0;
        memset(Hash,0,sizeof(Hash));
        memset(visit,0,sizeof(visit));
        memset(Tree,-1,sizeof(Tree));
        Top=1;
        Tree[1].w=1;
        for(i=2;i<=n;i++)      //åå»ºé¾è¡¨
        {
            Tree[i-1].next=i;
            Tree[i].w=i;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            if(b<a)
            {
                temp=a;
                a=b;
                b=temp;
            }
            Hash[BKDRHash(a+b*10000)]=1;  //è®°å½åªäºè¾¹ä¸è½èµ°ç
        }
        BFS(1);
        printf("Case %d: %d\n",++t,sum);
    }
    return 0;
}
