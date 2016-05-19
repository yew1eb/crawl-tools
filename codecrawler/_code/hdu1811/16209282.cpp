#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"queue"
using namespace std;
#define N 10011
#define M 20011

int n,m;
int father[N],indegree[N],ans;
struct Eage{
    int from,to,next;
}eage[M];
int tot,head[N];
void add(int a,int b){
    eage[tot].from=a;eage[tot].to=b;eage[tot].next=head[a];head[a]=tot++;
}

int find(int k)
{
    if(father[k]==k)    return k;
    father[k]=find(father[k]);
    return father[k];
}
void get_map()
{
    int i;
    int a[M],b[M];
    char str[M][3];
    int f1,f2;
    for(i=0;i<n;i++)    father[i]=i;
    for(i=0;i<m;i++)
    {
        scanf("%d%s%d",&a[i],str[i],&b[i]);
        if(str[i][0]=='=')
        {
            f1=find(a[i]);
            f2=find(b[i]);
            father[f2]=f1;
        }
    }
    for(i=0;i<n;i++)    f1=find(i);                    //å¦ææ³ç´æ¥ç¨æä¸ªç¹çfatherçè¯ï¼è¿ä¸ªä¸è½æ¼æã
    tot=0;
    memset(head,-1,sizeof(head));
    memset(indegree,0,sizeof(indegree));
    for(i=0;i<m;i++)
    {
        if(father[a[i]]==father[b[i]] && str[i][0]!='=')    {ans=1;break;}
        if(str[i][0]=='>')        {add(father[a[i]],father[b[i]]);indegree[father[b[i]]]++;}
        else if(str[i][0]=='<')    {add(father[b[i]],father[a[i]]);indegree[father[a[i]]]++;}
    }
}
int topsort()
{
    int tot2;
    int i,j,v,temp;
    int k,flag;
    queue<int>q;
    int now;

    tot2=flag=temp=0;
    for(i=0;i<n;i++)
    {
        if(father[i]==i)
        {
            tot2++;
            if(!indegree[i])    {temp++;q.push(i);}
            if(temp>1)    flag=2;
        }
    }

    k=0;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        k++;
        indegree[now]--;
        temp=0;
        for(j=head[now];j!=-1;j=eage[j].next)
        {
            v=eage[j].to;
            indegree[v]--;
            if(!indegree[v])    {temp++;q.push(v);}
        }
        if(temp>1)    flag=2;
    }
    if(k<tot2)    flag=1;
    return flag;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=-1)
    {
        ans=0;
        get_map();
        if(!ans)        ans=topsort();
        if(!ans)        printf("OK\n");
        else if(ans==1)    printf("CONFLICT\n");
        else            printf("UNCERTAIN\n");
    }
    return 0;
}