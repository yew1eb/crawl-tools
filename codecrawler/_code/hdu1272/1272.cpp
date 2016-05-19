#include <cstdio>
#include <cstring>
#define maxn 100005
int fa[maxn];
bool ff[maxn];

int findd( int x )
{
    return fa[x] == x ? x : fa[x] = findd(fa[x]);
}
void init()
{
    memset(ff, false, sizeof(ff));
    for(int i = 1; i < maxn; i++)
        fa[i] = i;
}
int main()
{
	//freopen("d://in.txt", "r", stdin);
    int u,v,x,y,flag = 1;
    init();
    while(scanf("%d%d",&u,&v) == 2)
    {
        if(u == -1 && v == -1) break;
        else if(u+v == 0)
        {
            int k = 0;
            for(int i = 1; i < maxn; i++)
            {
                if(ff[i] && fa[i] == i)
                    k++;
            }
            if(flag && k <= 1)
                puts("Yes");
            else
                puts("No");
            init();
            flag = 1;
        }
        else
        {
            ff[u] = ff[v] = true;
            x = findd(u), y = findd(v);
            if(x != y)
                fa[x] = y;
            else
                flag = 0;
        }
    }
    return 0;
}