#include <iostream>
#include <cstdio>
using namespace std;

int father[100005];

int find(int x)
{
    int num = 0;
    while(x!=father[x])
    {
        x = father[x];
        num++;
    }
    return num;
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m) && (n||m))
    {
        //int t = n-1;
        int x,y,i,a,b;
        for(i = 1; i<=n; i++)
            father[i] = i;
        for(i = 1; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            father[y] = x;
        }
        while(m--)
        {
            scanf("%d%d",&a,&b);
            int px = find(a);
            int py = find(b);
            if(px<=py)
                puts("lxh");
            else
                puts("pfz");
        }
    }

    return 0;
}
