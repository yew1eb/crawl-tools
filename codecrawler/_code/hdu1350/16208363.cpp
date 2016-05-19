#include"stdio.h"
#include"string.h"
#include"math.h"

struct A
{
    int s,e;
    int x_s,y_s;
    int x_e,y_e;
    int tot;
    int mem[444];
}E[511];

int match[511];
int visit[511];

int DFS(int k)
{
    int i;
    for(i=0;i<E[k].tot;i++)
    {
        if(visit[E[k].mem[i]])    continue;
        visit[E[k].mem[i]]=1;
        if(match[E[k].mem[i]]==-1 || DFS(match[E[k].mem[i]]))
        {
            match[E[k].mem[i]]=k;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int T;
    int n;
    int i,l;
    int a,b;
    char str[111];
    int ans;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s%d%d%d%d",str,&E[i].x_s,&E[i].y_s,&E[i].x_e,&E[i].y_e);
            a=0;
            for(l=0;str[l]!=':';l++)    {a*=10;a+=str[l]-'0';}
            b=0;
            for(l++;str[l];l++)            {b*=10;b+=str[l]-'0';}


            E[i].s=a*60+b;
            E[i].e=E[i].s+abs(E[i].x_s-E[i].x_e)+abs(E[i].y_s-E[i].y_e);
            E[i].tot=0;
        }

        for(i=0;i<n-1;i++)
        for(l=i+1;l<n;l++)
            if(E[i].e+abs(E[i].x_e-E[l].x_s)+abs(E[i].y_e-E[l].y_s)<E[l].s)    E[i].mem[E[i].tot++]=l;

        memset(match,-1,sizeof(match));
        ans=0;
        for(i=0;i<n;i++)
        {
            if(E[i].tot==0)    continue;
            memset(visit,0,sizeof(visit));
            ans+=DFS(i);
        }

        printf("%d\n",n-ans);
    }
    return 0;
}