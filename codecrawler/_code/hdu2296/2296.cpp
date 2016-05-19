#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<list>
#include<iostream>
#include<map>
using namespace std;
#define inf 0x3f3f3f3f
#define Max 110
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
int q[12*110],cnt;
char str[110][12];
int dp[60][1100];
int pre[60][1100];
char  c[1100];
struct node
{
    int cnt,fail,al;
    int next[26];
    void init()
    {
        cnt=fail=0;
        memset(next,0,sizeof(next));
    }
}tri[12*110];
int t,n,m;
inline bool cmp(int i,int x,int y)
{
    for(int k=i;k>=1;k--)
    {
        if(c[x]!=c[y])
            return c[x]<c[y];
        x=pre[k][x];
        y=pre[k][y];
    }
    return false;
}
void insert(char *s,int val)
{
    int i,p,x;
    p=0;
    for(i=0;s[i];i++)
    {
        x=s[i]-'a';
        if(!tri[p].next[x])
        {
            tri[++cnt].init();
            tri[cnt].al=s[i];
            tri[p].next[x]=cnt;
            c[cnt]=s[i];
        }
        p=tri[p].next[x];
    }
    tri[p].cnt=val;
}
void bfs()
{
    int i,p=0,suf,head=0,tail=0;
    for(i=0;i<26;i++)
    {
        if(tri[0].next[i])
        {
            q[tail++]=tri[0].next[i];
            tri[q[tail-1]].fail=0;
        }
    }
    while(head<tail)
    {
        p=q[head++];suf=tri[p].fail;
        tri[p].cnt+=tri[suf].cnt;
        for(i=0;i<26;i++)
        {
            if(tri[p].next[i])
            {
                q[tail++]=tri[p].next[i];
                tri[q[tail-1]].fail=tri[suf].next[i];
            }
            else
                tri[p].next[i]=tri[suf].next[i];
        }
    }
}
void solve()
{
    int ans=0,len=0,pos=0,i,j,k,tmp;
    for(i=0;i<=n;i++)
        for(j=0;j<=cnt;j++)
            dp[i][j]=-1;
    dp[0][0]=0;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=cnt;j++)
        {
            if((i&&(j==0))||dp[i][j]==-1)
                continue;
            if(i&&(ans<dp[i][j]))
            {
                ans=dp[i][j];
                len=i;
                pos=j;
            }
            else if(i&&(ans==dp[i][j]))
            {
                if(len==i&&cmp(len,j,pos))
                    pos=j;
            }
            if(i==n)
                continue;
            for(k=0;k<26;k++)
            {
                tmp=tri[j].next[k];
                if(tmp==0)
                    continue;
                if(dp[i+1][tmp]<dp[i][j]+tri[tmp].cnt)
                {
                    dp[i+1][tmp]=dp[i][j]+tri[tmp].cnt;
                    pre[i+1][tmp]=j;
                }
                else if(dp[i+1][tmp]==dp[i][j]+tri[tmp].cnt)
                {
                        if(cmp(i,j,pre[i+1][tmp]))
                            pre[i+1][tmp]=j;
                }
            }
        }
    }
    if(ans==0)
    {
        puts("");
        return ;
    }
    for(i=len;i>0;i--)
    {
        printf("%c",c[pos]);
       pos=pre[i][pos];
    }
    puts("");
}
int main()
{
   //freopen("D:/ring.txt","w",stdout);
    int v,i,len;
    char s[20];
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;tri[0].init();
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
            scanf("%s",str[i]);
        for(i=0;i<m;i++)
        {
            scanf("%d",&v);
            len=strlen(str[i]);
            for(int j=len-1;j>=0;j--)
                s[len-1-j]=str[i][j];
            s[len]=0;
            insert(s,v);
        }
        bfs();
        solve();
    }
}