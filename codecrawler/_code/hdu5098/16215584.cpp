#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<vector>
#include<bitset>
#define nn 1100
using namespace std;
char s[11000];
struct node
{
    int st,en,next;
}E[nn*nn];
int p[nn],num;
void init()
{
    memset(p,-1,sizeof(p));
    num=0;
}
void add(int st,int en)
{
    E[num].en=en;
    E[num].next=p[st];
    p[st]=num++;
}
map<string,int>ma;
bool vis[nn];
bool use[nn];
int dp[nn];
int dfs(int id)
{
    if(vis[id])
        return dp[id];
    vis[id]=true;
    int i,w;
    dp[id]=0;
    if(use[id])
        dp[id]=1;
    int re=0;
    for(i=p[id];i+1;i=E[i].next)
    {
        w=E[i].en;
        re=max(re,dfs(w));
    }
    dp[id]+=re;
    return dp[id];
}
int main()
{
    int i,j,t,cas=1;
    scanf("%d",&t);
    getchar();
    gets(s);
    string ix;
    int lx;
    while(t--)
    {
        memset(use,false,sizeof(use));
        init();
        ma.clear();
        int cnt=0;
        string my;
        while(gets(s))
        {
            if(strlen(s)==0)
                break;
            ix="";
            int id;
            for(i=0;i<(int)strlen(s);i++)
            {
                if(s[i]==':')
                {
                    lx=ix.size();
                    my="";
                    for(j=0;j<lx-1;j++)
                    {
                        my+=ix[j];
                    }
                    if(ix[lx-1]!='*')
                        my+=ix[lx-1];
                    if(ma.count(my)==0)
                        ma[my]=++cnt;
                    id=ma[my];
                    if(ix[lx-1]=='*')
                        use[id]=true;
                    ix="";
                }
                else if(s[i]==' ')
                {
                    if(ix.size())
                    {
                        lx=ix.size();
                        my="";
                        for(j=0;j<lx-1;j++)
                        {
                            my+=ix[j];
                        }
                        if(ix[lx-1]!='*')
                            my+=ix[lx-1];
                        if(ma.count(my)==0)
                            ma[my]=++cnt;
                        add(id,ma[my]);
                        if(ix[lx-1]=='*')
                            use[ma[my]]=true;
                    }
                    ix="";
                }
                else
                    ix+=s[i];
            }
            if(ix.size())
            {
                lx=ix.size();
                my="";
                for(j=0;j<lx-1;j++)
                {
                    my+=ix[j];
                }
                if(ix[lx-1]!='*')
                    my+=ix[lx-1];
                if(ma.count(my)==0)
                    ma[my]=++cnt;
                add(id,ma[my]);
                if(ix[lx-1]=='*')
                    use[ma[my]]=true;
            }
        }
        int ans=0;
        memset(vis,false,sizeof(vis));
        for(i=1;i<=cnt;i++)
        {
            if(!vis[i])
                dfs(i);
            ans=max(ans,dp[i]);
        }
        printf("Case %d: ",cas++);
        printf("%d\n",ans);
    }
    return 0;
}
