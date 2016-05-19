#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<math.h>
#include<stdlib.h>
#define nn 110
#define inff 0x3fffffff
using namespace std;
int n,m;
struct node
{
    int id;
    pair<int,int>nl;
}tem;
int len[25];
node ve[25][10];
int bh[110];
int gx[25][25];
int ys1,ys2,ys3;
int z1,z2,z3;
int a[20];
int ans,ans1;
pair<int,int>dp[25][10][10][10];
void init()
{
    ans=ans1=-inff;
    memset(len,0,sizeof(len));
    memset(gx,0,sizeof(gx));
}
void update(int i,int j,int k,int g,pair<int,int>x,pair<int,int>y)
{
    pair<int,int> &f=dp[i][j][k][g];
    if(f.first<x.first+y.first)
    {
        f.first=x.first+y.first;
        f.second=x.second+y.second;
    }
    else if(f.first==x.first+y.first)
    {
        f.second=max(f.second,x.second+y.second);
    }
}
void DP()
{
    int i,j,k,g,e;
    int gg=0;
    for(i=1;i<=11;i++)
    {
        for(j=i;j<=11;j++)
        {
            gg+=gx[a[i]][a[j]];
        }
    }
    int w0,w1,w2,w3;
    w0=w1=w2=w3=0;
    int ix=0,mx;
    for(i=1;i<=11;i++)
    {
        mx=-inff;
        for(j=0;j<len[a[i]];j++)
        {
            tem=ve[a[i]][j];
            mx=max(mx,tem.nl.first);
            if(tem.id==0)
                w0++;
            else if(tem.id==ys1)
                w1++;
            else if(tem.id==ys2)
                w2++;
            else
                w3++;
        }
        ix+=mx;
    }
    if(w0<1||w1<z1||w2<z2||w3<z3)
        return ;
    if(ix+gg<ans)
        return ;
    for(i=0;i<=11;i++)
    {
        for(j=0;j<=1;j++)
        {
            for(k=0;k<=z1;k++)
            {
                for(g=0;g<=z2;g++)
                {
                    dp[i][j][k][g]=make_pair(-inff,-inff);
                }
            }
        }
    }
    dp[0][0][0][0]=make_pair(0,0);
    for(i=0;i<11;i++)
    {
        for(j=0;j<=1;j++)
        {
            for(k=0;k<=z1;k++)
            {
                for(g=0;g<=z2;g++)
                {
                    if(i<j+k+g)
                        break;
                    if(dp[i][j][k][g].first==-inff)
                        continue;
                    for(e=0;e<len[a[i+1]];e++)
                    {
                        tem=ve[a[i+1]][e];
                        if(tem.id==0&&j<1)
                        {
                            update(i+1,j+1,k,g,dp[i][j][k][g],tem.nl);
                            continue;
                        }
                        if(tem.id==ys1&&k<z1)
                        {
                            update(i+1,j,k+1,g,dp[i][j][k][g],tem.nl);
                            continue;
                        }
                        if(tem.id==ys2&&g<z2)
                        {
                            update(i+1,j,k,g+1,dp[i][j][k][g],tem.nl);
                            continue;
                        }
                        if(tem.id==ys3&&i-j-k-g<z3)
                        {
                            update(i+1,j,k,g,dp[i][j][k][g],tem.nl);
                            continue;
                        }
                    }
                }
            }
        }
    }
    if(dp[11][1][z1][z2].first+gg>ans)
    {
        ans=dp[11][1][z1][z2].first+gg;
        ans1=dp[11][1][z1][z2].second;
    }
    else if(dp[11][1][z1][z2].first+gg==ans)
    {
        ans1=max(ans1,dp[11][1][z1][z2].second);
    }
}
void dfs(int id,int ren)
{
    if(ren==11)
    {
        DP();
        return ;
    }
    if(id>n)
        return ;
    for(int i=id;i<=n;i++)
    {
        if(ren+n-i+1>=11)
        {
            a[ren+1]=i;
            dfs(i+1,ren+1);
        }
    }
}
int main()
{
    int t;
    char s[20];
    int i,num,ca,pa,u,v,l,x;
    int cas=1;
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&num);
            bh[x]=i;
            while(num--)
            {
                scanf("%s%d%d",s,&ca,&pa);
                if(s[0]=='G')
                    tem.id=0;
                else if(s[0]=='D')
                    tem.id=1;
                else if(s[0]=='M')
                    tem.id=2;
                else
                    tem.id=3;
                tem.nl=make_pair(ca,pa);
                ve[i][len[i]++]=tem;
            }
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%s%d",&u,&v,s,&l);
            if(s[0]=='L')
            {
                gx[bh[u]][bh[v]]+=l;
                if(u!=v)
                    gx[bh[v]][bh[u]]+=l;
            }
            else
            {
                gx[bh[u]][bh[v]]-=l;
                if(u!=v)
                    gx[bh[v]][bh[u]]-=l;
            }
        }
        scanf("%d-%d-%d",&z1,&z2,&z3);
        ys1=1,ys2=2,ys3=3;
        if(z1>=z2&&z1>=z3)
        {
            swap(z1,z3);
            swap(ys1,ys3);
        }
        else if(z2>=z1&&z2>=z3)
        {
            swap(z2,z3);
            swap(ys2,ys3);
        }
        dfs(1,0);
        if(ans==-inff)
        {
            puts("Poor Manager!");
        }
        else
            printf("%d %d\n",ans,ans1);
    }
    return 0;
}
