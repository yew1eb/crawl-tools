/*
 * =====================================================================================
 *
 *       Filename:  hdu1512.cpp
 *
 *    Description:  Leftist Heap + Union Find Set
 *
 *        Version:  1.0
 *        Created:  2012å¹´02æ19æ¥ 21æ¶25å48ç§
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  SphinX (Whisper), sphinx2010@yahoo.cn
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <functional>
#include <algorithm>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <utility>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <limits>
#include <memory>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define LOWBIT(x) ( (x) & ( (x) ^ ( (x) - 1 ) ) )
#define CLR(x, k) memset((x), (k), sizeof(x))
#define CPY(t, s) memcpy((t), (s), sizeof(s))
#define SC(t, s) static_cast<t>(s)
#define LEN(s) static_cast<int>( strlen((s)) )
#define SZ(s) static_cast<int>( (s).size() )

typedef double LF;
typedef long long LL;    //g++
typedef unsigned long long ULL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;

typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<double> VF;
typedef vector<string> VS;

template <typename T>
T sqa(const T & x) { return x * x; }
template <typename T>
T ll(const T & x) { return x << 1; }
template <typename T>
T rr(const T & x) { return x << 1 | 1; }
    template <typename T>
T gcd(T a, T b)
{
    if (!a || !b)
    {
        return max(a, b);
    }
    T t;
    while (t = a % b)
    {
        a = b;
        b = t;
    }
    return b;
};

const int INF_INT = 0x3f3f3f3f;
const LL INF_LL = 0x7fffffffffffffffLL;        //15f
const double oo = 10e9;
const double eps = 10e-7;
const double PI = acos(-1.0);

#define  ONLINE_JUDGE

const int MAXN = 100004;

int n, m;
struct Node
{
    int val;
    Node * lch;
    Node * rch;
    int npl;

    Node() {}
    Node(int w, Node * lt = NULL, Node * rt = NULL, int np = 0)
        : val(w), lch(lt), rch(rt), npl(np) {}
};
Node * root[MAXN] = {NULL};
int ufs[MAXN], rk[MAXN];

void reclaimMemory(Node * t)
{
    if (t != NULL)
    {
        reclaimMemory(t->lch);
        reclaimMemory(t->rch);
    }
    return ;
}
void init(int n)
{
    for (int i = 0; i <= n; ++i)
    {
        reclaimMemory(root[i]);
        ufs[i] = i;
        rk[i] = 0;
    }
    return ;
}
Node * merge1(Node * h1, Node * h2);
Node * merge(Node * h1, Node * h2)
{
    if (NULL == h1)
    {
        return h2;
    }
    if (NULL == h2)
    {
        return h1;
    }
    if (h1->val > h2->val)
    {
        return merge1(h1, h2);
    }
    return merge1(h2, h1);
}
Node * merge1(Node * h1, Node * h2)
{
    if (NULL == h1->lch)
    {
        h1->lch = h2;
    }
    else
    {
        h1->rch = merge(h1->rch, h2);
        if (h1->lch->npl < h1->rch->npl)
        {
            swap(h1->lch, h1->rch);
        }
        h1->npl = h1->rch->npl + 1;
    }
    return h1;
}
void deleteMax(Node * & t)    //*, * & å¤ªåäººäºããã
{
    if (t != NULL)
    {
        Node * oldNode = t;
        t = merge(t->lch, t->rch);    //è¦ç¨* &å°±æ¯å ä¸ºè¿å¥
        delete oldNode;
    }
    return ;
}
int findUFS(int x)
{
    int tmp = x, buf;
    while (x != ufs[x])
    {
        x = ufs[x];
    }
    while (tmp != x)
    {
        buf = ufs[tmp];
        ufs[tmp] = x;
        tmp = buf;
    }
    return x;
}
void unionUFS(int x, int y)
{
    int tx = findUFS(x);
    int ty = findUFS(y);
    if (tx < ty)
    {
        ufs[ty] = tx;
    }
    else
    {
        ufs[ty] = tx;
    }
    return ;
}
void ace()
{
    int u, v, w;
    int x, y;
    int wx, wy;
    while (scanf("%d", &n) != EOF)
    {
        init(n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &w);
            root[i] = new Node(w);
        }
        for (scanf("%d", &m); m--; )
        {
            scanf("%d %d", &u, &v);
            x = findUFS(u);
            y = findUFS(v);
            if (x == y)
            {
                puts("-1");
                continue ;
            }
            wx = root[x]->val / 2;
            wy = root[y]->val / 2;
            deleteMax(root[x]);
            deleteMax(root[y]);
            root[x] = merge(root[x], new Node(wx));
            root[y] = merge(root[y], new Node(wy));
            unionUFS(x, y);
            root[x] = root[y] = merge(root[x], root[y]);
            printf("%d\n", root[x]->val);
        }
        
    }
    return ;
}
int main(int argc, char * argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ace();
    return EXIT_SUCCESS;
}
