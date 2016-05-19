#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int y[105];
bool vis[105];
vector<int> G[105];
bool visx[105];
bool visy[105];
bool dfs(int v)
{
    //cout<<v<<endl;
    for(int i=0;i<G[v].size();i++)
    {
        int e=G[v][i];
        if(vis[e]||visy[e]) continue;
        vis[e]=1;
        if(y[e]==-1||dfs(y[e]))
        {
            y[e]=v;
            return true;
        }
    }
    return false;
}
int maxx;
int maxy;
int xyl()
{
    int cnt=0;
    memset(y,-1,sizeof(y));
    for(int i=0;i<maxx;i++)
    {
        memset(vis,0,sizeof(vis));
        //cout<<i<<endl;
        if(!visx[i]&&dfs(i))
            cnt++;
        //cout<<i<<endl;
    }
    return cnt;
}
char s[15][15];
bool vis1[15];
int bh[15][15];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m;
bool temp[15];
int res;
bool flag[15][15];
void solve(int p,int _k)
{
    //cout<<p<<endl;
    if(p==10)
    {
        memset(visx,0,sizeof(visx));
        memset(visy,0,sizeof(visy));
        int cnt=0;
        int cnt1=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='.')
                for(int k=0;k<4;k++)
                {
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx>=0&&ny>=0&&nx<n&&ny<m&&s[nx][ny]!='.')
                    {
                        int __k=s[nx][ny]-'0';
                        if(temp[__k])
                        {
                            if(i%2==j%2)
                            {
                                cnt++;
                                visx[bh[i][j]]=1;
                            }
                            else
                            {
                                cnt1++;
                                visy[bh[i][j]]=1;
                            }
                            break;
                        }
                    }
                }
            }
        }
        //cout<<maxx<<endl;
        int rr=xyl();
        //cout<<rr<<" "<<maxx<<" "<<maxy<<" "<<cnt<<" "<<cnt1<<" "<<_k<<endl;
        rr=maxx+maxy-cnt-rr-cnt1;
        //cout<<rr<<" "<<cnt<<" "<<_k<<" "<<maxx<<endl;
        res=max(res,rr+_k);
    }
    else
    {
        if(!vis1[p]) solve(p+1,_k);
        else
        {
            solve(p+1,_k);
            bool he=0;
            for(int i=0;i<p;i++)
            {
                //cout<<i<<" "<<temp[i]<<" "<<" "<<flag[i][p]<<endl;
                if(temp[i]&&flag[i][p])
                {
                    he=1;
                    break;
                }
            }

            if(!he)
            {
                temp[p]=1;
                solve(p+1,_k+1);
                temp[p]=0;
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    int ca=0;
    while(t--)
    {
        //int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n*m;i++) G[i].clear();
        for(int i=0;i<n;i++) scanf("%s",s[i]);
        memset(vis,0,sizeof(vis));
        int X=0,Y=0;
        memset(flag,0,sizeof(flag));
        memset(vis1,0,sizeof(vis1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j]!='.')
                {
                    int _k=s[i][j]-'0';
                    vis1[_k]=1;
                    for(int k=0;k<4;k++)
                    {
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        if(nx>=0&&ny>=0&&nx<n&&ny<m&&s[nx][ny]!='.')
                        {
                            //cout<<_k<<" "<<s[nx][ny]<<endl;
                            flag[_k][s[nx][ny]-'0']=flag[s[nx][ny]-'0'][_k]=1;
                        }
                    }
                }
                else
                {
                    if(i%2==j%2)
                    {
                        bh[i][j]=X++;
                    }
                    else bh[i][j]=Y++;
                    //cout<<i<<" "<<j<<" "<<bh[i][j]<<endl;
                }
            }
        }
        //cout<<"~~~~~"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=i%2;j<m;j+=2)
            {
                if(s[i][j]=='.')
                {
                    for(int k=0;k<4;k++)
                    {
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        if(nx>=0&&ny>=0&&nx<n&&ny<m&&s[nx][ny]=='.')
                        {
                            //cout<<bh[i][j]<<" "<<bh[nx][ny]<<"~~~"<<endl;
                            G[bh[i][j]].push_back(bh[nx][ny]);
                        }
                    }
                }
            }
        }
        maxx=X;
        maxy=Y;
        memset(temp,0,sizeof(temp));
        res=0;
        //cout<<"~~~"<<endl;
        solve(0,0);
        printf("Case #%d: %d\n",++ca,res);
    }
}
