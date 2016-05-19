/*
 * Author: Gatevin
 * Created Time:  2015/11/20 10:23:20
 * File Name: Sakura_Chiyo.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;
const double eps(1e-8);
typedef long long lint;

#define maxn (100010*2)
#define maxm 100010

struct Suffix_Automation
{
    struct State
    {
        State *par;
        State *go[26];
        int val;
        int mi;
        int cnt;
        int right;
        int leftmost;
        void init(int _val = 0)
        {
            par = 0, val = _val, cnt = 0, mi = 0, right = 0, leftmost = 1e9;
            memset(go, 0, sizeof(go));
        }
    };
    State *root, *last, *cur;
    State nodePool[maxn];
    State* newState(int val = 0)
    {
        cur->init(val);
        return cur++;
    }
    void initSAM()
    {
        cur = nodePool;
        root = newState();
        last = root;
    }
    void extend(int w, int head)
    {
        State *p = last;
        State *np = newState(p->val + 1);
        np->right = 1;
        np->leftmost = head;
        while(p && p->go[w] == 0)
        {
            p->go[w] = np;
            p = p->par;
        }
        if(p == 0)
        {
            np->par = root;
        }
        else
        {
            State *q = p->go[w];
            if(p->val + 1 == q->val)
            {
                np->par = q;
            }
            else
            {
                State *nq = newState(p->val + 1);
                memcpy(nq->go, q->go, sizeof(q->go));
                nq->leftmost = q->leftmost;
                nq->par = q->par;
                q->par = nq;
                np->par = nq;
                while(p && p->go[w] == q)
                {
                    p->go[w] = nq;
                    p = p->par;
                }
            }
        }
        last = np;
    }
    void solve(char *s)
    {
        initSAM();
        int n = strlen(s);
        int now = 0;
        while(now != n)
        {
            State* pos = root;
            int deep = 0;
            while(now < n && pos->go[s[now] - 'a'] != 0)
            {
                pos = pos->go[s[now] - 'a'];
                deep++;
                extend(s[now] - 'a', now);
                now++;
            }
            if(deep == 0)
            {
                extend(s[now] - 'a', now);
                printf("-1 %d\n", s[now++]);
            }
            else printf("%d %d\n", deep, pos->leftmost - deep + 1);
        }
    }
};

Suffix_Automation sam;
char s[maxm];

int main()
{
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        printf("Case #%d:\n", cas);
        scanf("%s", s);
        sam.solve(s);
    }
    return 0;
}
/*

2
aaaaaa
aaaaabbbbbaaabbc 

*/