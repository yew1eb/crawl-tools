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
#define uint unsigned __int64
#define Max 110
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
int q[6*6],cnt;
int hash[36];
uint a[25][25],b[25][25],c[25][25],ans;
struct node
{
    int cnt,fail;
    int next[26];
    void init()
    {
        cnt=fail=0;
        memset(next,0,sizeof(next));
    }
}tri[6*6];
void insert(char *s)
{
    int i,p,x;
    p=0;
    for(i=0;s[i];i++)
    {
        x=s[i]-'a';
        if(!tri[p].next[x])
        {
            tri[++cnt].init();
            tri[p].next[x]=cnt;
        }
        p=tri[p].next[x];
    }
    tri[p].cnt++;
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
    tri[cnt+1].cnt=0;
    memset(b,0,sizeof(b));
    int tmp=0;
    for(i=0;i<=cnt+1;i++)
    {
        if(!tri[i].cnt)
        {
            hash[i]=tmp++;
        }
    }
    for(i=0;i<=cnt;i++)
    {
        if(tri[i].cnt)
            continue;
        else
        {
            b[hash[i]][hash[cnt+1]]++;
            for(int j=0;j<26;j++)
            {
                int tmp=tri[i].next[j];
                if(!tri[tmp].cnt)
                    b[hash[i]][hash[tmp]]++;
            }
        }
    }
    cnt++;
    b[hash[cnt]][hash[cnt]]=1;
    cnt=tmp-1;
}
void run(uint a[][25],uint b[][25],uint c[][25],int cnt)
{
    int i,j,k;
    for(i=0;i<=cnt;i++)
        for(j=0;j<=cnt;j++)
        {
            c[i][j]=0;
            for(k=0;k<=cnt;k++)
                c[i][j]+=a[i][k]*b[k][j];
        }
    for(i=0;i<=cnt;i++)
        for(j=0;j<=cnt;j++)
            a[i][j]=c[i][j];
}
void getsum(int n)
{
    a[0][0]=0;a[0][1]=26;
    a[1][0]=0;a[1][1]=0;
    b[0][0]=26;b[0][1]=0;
    b[1][0]=1;b[1][1]=1;
    ans=0;
    while(n)
    {
        if(n&1)
            run(a,b,c,1);
        n>>=1;
        run(b,b,c,1);
    }
    ans=a[0][0];
}
void solve(int n)
{
    memset(a,0,sizeof(a));
    a[0][0]=1;
    while(n)
    {
        if(n&1)
            run(a,b,c,cnt);
        n>>=1;
        run(b,b,c,cnt);
    }
    for(int i=0;i<=cnt;i++)
        ans-=a[0][i];
}
int main()
{
    int n,l;
    char s[10];
    while(scanf("%d%d",&n,&l)!=EOF)
    {
        cnt=0;
        tri[0].init();
        while(n--)
        {
            scanf("%s",s);
            insert(s);
        }
        getsum(l);
        bfs();
        solve(l);
        printf("%I64u\n",ans+1);
    }
}