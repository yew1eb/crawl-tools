#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
#define eps 1e-8
#define maxn 226
using namespace std;
char s[22][22];
int n,m;
int cnt;
struct node
{
    int x,y;
    node(){};
    node(int xx,int yy){x=xx,y=yy;}
};
node st;
int vis[22][22];
int X[]={0,0,-1,1};
int Y[]={-1,1,0,0};
bool inmap(int x,int y)
{
    if(0<=x&&x<n&&0<=y&&y<m) return true;
    else return false;
}
bool bfs()
{
    int flag=0;
    memset(vis,-1,sizeof(vis));
    queue<node> q;
    cnt=0;
    vis[st.x][st.y]=cnt++;
    q.push(st);
    while(!q.empty())
    {
        node tmp=q.front();q.pop();
        if(s[tmp.x][tmp.y]=='$') flag=1;
        for(int i=0;i<4;i++)
        {
            node next=node(tmp.x+X[i],tmp.y+Y[i]);
            if(!inmap(next.x,next.y)) continue;
            else if(s[next.x][next.y]=='#') continue;
            else if(vis[next.x][next.y]==-1)
            {
                vis[next.x][next.y]=cnt++;
                q.push(next);
            }
        }
    }
    return flag;
}
double A[maxn][maxn];
void build()
{
    memset(A,0,sizeof(A));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]==-1) continue;
            else if(s[i][j]=='$')
            {
                A[vis[i][j]][vis[i][j]]=1;
                A[vis[i][j]][cnt]=0;
            }
            else
            {
                int nn=0;
                for(int k=0;k<4;k++)
                {
                    node next= node(i+X[k],j+Y[k]);
                    if(!inmap(next.x,next.y)) continue;
                    else if(vis[next.x][next.y]==-1) continue;
                    else if(s[next.x][next.y]=='#') continue;
                    else
                    {
                        A[vis[i][j]][vis[next.x][next.y]]=-1.0;
                        nn++;
                    }
                }
                A[vis[i][j]][vis[i][j]]=nn;
                A[vis[i][j]][cnt]=nn;
            }
        }
    }
}
int sgn(double x)
{
    if(fabs(x)<eps) return 0;
    else return x>0?1:-1;
}
bool gaosi()
{
    int i,j,r,c;
    for(r=0,c=0;r<cnt&&c<cnt;r++,c++)
    {
        //找不是0的行
        for(i=r;i<cnt;i++)
        {
            if(sgn(A[i][c])!=0) break;
        }
        if(i==cnt)
        {
            r--;continue;
        }
        //替换
        if(i!=r)
        {
            for(j=c;j<=cnt;j++) swap(A[i][j],A[r][j]);
        }
        //消元
        for(i=r+1;i<cnt;i++)
        {
            for(j=cnt;j>=c;j--)
            {
                A[i][j]-=A[r][j]/A[r][c]*A[i][c];
            }
        }
    }
    for(i=r;i<cnt;i++)
    {
        if(sgn(A[i][cnt]!=0)) return 1;//无解
    }
    if(r<cnt) return cnt-r;//有无穷解
    //回溯
    for(i=cnt-1;i>=0;i--)
    {
        for(j=cnt-1;j>i;j--)
        {
            A[i][cnt]-=A[i][j]*A[j][cnt];
        }
        A[i][cnt]/=A[i][i];
        A[i][i]=1;
    }
    return 0;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='@')
                {st.x=i,st.y=j;}
            }
        }
        if(!bfs())
        {
            printf("-1\n");
            continue;
        }
        build();
        if(gaosi()!=0)
        {
            printf("-1\n");
        }
        else
        {
            printf("%.6lf\n",A[0][cnt]);
        }
    }
    return 0;
}