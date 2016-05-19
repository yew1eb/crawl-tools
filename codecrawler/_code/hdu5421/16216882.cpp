#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <queue>

#define M 110
#define N 150000
using namespace std;

class Node
{
public:
    int next[30], pre, num, len, preNum;
    void init(int _len)
    {
        memset(next, 0, sizeof next);
        pre = 0;
        num = 0;
        len = _len;
        preNum = 0;
    }
};
Node node[N];

class PaliTree
{
public:
    int cnt, str[N*3], o, root0, root1, r, l, last[2];
    long long paliSum;
    int newNode(int _len)
    {
        node[++cnt].init(_len);
        return cnt;
    }
    void init(int _n)
    {
        o = _n;
        cnt = -1;
        root0 = newNode(0);
        root1 = newNode(-1);
        last[0] = last[1] = root0;
        l = o; r = o-1;
        str[l-1] = str[r+1] = -1;
        node[root0].pre = root1;
        paliSum = 0;
    }
    int getFail(int p, int dir)
    {
        if(dir == 1)
        {
            for(; str[r-node[p].len-1] != str[r]; p = node[p].pre);
        }
        else
        {
            for(; str[l+node[p].len+1] != str[l]; p = node[p].pre);
        }
        return p;
    }
    void extend(char _ch, int dir) // dir ä¸º0 åå·¦æå¥
    {
        int ch = _ch-'a';
        if(dir == 0)
        {
            str[--l] = ch;
            str[l-1] = -1;
        }
        else
        {
            str[++r] = ch;
            str[r+1] = -1;
        }
        int cur = getFail(last[dir], dir);
        int nxt = node[cur].next[ch];
        if(!nxt)
        {
            nxt = newNode(node[cur].len+2);
            node[nxt].pre = node[getFail(node[cur].pre, dir)].next[ch];
            node[nxt].preNum = node[node[nxt].pre].preNum+1;
            node[cur].next[ch] = nxt;
        }
        last[dir] = nxt;
        if(dir == 0 && l+node[nxt].len-1 == r)
        {
            last[dir^1] = nxt;
        }
        else if(dir == 1 && r-node[nxt].len+1 == l)
        {
            last[dir^1] = nxt;
        }
        node[nxt].num++;
        paliSum += node[nxt].preNum;
    }
    int query1()
    {
        return cnt-1;
    }
    long long query2()
    {
        return paliSum;
    }
};

PaliTree tree;
int main()
{
    //freopen("C:\\Users\\zfh\\Desktop\\in.txt", "r", stdin);
    int q;
    while(scanf("%d", &q) != -1)
    {
        int type;
        char ch;
        tree.init(150000);
        for(int i = 0; i < q; i++)
        {
            scanf("%d", &type);
            if(type == 1)
            {
                scanf(" %c", &ch);
                tree.extend(ch, 0);
            }
            else if(type == 2)
            {
                scanf(" %c", &ch);
                tree.extend(ch, 1);
            }
            else if(type == 3)
            {
                printf("%d\n", tree.query1());
            }
            else printf("%I64d\n", tree.query2());
        }
    }
    return 0;
}
