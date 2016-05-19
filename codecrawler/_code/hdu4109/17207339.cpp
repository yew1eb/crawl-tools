#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define val 1001
struct link
{
    int v;
    int cost;
    struct link *next;
};
struct node
{
    struct link *next;
}vode[val];
int into[val],ee[val],n,m;//intoè¡¨ç¤ºå¥åº¦ï¼eeè¡¨ç¤ºä»ææ©å®æè¯¥ä»»å¡çæ¶é´ï¼eeåå§åä¸º1
void topsort();//æææåºï¼è¾¹ææè¾¹æ±æé¿è·¯å¾
void create_link();
int main()
{
    int i,j,ans;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(into,0,sizeof(into));
        for(i=0;i<n;i++)
            ee[i]=1;
        create_link();
        ans=0;
        topsort();
        for(i=0;i<n;i++)
            if(ee[i]>ans) ans=ee[i];
        printf("%d\n",ans);
    }
    return 0;
}
void create_link()
{
    int i,j,a,b,c;
    struct link *s;
    for(i=0;i<n;i++)
        vode[i].next=NULL;
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        into[b]++;
        s=(struct link*)malloc(sizeof(struct link));
        s->v=b;
        s->cost=c;
        s->next=vode[a].next;
        vode[a].next=s;
    }
}
void topsort()
{
    int i,j,v;
    struct link *p;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(into[j]==0) 
            {
                v=j;
                break;
            }
        into[v]=-1;
        p=vode[v].next;
        while(p!=NULL)
        {
            if(ee[p->v]<ee[v]+p->cost)//å¦ææå¼åæ´å¤§ï¼åæ¿æ¢
                ee[p->v]=ee[v]+p->cost;
            into[p->v]--;
            p=p->next;
        }
    }
}
