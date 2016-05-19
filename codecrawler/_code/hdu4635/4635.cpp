#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stack>
#include<vector>
using namespace std;
#define maxn 100005
#define mem(a,b) memset(a,b,sizeof(a));
vector<int>q[maxn];
stack<int>qq;
int times;
int nums;
int num[maxn];
int dnf[maxn];
int low[maxn];
int out[maxn];
int in[maxn];
int sum[maxn];
int instack[maxn];
void tarjan(int x)
{
    dnf[x]=low[x]=times++;
    instack[x]=1;
    qq.push(x);
    int i;
    for(i=0;i<q[x].size();i++)
    {
        int y=q[x][i];
        if(!dnf[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(instack[y])
        {
            low[x]=min(low[x],dnf[y]);
        }
    }
    if(dnf[x]==low[x])
    {
        int y=-1;
        while(y!=x)
        {
            y=qq.top();
            qq.pop();
            num[y]=nums;
            instack[y]=0;
            sum[nums]++;
        }
        nums++;
    }
    //cout<<x<<" "<<low[x]<<" "<<dnf[x]<<endl;
}
int main()
{
   // freopen("1004.in","r",stdin);
    int T,cas,i,j,n,m;
    cin>>T;
    for(cas=1;cas<=T;cas++)
    {
        cin>>n>>m;
        for(i=1;i<=n;i++)q[i].clear();
        while(!qq.empty())qq.pop();
        mem(in,0);
        mem(out,0);
        mem(dnf,0);
        mem(low,0);
        mem(num,0);
        mem(sum,0);
        mem(instack,0);
        nums=0;
        int x,y;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            q[x].push_back(y);
        }
        for(i=1;i<=n;i++)
            if(!dnf[i])tarjan(i);
        if(nums==1)
        {
            printf("Case %d: -1\n",cas);
            continue;
        }
        for(i=1;i<=n;i++)
        {
            for(j=0;j<q[i].size();j++)
            {
                if(num[i]!=num[q[i][j]])
                {
                    out[num[i]]++;
                    in[num[q[i][j]]]++;
                }
            }
        }
        int maxx=maxn;
        for(i=0;i<nums;i++)
        {
            if(in[i]==0||out[i]==0)
            {
                if(sum[i]<maxx)maxx=sum[i];
            }
        }
        __int64 ss;
        ss=0;
        ss =(__int64)n*(n-1);
        ss-=(__int64)m;
        ss-=(__int64)maxx*(n-maxx);

        printf("Case %d: %I64d\n",cas,ss);
    }
    return 0;
}






