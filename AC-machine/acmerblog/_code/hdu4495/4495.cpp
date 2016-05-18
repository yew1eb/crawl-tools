#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char s[510][510];
int num1[510][510];
int num2[510][510];
int num3[510][510];
int num4[510][510];
int N,M;
void dfs1(int i,int j)
{
    int k;
    for(k=1;k+j<M&&k+i<N;k++)
        if(s[i+k][j]!=s[i][j+k])
        break;
    num1[i][j]=k-1;
}
void dfs2(int i,int j)
{
    int k;
    for(k=1;k+j<M&&i-k>=0;k++)
        if(s[i-k][j]!=s[i][j+k])
        break;
    num2[i][j]=k-1;
}
void dfs3(int i,int j)
{
    int k;
    for(k=1;j-k>=0&&i-k>=0;k++)
        if(s[i-k][j]!=s[i][j-k])
        break;
    num3[i][j]=k-1;
}
void dfs4(int i,int j)
{
    int k;
    for(k=1;j-k>=0&&k+i<N;k++)
        if(s[i+k][j]!=s[i][j-k])
        break;
    num4[i][j]=k-1;
}
int getans1(int i,int j)
{
    int k=num1[i][j];
    int ans=num1[i][j];
    for(int h=1;h<=k/2;h++)
    {
        ans=min(ans,num1[i+h][j+h]+2*h);
    }
    return ans;
}
int getans2(int i,int j)
{
    int k=num2[i][j];
    int ans=num2[i][j];
    for(int h=1;h<=k/2;h++)
    {
        ans=min(ans,num2[i-h][j+h]+2*h);
    }
    return ans;
}

int getans3(int i,int j)
{
    int k=num3[i][j];
    int ans=num3[i][j];
    for(int h=1;h<=k/2;h++)
    {
        ans=min(ans,num3[i-h][j-h]+2*h);
    }
    return ans;
}

int getans4(int i,int j)
{
    int k=num4[i][j];
    int ans=num4[i][j];
    for(int h=1;h<=k/2;h++)
    {
        ans=min(ans,num4[i+h][j-h]+2*h);
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;i++)
            scanf("%s",s[i]);
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
        {
            dfs1(i,j);
             dfs2(i,j);
              dfs3(i,j);
               dfs4(i,j);
        }
        int ans=0;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
            {
                ans=max(ans,getans1(i,j));//分别为直角朝向的四个方向的计算
                ans=max(ans,getans2(i,j));
                ans=max(ans,getans3(i,j));
                ans=max(ans,getans4(i,j));
            }
            cout<<(ans+1)*(ans+2)/2<<endl;
    }
    return 0;
}
