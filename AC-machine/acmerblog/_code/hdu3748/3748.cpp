#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
map<int,int> hash[35];
int vis[35];
int n,v,k;
int flag;
int constraint;
int g[35][35];
struct node
{
    int w;
    int cons;
}t[35],s[35];
void dfs(int y,int x,int cur)
{
    if(y>k) return;
    else if(x==constraint) hash[y][cur]=1;
    else
    {
        int tt=0;
        if(s[x].cons!=-1)
        {
            for(int i=0;i<n;i++) if(g[x][i])
            {
                if(vis[i])
                {
                    tt=1;
                    break;
                }
            }
        }
 