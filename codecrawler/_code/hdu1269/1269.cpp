#include <iostream>
using namespace std;
#include <stack>
#include <vector>
const int MAX=10000+10;
vector<int >map[MAX];//构建邻接表
stack<int >s;//将更新到的店入栈
int Dfs[MAX];//访问的节点次序//u或u的子树能够追溯到的最早的栈中节点的序号(时间戳)
int Low[MAX];//父节点最早出现的时间戳//节点u搜索的序号(时间戳)
bool isStack[MAX];//是否在栈中
int used[MAX];//标记该点输入哪个联通分量
int top;//时间戳
int newflag;//联通分量
void init()//各种初始化
{
    memset(Dfs,0,sizeof(Dfs));
    memset(Low,0,sizeof(Low));
    memset(isStack,false,sizeof(isStack));
    memset(used,0,sizeof(used));
    for(int i=0;i<MAX;i++)
    {
        map[i].clear();
    }
    while(!s.empty())
    {
        s.pop();
    }
    newflag=0;
    top=0;
}
void tarjan(int u)
{
    Dfs[u]=Low[u]=++top;//时间戳
    isStack[u]=true;//存在栈中
    s.push(u);
    for(int x=0;x<map[u].size();x++)
    {
        int v=map[u][x];
        if(!Dfs[v])//判断是否更新过
        {
            tarjan(v);//递归，继续更新
            if(Low[v]<Low[u])//若存在子节点能找到比父节点更早节点，即有环
            {
                Low[u]=Low[v];
            }
        }
        else if(isStack[v]&&Dfs[v]<Low[u])
        {
            Low[u]=Dfs[v];
        }
    }
    if(Dfs[u]==Low[u])//找不到邻接点了，即找到联通分量的结束条件
    {
        newflag++;
        int x;
        do
        {
            x=s.top();
            isStack[x]=false;
            used[x]=newflag;
            s.pop();
        }while(x!=u);//输出联通分量
    }
    return;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),n+m)
    {
        init();
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            map[x].push_back(y);
        }
        for(i=1;i<=n;i++)
        {
            if(!Dfs[i])
            {
                tarjan(i);
            }
        }
        if(newflag==1)
        {
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}