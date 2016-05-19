#include <queue>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define CLR(a,v) memset(a,v,sizeof(a))

const int mod = 20090717;

namespace Trie
{
    const int N = 255;
    const int Size = 26;
    int top;
    struct Node{
        Node *next[Size], *f;
        //int ended_cnt;
        int ended_val;
    }node[N], *root;
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
            int id = s[i] - 'a';
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
    int dp[26][N][1<<10];
    int bit_cnt[1<<10];
    void pre()
    {
        bit_cnt[0] = 0;
        for(int mask=1;mask<(1<<10);mask++)
        {
            bit_cnt[mask] = bit_cnt[mask>>1] + (mask & 1);
        }
    }
    int solve(int n,int m,int k)
    {
        //memset(dp,0,sizeof(dp));        //TLE
        for(int i=0;i<=n;i++)
            for(int j=0;j<top;j++)
                for(int mask=0;mask<(1<<m);mask++)
                    dp[i][j][mask] = 0;
        dp[0][0][0] = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<top;j++)
            {
                for(int mask=0;mask<(1<<m);mask++)
                {
                    if(dp[i][j][mask] == 0)
                        continue;
                    for(int kk=0;kk<Size;kk++)
                    {
                        int jj = node[j].next[kk] - node;
                        (dp[i+1][jj][mask | node[jj].ended_val] += dp[i][j][mask]) %= mod;
                    }
                }

            }
        }
        int ans = 0;
        for(int j=0;j<top;j++)
            for(int mask=0;mask<(1<<m);mask++)
                if(bit_cnt[mask] >= k)
                    (ans += dp[n][j][mask]) %= mod;
        return ans;
    }
}

char str[30];

int main()
{
    ACam::pre();
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k),n||m||k)
    {
        ACam::init();
        for(int i=0;i<m;i++)
        {
            scanf("%s",str);
            ACam::insert(str,1<<i);
        }
        ACam::get_fail();
        int ans = ACam::solve(n,m,k);
        printf("%d\n",ans);
    }
    return 0;
}