#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int vis[1100000];
struct node
{
    int noa,yesa;
    int time;
    int ka,ta;
}pat[105];
struct node2
{
   int bug;
   int time;
   bool operator <(const node2 &a) const
   {
       return time>a.time;
   }
};
int n,m;
bool isok(int k,int bug)
{
	if((pat[k].noa&bug)!=0) return false;
	if((pat[k].yesa&bug)!=pat[k].yesa) return false;
	return true;
}
int fix(int k,int bug)
{
    int tmp=bug;
    bug=((~pat[k].ka)&bug);
    bug=(pat[k].ta|bug);
    if(tmp==bug) return -1;
    return bug;
}
void bfs(int bug)
{
    priority_queue<node2> q;
    node2 tmp,tt;
    tmp.bug=bug;tmp.time=0;
    q.push(tmp);
    int mins=-1;
    while(!q.empty())
    {
        tmp=q.top();q.pop();
        if(tmp.bug==0)
        {
            mins=tmp.time;
            break;
        }
        for(int i=1;i<=m;i++)
        {
            tt=tmp;
            if(isok(i,tt.bug)) //第i种补丁应用到当前bug上
            {
                tt.bug=fix(i,tmp.bug);
                if(tt.bug<0) continue;
                tt.time+=pat[i].time;
                if(vis[tt.bug]!=-1&&tt.time>=vis[tt.bug]) continue;      //判断新旧时间，依此决定是否进入队列
                vis[tt.bug]=tt.time;
                q.push(tt);
            }
        }
    }
    if(mins==-1)
    {
        printf("Bugs cannot be fixed.\n");
    }
    else
    {
        printf("Fastest sequence takes %d seconds.\n",mins);
    }
}
int main()
{
    int bug;
    char a[200],b[200];
    int cas=1;
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        bug=0;
        memset(pat,0,sizeof(pat));
        memset(vis,-1,sizeof(int)*(1<<n));
        bug=(1<<n)-1;
        for(int i=1;i<=m;i++)
        {
            scanf("%d %s %s",&pat[i].time,a,b);
            for(int k=0;k<n;k++)
            {
                if(a[k]=='-')
                {
                    pat[i].noa+=(1<<(n-k-1));
                }
                else if(a[k]=='+')
                {
                    pat[i].yesa+=(1<<(n-k-1));
                }
            }
            for(int k=0;k<n;k++)
            {
                if(b[k]=='-')
                {
                    pat[i].ka+=(1<<(n-k-1));
                }
                else if(b[k]=='+')
                {
                    pat[i].ta+=(1<<(n-k-1));
                }
            }
        }
        printf("Product %d\n",cas++);
        bfs(bug);
        putchar(10);
    }
    return 0;
}