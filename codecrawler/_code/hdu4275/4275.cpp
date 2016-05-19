/*
 * Author: Gatevin
 * Created Time:  2015/7/27 23:59:16
 * File Name: Sakura_Chiyo.cpp
 */
#pragma comment(linker, "/STACK:16777216")
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

//防CE
#define hash hhhhhhh
#define end eeeeend

/*
 * 第一次写树的Hash...愿顺利
 * 首先考虑到Karp-Rabin算法中对于树的同构问题避免不够好,没有采用Karp-Rabin的hash方式
 * 采用的hash表达式如下
 * 对于结点u, u有儿子结点v1, v2, ..., vk
 * 其中儿子结点的Hash值已经处理出来时H[1~k]
 * 那么首先对于Hash值进行排序, (相同的子树的hash值一定是一样的, 于是同构的子树一定会被排在一起
 * Hash(v) = ((...(((((a*p ^ H[1]) mod q) *p ^ H[2]) % q) * p ^ .... H[k - 1]) mod q)*p ^ H[k]) * b % q
 * 其中a, p, q, b为参数自选, ^表示异或, 这里没考虑优先级问题, 表达式从左向右计算
 * 用ans[v]表示结点v及其所在子树部分有ans[v]种不同的染色方式, 那么
 * 当我们知道了ans[v1~vk]之后, 考虑对于一段李旭相同的Hash值, 如果有k个子树Hash值相同同构, 这些子树是vi, vj...vt
 * 那么ans[vi] = ans[vj] = .. = ans[vt]是肯定的
 * 于是这几棵相同的子树能有的颜色的方案是相当于从ans[vi]个不同方案中挑出k个, 可重复挑选, 有多少个不同的组合方案
 * 这就可以用隔板法解决了, 相当于是k个物品分为ans[vi]组, 每组都可以为空, 有多少种分组方案, 组没有编号区别
 * 于是就是ans[vi] + k个物品分ans[vi]k组, 每组至少有1个有多少种分组方案
 * 于是就是从ans[vi] + k - 1个空隙中选出ans[vi] - 1个, 就分出来了, 方案数是C[ans[vi] + k - 1][ans[vi] - 1] = C[ans[vi] + k - 1][k]个
 * 那么对于不同的Hash的子树集合就直接是种数相乘了
 * 初始化叶子节点的ans是M(颜色种数), 单个结点的Hash值为a, 自选
 * 那么剩下的就只是一个树形DP问题了, 整体复杂度可以在O(nlogn)内解决
 *
 * 以上是在选定树的根节点的条件下做的计数工作
 * 那么如何选择这棵树的根节点呢?
 * 这里要用到树的重心, 也就是直径的中点, 如果直径上的点数是奇数, 取中间那个点作为根即可
 * 否则的话需要在中间添加一个节点作为根, 可以发现这样的点作为根一定不会
 * 出现选择除这个点之外的树上的点作为根之后得到同构树的情况
 * 而如果不这么选的话则不能保证这一点(取其他点作为根得到的树长的一样的情况)
 * 那么这题还需要先求出树的直径(直接两遍dfs找最远即可), 然后根据树的直径奇偶决定一些细节操作
 */
#define maxn 50010
const lint mod = 1e9 + 7;
const lint A = 233, P = 23333, Q = 1e9 + 1027, B = 50009;
int n, m;
int dis[maxn];
bool flag;//记录树的直径中有没有自己加一个节点作为中心
vector<int> dia;//储存直径的点
int start, end;//树的直径的起点和终点
lint hash[maxn], cnt[maxn];//hash[v]为以v为根及其子树的hash值, cnt[v]表示这棵子树有多少种不同的染色方案
int idx[maxn];//下标数组, 在对子树的hash值进行排序的时候采用
lint fac[maxn];//阶乘数组
vector<int> G[maxn];//存储树
int center;//树的中心

void dfs(int now, int fa)
{
    int nex;
    for(int i = 0, sz = G[now].size(); i < sz; i++) if((nex = G[now][i]) != fa)
    {
        dis[nex] = dis[now] + 1;
        dfs(nex, now);
    }
    return;
}

bool getDiameter(int now, int fa)
{
    int nex;
    for(int i = 0, sz = G[now].size(); i < sz; i++) if((nex = G[now][i]) != fa)
        if(getDiameter(nex, now))
        {
            dia.push_back(now);
            return true;
        }
    if(now == end)
    {
        dia.push_back(now);
        return true;
    }
    return false;
}

void diameter()//寻找树的直径, 确定中心
{
    dis[1] = 0;
    dfs(1, -1);
    start = 1;
    for(int i = 1; i <= n; i++)
        if(dis[start] < dis[i]) start = i;
    dis[start] = 0;
    dfs(start, -1);
    end = start;
    for(int i = 1; i <= n; i++)
        if(dis[end] < dis[i]) end = i;
    //到这里为止直径的两个端点是 (start, end)
    dia.clear();
    getDiameter(start, -1);//得到直径上的点, 从end到start
    if(dis[end] & 1)//直径上有偶数个结点, 需要添加一个center作为中心, 修改原来的树
    {
        flag = true;
        int centerLeft = dia[(dia.size() >> 1) - 1];
        int centerRight = dia[dia.size() >> 1];
        center = n + 1;
        G[center].push_back(centerLeft);
        G[center].push_back(centerRight);
        for(int i = 0, sz = G[centerLeft].size(); i < sz; i++)
            if(G[centerLeft][i] == centerRight)
            {
                G[centerLeft][i] = center;
                break;
            }
        for(int i = 0, sz = G[centerRight].size(); i < sz; i++)
            if(G[centerRight][i] == centerLeft)
            {
                G[centerRight][i] = center;
                break;
            }
    }
    else//直径上是奇数个点, 中间那个点就是中心
        center = dia[dia.size() >> 1];
    return;
}

lint quick(lint base, lint pow)
{
    lint ret = 1;
    while(pow)
    {
        if(pow & 1) ret = ret*base % mod;
        base = base*base % mod;
        pow >>= 1;
    }
    return ret;
}

lint C(int x, int y)//return x取y 其中y在预处理的范围内, 但是x不在 C[x][y] = x!/(y!*(x - y)!) 考虑x!/(x - y)!相乘的数的个数不超过y即可
{
    lint ret = 1;
    for(int i = 1; i + x - y <= x; i++)
        ret = ret*(x - y + i) % mod;
    ret = ret*quick(fac[y], mod - 2) % mod;
    return ret;
}

bool cmp(int x, int y)
{
    return hash[x] < hash[y];
}

void calc(int now, int fa)
{
    int nex;
    for(int i = 0, sz = G[now].size(); i < sz; i++) if((nex = G[now][i]) != fa)
        calc(nex, now);
    if(G[now].size() == 1)
    {
        hash[now] = A*B % Q;//hash值为A*B % Q
        cnt[now] = m;//有m种不同的染色方案
        return;
    }
    //否则需要根据所有子树的hash值排序来计算
    hash[now] = A*B % Q;
    cnt[now] = m;
    int num = 0;//在对子树排序的时候进行个数的记录
    for(int i = 0, sz = G[now].size(); i < sz; i++) if((nex = G[now][i]) != fa)
        idx[num++] = nex;
    sort(idx, idx + num, cmp);//根据hash值将下标从小到大进行排序
    for(int i = 0; i < num; i++)
    {
        nex = idx[i];
        hash[now] *= P;
        hash[now] ^= hash[nex];
        hash[now] %= Q;
    }
    hash[now] = hash[now] * B % Q;
    int st = 0;
    while(st < num)
    {
        lint val = hash[idx[st]];
        lint kinds = cnt[idx[st]];
        lint count = 1;
        st++;
        while(st < num && val == hash[idx[st]])//连续多棵同构的子树
            count++, st++;
        cnt[now] = cnt[now] * C(kinds + count - 1, count) % mod;
    }
    return;
}

int main()
{
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    fac[0] = 1;
    for(int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
    while(~scanf("%d %d", &n, &m))
    {
        for(int i = 1; i <= n + 1; i++) G[i].clear();
        for(int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        flag = false;
        diameter();//先找到树的直径
        calc(center, -1);
        if(flag)//添加过节点, 那么根节点的m种颜色应该不算
            printf("%I64d\n", cnt[center] * quick(m, mod - 2) % mod);
        else printf("%I64d\n", cnt[center]);
    }
    return 0;
}
/*
8 20314
2 1
3 1
4 3
5 1
6 4
7 5
8 3
*/
