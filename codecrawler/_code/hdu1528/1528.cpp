#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

char t1[15]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
int t2[15]={1,2,3,4,5,6,7,8,9,10,11,12,13};
struct node
{
    int id;
    char cha;
    char type;
}card[60];
int n,cnt;
int match[60];
int vis[60];
int g[60][60];

bool judge(int x,int y)
{
    if(card[x].type=='H' && card[y].type!='H')
        return true;
    else if(card[x].type=='S' && (card[y].type=='D'||card[y].type=='C'))
        return true;
    else if(card[x].type=='D' && card[y].type=='C')
        return true;
    else return false;
}
bool dfs(int u)
{
    for(int i=1;i<=n;i++)
    {
        if(g[u][i] && !vis[i])
        {
            vis[i]=true;
            if(match[i]==-1 || dfs(match[i]))
            {
                match[i]=u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        getchar();
        memset(card,0,sizeof(card));
        memset(match,-1,sizeof(match));
        memset(g,0,sizeof(g));
        for(j=1;j<=n;j++)
        {
            card[j].cha=getchar();
            for(k=0;k<13;k++)
                if(card[j].cha==t1[k])
                    card[j].id=t2[k];
            /*if(card[j].id==13)
            {
                if(j<=n-1)
                    getchar();
                continue;
            }*/
            card[j].type=getchar();
            if(j<=n-1)
                getchar();
        }
        getchar();
        for(j=n+1;j<=2*n;j++)
        {
            card[j].cha=getchar();
            for(k=0;k<13;k++)
                if(card[j].cha==t1[k])
                    card[j].id=t2[k];
            /*if(card[j].id==13)
            {
                if(j<=n-1)
                    getchar();
                continue;
            }*/
            card[j].type=getchar();
            getchar();
            for(i=1;i<=n;i++)
            {
                if(card[j].id>card[i].id)
                    g[j][i]=true;
                else if(card[j].id==card[i].id && judge(j,i))
                    g[j][i]=true;
            }
        }
        cnt=0;
        for(i=n+1;i<=2*n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i))
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}