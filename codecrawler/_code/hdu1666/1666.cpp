#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

const int W=5;
const int MS=15;
const int MSK=1<<MS;
const int NS=1100;
const int INF=0x3f3f3f3f;

struct node{
    int sta,add;
}z;

char pic[4][4];
int n,m,w;
int tmp,top,num;
int p[3][3],q[3][3];
int bv[MSK],vis[MSK],best[MSK];
int h[NS],state[NS],value[NS][1<<10];
vector<node> tst[MSK];

int Trans_num(int arr[3][3])
{
    int st=0;
    for (int i=0;i<3;i++)
    for (int j=0;j<3;j++)
    st|=arr[i][j]<<(i*5+j);
    while ( !(st&31) ) st>>=5;
    while ( !(st&0x421) ) st>>=1;
    return st;
}

void Route()
{
    memcpy(q,p,sizeof(q));
    for (int i=0;i<3;i++)
    for (int j=0;j<3;j++)
    p[i][j]=q[2-j][i];
}

void dfs(int cur,int pre,int pos,int add)
{
    if(add>=best[pre]) return;
    best[pre]=add;
    if ( !(pre&31) )
    {
        z.sta=(pre>>5),z.add=add;
        tst[cur].push_back(z);
        return ;
    }
    for (int i=pos;i<top;i++)
    {
        int stu=state[i];
        do
        {
            if ( (pre&stu)==stu )
            dfs(cur,pre^stu,i,add+bv[i]);
            stu<<=1;
        }while( !(stu&0x421) );
    }
}

int cal(int pos,int st)
{
    if (value[pos][st]>=0) return value[pos][st];
    int r=INF,cur=st|(((1<<h[pos+2])-1)<<10);
    if (!vis[cur])
    {
        vis[cur]=1;
        memset(best,0x3f,sizeof(best));
        tst[cur].clear(),dfs(cur,cur,0,0);
    }
    for (int i=0;i<tst[cur].size();i++)
    r=min(r,cal(pos+1,tst[cur][i].sta)+tst[cur][i].add);
    return value[pos][st]=r;
}

void solve()
{
    memset(value,-1,sizeof(value));
    memset(vis,0,sizeof(vis)),value[n][0]=0;
    int ans=cal(0,((1<<h[0])-1)|(((1<<h[1])-1)<<5));
    if (ans>=INF) printf("Impossible.\n");
    else printf("Need at least %d Gil(s).\n",ans);
}

int main()
{
    while (~scanf("%d",&n)&&n)
    {
        top=0;
        memset(h,0,sizeof(h));
        memset(bv,0x3f,sizeof(bv));
        for (int i=0;i<n;i++)
        scanf("%d",&h[i]);
        scanf("%d",&m);
        for (int i=0;i<m;i++)
        {
            scanf("%d",&w);
            for (int j=0;j<3;j++)
            {
                scanf("%s",pic[j]);
                for (int k=0;k<3;k++)
                p[j][k]= (pic[j][k]=='#');
            }
            tmp=Trans_num(p);
            bv[tmp]=min(bv[tmp],w);

            for (int j=0;j<3;j++)
            {
                Route();
                tmp=Trans_num(p);
                bv[tmp]=min(bv[tmp],w);
            }
        }
        for (int i=1;i<MSK;i++)
        if (bv[i]<INF)
        state[top]=i,bv[top++]=bv[i];
        solve();
    }
    return 0;
}