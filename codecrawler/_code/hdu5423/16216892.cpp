#include<iostream>
#include<vector>
#include<queue>
#define maxn 1005
using namespace std;
int n;
vector<int>mapp[maxn];
int visit[maxn];
void init()
{
    for(int i=0;i<=n;i++)
    {
        visit[i]=0;
        mapp[i].clear();
    }
}
void input()
{
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        mapp[x].push_back(y);
        mapp[y].push_back(x);
    }
}
void bfs()
{
    queue<int>q;
    int sum=1;
    q.push(1);
    visit[1]=1;
    while(q.size())
    {
        int x=q.front();
        q.pop();
        int k=0;
        for(int i=0;i<mapp[x].size();i++)
        {
            int y=mapp[x][i];
            if(visit[y]) continue;
            visit[y]=1;
            k++;
            q.push(y);
        }
        sum+=k;
        if(k!=1) break;
    }
    //cout<<sum<<endl;
    if(sum==n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{
    cin.sync_with_stdio(false);
    while(cin>>n)
    {
        init();
        input();
        bfs();
    }
    return 0;
} 