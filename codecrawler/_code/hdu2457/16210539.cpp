#include <queue>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define CLR(a,v) memset(a,v,sizeof(a))

namespace Trie
{
    const int N = 1005;
    const int Size = 4;
    int top;
    struct Node{
        Node *next[Size], *f;
        //int ended_cnt;
        int ended_val;
    }node[N], *root;
    inline int get_id(char c)
    {
        if(c == 'A')    return 0;
        if(c == 'G')    return 1;
        if(c == 'C')    return 2;
        if(c == 'T')    return 3;
        return 5;
    }
    inline Node* new_node()
    {
        //node[top].ended_cnt = 0;
        node[top].ended_val = 0;
        CLR(node[top].next,NULL);
        return &node[top++];
    }
    void init()
    {
        top = 0;
        root = new_node();
    }
    void insert(char *s,int val=1)
    {
        Node *u = root;
        for(int i=0;s[i];i++)
        {
            int id = get_id(s[i]);
            if(u->next[id] == NULL)
                u->next[id] = new_node();
            u = u->next[id];
        }
        //u->ended_cnt++;
        u->ended_val = val;
    }
}

namespace ACam
{
    using namespace Trie;
    void get_fail()
    {
        queue<Node*> Q;
        for(int i=0;i<Size;i++)
        {
            Node *&ch = root->next[i];
            if(!ch)
                ch = root;
            else
            {
                ch->f = root;
                Q.push(ch);
            }
        }
        while(!Q.empty())
        {
            Node *cur = Q.front();Q.pop();
            for(int i=0;i<Size;i++)
            {
                Node *&ch = cur->next[i];
                if(!ch)
                    ch = cur->f->next[i];
                else
                {
                    ch->f = cur->f->next[i];
                    ch->ended_val |= ch->f->ended_val;
                    Q.push(ch);
                }
            }
        }
    }
    int dp[N][N];
    int solve(char *s)
    {
        int n = strlen(s);
        memset(dp,63,sizeof(dp));
        const int inf = dp[0][0];
        dp[0][0] = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<top;j++)
            {
                if(dp[i][j] == inf)
                    continue;
                for(int k=0;k<Size;k++)
                {
                    int jj = node[j].next[k] - node;
                    if(node[jj].ended_val)
                        continue;
                    dp[i+1][jj] = min(dp[i+1][jj],dp[i][j] + (get_id(s[i]) != k ? 1 : 0));
                }
            }
        }
        int ans = inf;
        for(int j=0;j<top;j++)
            ans = min(ans,dp[n][j]);
        return ans == inf ? -1 : ans;
    }
}

char str[1005];

int main()
{
    int n, ncase = 0;
    while(~scanf("%d",&n),n)
    {
        ACam::init();
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            ACam::insert(str);
        }
        ACam::get_fail();
        scanf("%s",str);
        int ans = ACam::solve(str);
        printf("Case %d: %d\n",++ncase,ans);
    }
    return 0;
}