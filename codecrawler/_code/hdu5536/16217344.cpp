#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int N = 1024;

int a[N];
int twochild[2];

struct Trie
{
    int next[2];
    int flag;
    int cnt;
    void init()
    {
        next[0] = next[1] = -1;
        flag = -1;
        cnt = 0;
    }
};

Trie trie[N<<6];
int sz;

void init()
{
    sz = 1;
    trie[0].init();
}

void myinsert(int n, int t1)
{
    int p = 0;
    for(int i = 30; i >= 0; i--)
    {
        int ch = n&(1<<i);
        if(ch) ch = 1;
        if(trie[p].next[ch] == -1)
        {
            trie[p].next[ch] = sz;
            trie[sz++].init();
        }
        p = trie[p].next[ch];
    }
    int cnt = trie[p].cnt;
    if(cnt < 1)
        trie[p].flag = t1;
    trie[p].cnt++;
}

int myquery(int n, int t1, int t2, int seq)
{
    int p = 0;
    twochild[seq] = -1;
    int ret = 0;
    int j = -1;
    for(int i = 30; i >= 0; i--)
    {
        int ch = n & (1 << i);
        if(ch) ch = 1;
        for(j = seq-1; j >= 0; j--){
            if(p == twochild[j])
                break;
        }

        if(j >= 0)
        {
            p = trie[p].next[ch];
            continue;
        }

        if(trie[p].next[0] != -1 && trie[p].next[1] != -1){
            twochild[seq] = p;
        }
        if(trie[p].next[!ch] != -1)
        {
            ret |= (1<<i);
            p = trie[p].next[!ch];
        }
        else p = trie[p].next[ch];
    }
    /*if((trie[p].flag[0] != -1 && trie[p].flag[0] != t1 && trie[p].flag[0] != t2) ||
            (trie[p].flag[1] != -1 && trie[p].flag[1] != t1 && trie[p].flag[1] != t2) || trie[p].cnt > 2)
        return ret;*/
     if(t1 != trie[p].flag && t2 != trie[p].flag)
        return ret;
    if(a[t1] != a[t2] && trie[p].cnt > 1)
        return ret;
    if(a[t1] == a[t2] && trie[p].cnt > 2)
        return ret;

    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        init();
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            myinsert(a[i], i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
            {
                int tmp = myquery(a[i]+a[j], i, j, 0);
                if(tmp == -1) tmp = myquery(a[i]+a[j], i, j, 1);
                if(tmp == -1) tmp = myquery(a[i]+a[j], i, j, 2);
                ans = max(ans, tmp);
            }
        printf("%d\n", ans);
    }
    return 0;
}

/*
10
5
19 42 82 84 16
5
29 2 41 18 13
*/
