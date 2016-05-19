#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#pragma warning(disable: 4996)

using namespace std;

const int MaxV = 10003;
const int MaxE = 20003;

struct Graph
{
    void init()
    {
        top = 0;
        memset(head, -1, sizeof(head));
    }
    void addEdge(int u, int v)
    {
        next[top] = head[u];
        head[u] = top;
        num[top] = v;
        top++;
    }
    int top;
    int head[MaxV], num[MaxE], next[MaxE];
};

Graph g;
int in[MaxV];
int logicalTopSort(int vexNum)
{
    int tmp[MaxV], indexx = 0;
    memset(in, 0, sizeof(in));
    for(int i = 1; i <= vexNum; i++)
    {
        for(int j = g.head[i]; j != -1; j = g.next[j])
        {
            int v = g.num[j];
            in[v]++;
        }
    }

    int cengci = 0;
    int res = 0;
    for(int i = 1; i <= vexNum; i++)
    {
        int s = 1;
        bool flag = false;
        for(int j = 1; j <= vexNum; j++)
        {
            if(in[j] == 0)
                tmp[s++] = j;
            if(in[j] != -1)
                flag = true;
        }
        if(s == 1 && flag)
            return -1;
        res += ((s - 1) * (888 + cengci));
        cengci++;
        for(int j = 1; j < s; j++)
        {
            in[tmp[j]] = -1;
            for(int k = g.head[tmp[j]]; k != -1; k = g.next[k])
            {
                in[g.num[k]]--;
            }
        }
    }
    return res;
}

int main()
{
    //freopen("data_in.txt", "r", stdin);
    int vexNum, edgeNum;
    int u, v;
    while(scanf("%d %d", &vexNum, &edgeNum) != EOF)
    {
        g.init();
        for(int i = 0; i < edgeNum; i++)
        {
            scanf("%d %d", &u, &v);
            g.addEdge(v, u);
        }
        int ans = logicalTopSort(vexNum);
        printf("%d\n", ans);
    }
    return 0;
}