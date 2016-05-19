#include"stdio.h"
#include"string.h"


struct A
{
    int total;
    int mem[1111];
}E[1111];
int match[1111];
int visit[1111];


int DFS(int k)
{
    int i;
    for(i=0;i<E[k].total;i++)
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
    int n;
    int ans;
    int i,l;
    int a,b;
    char str[22];
    int temp;


    while(scanf("%d",&n)!=-1)
    {
        memset(match,-1,sizeof(match));


        for(i=0;i<n;i++)    E[i].total=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            a=0;
            for(l=0;str[l]!=':';l++)    {a*=10;a+=str[l]-'0';}


            scanf("%s",str);
            temp=0;
            for(l=1;str[l]!=')';l++)    {temp*=10;temp+=str[l]-'0';}


            while(temp--)
            {
                scanf("%d",&b);
                E[a].mem[E[a].total++]=b;
            }
        }


        ans=0;
        for(i=0;i<n;i++)
        {
            if(E[i].total==0)    continue;
            memset(visit,0,sizeof(visit));
            ans+=DFS(i);
        }
        ans=n-ans/2;


        printf("%d\n",ans);
    }
    return 0;
}