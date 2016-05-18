#include <stdio.h>
#include <string.h>
#define INF 99999999
#define N 350

int n,nx,ny;   //nx,ny分别表示x集合和y集合的元素个数

int lx[N];
int ly[N];
int link[N];
int slack[N];
int visx[N];
int visy[N];
int w[N][N];

bool DFS(int x)
{
    int y;
    visx[x]=1;
    for(y=1;y<=ny;y++)
    {
        if(visy[y]) continue;
        int t=lx[x]+ly[y]-w[x][y];
        if(t==0)
        {
            visy[y]=1;
            if(link[y]==-1||DFS(link[y]))
            {
                link[y]=x;
                return true;
            }
        }
        else if(slack[y]>t)         //不在相等子图中slack 取最小的
            slack[y]=t;
    }
    return false;
}

int KM()
{
    int i,j,x;
    memset(link,-1,sizeof(link));
    memset(ly,0,sizeof(ly));
    for(i=1;i<=nx;i++)            //lx初始化为与它关联边中最大的
        for(j=1,lx[i]=-INF;j<=ny;j++)
            if(w[i][j]>lx[i])
                lx[i]=w[i][j];
    for(x=1;x<=nx;x++)
    {
        for(i=1;i<=ny;i++)
            slack[i]=INF;
        while(1)
        {
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if(DFS(x)) break;        //若成功（找到了增广轨），则该点增广完成，进入下一个点的增广

            //若失败（没有找到增广轨），则需要改变一些点的标号，使得图中可行边的数量增加。
            //方法为：将所有在增广轨中（就是在增广过程中遍历到）的X方点的标号全部减去一个常数d，
            //所有在增广轨中的Y方点的标号全部加上一个常数d

            int d=INF;
            for(i=1;i<=ny;i++)
                if(!visy[i]&&d>slack[i])
                   d=slack[i];
            for(i=1;i<=nx;i++)
                if(visx[i])
                   lx[i]-=d;
            for(i=1;i<=ny;i++)      //修改顶标后，要把所有不在交错树中的Y顶点的slack值都减去d
            {
                if(visy[i]) ly[i]+=d;
                else        slack[i]-=d;
            }
        }
    }
    int ans=0;
    for(i=1;i<=ny;i++)
       if(link[i]>-1)
          ans+=w[link[i]][i];
    return ans;
}

int main()
{
    int i,j;
    while(~scanf("%d",&n))
    {
        nx=ny=n;
        memset(w,0,sizeof(w));
        for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
              scanf("%d",&w[i][j]);
        int ans=KM();
        printf("%d\n",ans);
    }
    return 0;
}