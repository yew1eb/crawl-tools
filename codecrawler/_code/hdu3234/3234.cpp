/*
 *  解法: 带权并查集神题.
 *        设置了一个超级根, 如果树中的一个数可以确认, 则将这棵树连接到超级根上.
 *        这样就简化了算法复杂性.
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 20005;
int N, Q, pare[maxn], cnt;
__int64 edge[maxn];
bool flag;
void init()
{
    cnt = 0;
    flag = 1;
    memset(pare, -1, sizeof(pare));
}
void Conflict()
{
    flag = 0;
    printf("The first %d facts are conflicting./n", cnt);
}
void find(int x, int &r, __int64 &v)
{
    if (pare[x] == -1)
    {
        r = x;
        v = 0;
    }
    else
    {
        find(pare[x], r, v);
        v = v ^ edge[x];
        edge[x] = v;
        pare[x] = r;
    }
}
void mearge(int x, int y, __int64 v)
{
    if (x > y)
        swap(x, y);
    pare[x] = y;
    edge[x] = v;
}
void Ifunc()
{
    char str[20];
    __int64 a, b, c;
    gets(str);
    if (!flag)
        return;
    cnt++;
    if (sscanf(str, "%I64d %I64d %I64d", &a, &b, &c) == 3)
    {
        int r1, r2;
        __int64 v1, v2;
        find(a, r1, v1);
        find(b, r2, v2);
        if (r1 == r2)
        {
            if (c != (v1 ^ v2))
            {
                Conflict();
            }
        }
        else
        {
            mearge(r1, r2, v1 ^ v2 ^ c);
        }
    }
    else
    {
        int r;
        __int64 v;
        find(a, r, v);
        if (r == N)
        {
            if (b != v)
            {
                Conflict();
            }
        }
        else
        {
            mearge(r, N, v ^ b);
        }
    }
}
void Qfunc()
{
    int k, x, i, r, ary[16], idx = 0;
    __int64 ans = 0, v;
    scanf("%d", &k);
    for (i = 0; i < k; i++)
    {
        scanf("%d", &x);
        find(x, r, v);
        ans = ans ^ v;
        if (r != N)
            ary[idx++] = r;
    }
    getchar();
    if (!flag)
        return;
    if (idx % 2 == 1)
    {
        printf("I don't know./n");
        return;
    }
    sort(ary, ary + idx);
    for (i = 0; i < idx; i += 2)
        if (ary[i] != ary[i+1])
            break;
    if (i != idx)
        printf("I don't know./n");
    else
        printf("%I64d/n", ans);
}
void InputCmd()
{
    char cmd;
    scanf("%c", &cmd);
    if (cmd == 'I')
        Ifunc();
    else
        Qfunc();
}
int main()
{
    int i, cas = 1;
    while (scanf("%d %d", &N, &Q), N || Q)
    {
        getchar();
        printf("Case %d:/n", cas++);
        init();
        for (i = 0; i < Q; i++)
        {
            InputCmd();
        }
        printf("/n");
    }
    return 0;
}