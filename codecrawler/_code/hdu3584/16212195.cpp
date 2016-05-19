#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int n, m;
int a[111][111][111];
int lowbit(int x)
{
    return x & (-x);
}
void modify(int x, int y, int z)
{
    for(int i=x; i<=n; i+=lowbit(i))
    {
        for(int j=y; j<=n; j+=lowbit(j))
        {
            for(int k=z; k<=n; k+=lowbit(k))
            {
                a[i][j][k] ^= 1;
            }
        }
    }
}
int query(int x, int y, int z)
{
    int res = 0;
    for(int i=x; i>0; i-=lowbit(i))
    {
        for(int j=y; j>0; j-=lowbit(j))
        {
            for(int k=z; k>0; k-=lowbit(k))
            {
                res += a[i][j][k];
            }
        }
    }
    return res;
}
int main()
{
    int x1, y1, z1, x2, y2, z2, x, y, z;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(a, 0, sizeof a);
        while(m--)
        {
            int op;
            scanf("%d", &op);
            if(op == 1)
            {
                scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
                x2++;
                y2++;
                z2++;
                modify(x1, y1, z1);
                modify(x1, y1, z2);
                modify(x1, y2, z1);
                modify(x1, y2, z2);
                modify(x2, y1, z1);
                modify(x2, y1, z2);
                modify(x2, y2, z1);
                modify(x2, y2, z2);
            }
            else
            {
                scanf("%d%d%d", &x, &y, &z);
                if(query(x, y, z) % 2)
                {
                    printf("1\n");
                }
                else
                {
                    printf("0\n");
                }
            }
        }
    }
    return 0;
}
