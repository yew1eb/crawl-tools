#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
#include<map>
#include<string>
using namespace std;
int a[10][10];
int n,m,k;
int sum;
int ans;
int cnt[10];
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
struct node
{
    int x,y;
}Q[10000];
int top;
int isok(int x,int y,int use[][10])
{
    top=0;
    node t,f;
    int front=0,rear=0;
    f.x=x;f.y=y;
    Q[rear++]=f;
    use[x][y]=1;
    while(front<rear)
    {
        f=Q[front++];
        for(int d=0;d<8;d++)
        {
            t=f;
            t.x+=dx[d];
            t.y+=dy[d];
            if(a[t.x][t.y]==a[x][y]&&!use[t.x][t.y])
            {
               use[t.x][t.y]=1;
               Q[rear++]=t;
            }
        }
    }
    top=rear;
    return rear;
}
inline void save(int sa[][10])
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sa[i][j]=a[i][j];
}
inline void read(int sa[][10])
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=sa[i][j];
}
void debug()
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout<<a[i][j];
            cout<<endl;
    }
    system("pause");
}
void trans()
{
    for(int i=0;i<top;i++)
        a[Q[i].x][Q[i].y]=0;
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=m;j++)
        {
            int x=i,y=j;
            if(a[i][j]&&!a[i+1][j])
            {
                while(a[x][y])
                {
                    a[x+1][y]=a[x][y];
                    x--;
                }
                a[x+1][y]=0;
            }
        }
    for(int j=m;j>=1;j--)
    {
        int ok=1;
        for(int i=1;i<=n;i++)
            if(a[i][j]) ok=0;
        if(ok)
        {
            int p,k;
            for(int q=1;q<=n;q++)
            {
                for(p=m;p>j;p--)
                    if(a[q][p]) break;
                if(p==j) continue;
                for(k=j;k<p;k++)
                    a[q][k]=a[q][k+1];
                a[q][k]=0;
            }
        }
    }
}
inline int h()
{
    int tot=0;
    for(int i=1;i<=k;i++)
    {
        if(cnt[i]>=3) tot+=cnt[i]*cnt[i];
    }
    return tot;
}
void dfs(int score)
{
    ans=max(ans,score);
    if(h()+score<=ans) return;
    int tmp;
    int use[10][10]={0};
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==0&&!use[i][j]) continue;
            tmp=isok(i,j,use);
            if(tmp>=3)
            {
                int sa[10][10];
                cnt[a[i][j]]-=tmp;
                save(sa);
                trans();
                dfs(score+tmp*tmp);
                read(sa);
                cnt[a[i][j]]+=tmp;
            }
        }
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        sum=0;
        memset(a,0,sizeof(a));
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
                cnt[a[i][j]]++;
            }
        }
        ans=0;
        dfs(0);
        printf("%d\n",ans);
    }
    return 0;
}
