#include <queue>
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int N = 1e4 + 5;

#define CLR(a,v) memset(a,v,sizeof(a))

int n,k;

bool vis[N];

pair<int,int> bfs1()
{
    pair<int,int> ans = make_pair(N,N);
    for(int x=1;x<k;x++)
    {
        CLR(vis,false);
        int cur_mod = 0;
        for(int l=1;;l++)
        {
            cur_mod = (cur_mod * k + x) % n;
            if(cur_mod == 0)
            {
                ans = min(ans,make_pair(l,x));
                break;
            }
            if(vis[cur_mod])
                break;
            vis[cur_mod] = true;
        }
    }
    return ans;
}

int pre[N];

char ansAt[N];

bool legal(int a,int b)
{
    queue<int> Q;
    Q.push(0);
    int num[2] = {a,b};
    while(!Q.empty())
    {
        int cur = Q.front();Q.pop();
        for(int i=0;i<2;i++)
        {
            if(cur == 0 && num[i] == 0)
                continue;
            int nxt = (cur * k + num[i]) % n;
            if(!vis[nxt])
            {
                vis[nxt] = true;
                pre[nxt] = cur;
                ansAt[nxt] = '0' + num[i];
                Q.push(nxt);
                if(nxt == 0)
                    return true;
            }
        }
    }
    return false;
}

#define size(v) (int)v.size()

bool __less(string& a,string& b){
    return size(a) < size(b) || size(a) == size(b) && a < b;
}

string sol;

void get_ans(){
    sol = "";
    int p = 0;
    while(p != 0 || sol.empty())
    {
        sol += ansAt[p];
        p = pre[p];
    }
    reverse(sol.begin(),sol.end());
}

string bfs2()
{
    string ans;
    for(int i=0;i<k;i++)
        for(int j=i+1;j<k;j++)
        {
            CLR(vis,false);
            if(!legal(i,j))
                continue;
            get_ans();
            if(ans.empty() || __less(sol,ans))
                ans = sol;
        }
    return ans;
}

int main()
{
    //freopen("out.ads","w",stdout);
    while(~scanf("%d%d",&n,&k))
    {
        pair<int,int> ans1 = bfs1();
        if(ans1.first != N)
        {
            while(ans1.first--)
                printf("%d",ans1.second);
            puts("");
        }
        else
        {
            string ans2 = bfs2();
            printf("%s\n",ans2.c_str());
        }
    }
    return 0;
}
