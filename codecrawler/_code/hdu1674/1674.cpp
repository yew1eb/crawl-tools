#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<time.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;

//typedef long long lld;
typedef __int64 lld;//??????????????long long
const lld MAX=210;
const double  INF=1.0e9;
lld gcd(lld a,lld b){return a%b?gcd(b,a%b):b;}

int dblcmp(double x)
{
    const double EPS=1.0e-8;
    if(fabs(x)<EPS)return 0;
    return x<0?-1:1;
}
char s[MAX],t[MAX];
int pt[MAX];
bool smove[1<<19];
vector<int>edge[MAX][MAX];
void ins(char dest[],int n,int i,int j)
{
    char zs[MAX];
    strcpy(zs,dest);
    if(strstr(s,zs)!=NULL)
    {
        smove[((pt[j-i+1]-1)<<i)]=true;
        return ;
    }
    reverse(zs,zs+n);

    if(strstr(s,zs)!=NULL)
    {
        smove[((pt[j-i+1]-1)<<i)]=true;
    }
}
vector<int> match(char src[],int lens,int lent)
{
    vector<int>ret;
    ret.clear();
    int i;
    char*pos;
    int v;
    for(i=0;i+lens-1<lent;i++)
    {
        v=(pt[lens]-1)<<i;
        pos=strstr(&t[i],src);
        if(pos==&t[i])
        {
            ret.push_back(v);
        }
        else
        {
            reverse(src,src+lens);
            pos=strstr(&t[i],src);
            if(pos==&t[i])
            {
                ret.push_back(v);
            }
            reverse(src,src+lens);
        }
    }
    return ret;
}
queue<int>q;
queue<int>qa;
bool visa[1<<19];
bool vis[1<<19];
bool walk(int n)
{
    int i,j,k;
    int full=(1<<n)-1;
    int size=q.size();
    while(size--)
    {
        int cur=q.front();
        q.pop();
        int i,v;
        int j,k;
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                if((1<<j)&cur)break;
                v=(pt[j-i+1]-1)<<i;
                if(smove[v]==false)break;

                v|=cur;
                if(visa[v])return true;
                if(vis[v])continue;
                vis[v]=true;

                q.push(v);
            }
        }

        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                if(((1<<j)&cur)==0)break;

                for(k=0;k<edge[i][j].size();k++)
                {
                    v=edge[i][j][k];
                    if((v&cur)==0)
                    {
                        v|=cur;
                        if(visa[v])return true;
                        if(vis[v])continue;
                        vis[v]=true;

                        q.push(v);
                    }
                }
            }
        }
    }
return false;
}
bool walka(int n)
{
    int i,j,k;
    int full=(1<<n)-1;
    int size=qa.size();
    while(size--)
    {
        int cur=qa.front();
        qa.pop();
        int i,v;
        int j,k;
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                if(0==((1<<j)&cur))break;
                v=(pt[j-i+1]-1)<<i;
                if(smove[v]==false)break;

                v^=cur;
                if(vis[v])return true;
                if(visa[v])continue;
                visa[v]=true;

                qa.push(v);
            }
        }

        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                if(((1<<j)&cur)==0)break;

                for(k=0;k<edge[i][j].size();k++)
                {
                    v=edge[i][j][k];
                    if(v&((pt[j-i+1]-1)<<i))continue;
                    if((v&cur)==v)
                    {
                        v^=cur;
                        if(vis[v])return true;
                        if(visa[v])continue;
                        visa[v]=true;

                        qa.push(v);
                    }
                }
            }
        }
    }
return false;
}
int BFS(int n)
{
    memset(vis,false,sizeof(bool)*((1<<n)+3));
    memset(visa,false,sizeof(bool)*((1<<n)+3));
    while(!q.empty())q.pop();
    while(!qa.empty())qa.pop();
    int full=1<<n;
    vis[0]=true;
    q.push(0);
    visa[full-1]=true;
    qa.push(full-1);
    int step=0,size;
    while(!q.empty()||!qa.empty())
    {
        step++;
        if(step&1)
        {
            if(walk(n))return step;
        }
        else
        {
            if(walka(n))return step;
        }
    }
    return -1;
}
int main()
{
    int n;
    int i,j,k;
    int CS=1;
    int T;
    int m;
    pt[0]=1;
    for(i=1;i<MAX;i++)pt[i]=pt[i-1]*2;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s",s,t);

        int lens=strlen(s);
        bool ext[222]={false};
        for(i=0;i<lens;i++)ext[s[i]]=true;
        int lent=strlen(t);
        memset(smove,false,sizeof(bool)*((1<<lent)+3));
        for(i=0;i<lent;i++)
        {
            if(!ext[t[i]])break;
        }
        if(i<lent)
        {
            puts("impossible");
            continue;
        }
        char tmps[MAX];
        char zs[MAX];
        for(i=0;i<lent;i++)
        {
            k=0;
            for(j=i;j<lent;j++)
            {
                tmps[k]=t[j];
                k++;
                tmps[k]=0;
                ins(tmps,k,i,j);

            }
        }
//      for(i=0;i<(1<<lent);i++)   {           printf("smove[%d]=%d\n",i,smove[i]);        }

        for(i=0;i<lent;i++)
        {
            k=0;
            for(j=i;j<lent;j++)
            {
                tmps[k]=t[j];
                k++;
                tmps[k]=0;
                //if(i==0&&j==3)
                {
                    edge[i][j]=match(tmps,k,lent);
                }

            }
        }
        /*
        for(i=0;i<lent;i++)
        {
            for(j=i;j<lent;j++)
            {
                printf("[%d,%d]",i,j);
                for(k=0;k<edge[i][j].size();k++)
                {
                    printf("->%d",edge[i][j][k]);
                }
                puts("");
            }
        }*/
        int ans=BFS(lent);
        if(ans==-1)puts("impossible");
        else printf("%d\n",ans);
    }
    return 0;
}
/*

A
AAAA

A
AAAAA

A
AAAAAA

AAAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAD

ACGT
TCGATCGA

GTACTATTATA
GTACAATTAAT

ACGT
TCGATCGA
1248

16+64=80

128+32=160
(2^4-1)=15<<4
15*16
ABCEFGHIJKLMNOPQRS
AAAAAAAAAAAAAAAAAA

ABCEFGHIJKLMNOPQRS
ABCEFGHIJKLMNOPQRS

ABCEFGHIJKLMNOPQRS
ABCEFGHIJKLMNOPQRA
*/