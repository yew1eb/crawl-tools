#include <stdio.h>
#include <string.h>
const int Maxn = 100000 + 10;
int f[Maxn];
bool mark[Maxn];
int find(int x) { return f[x] == x ? x: f[x] = find(f[x]); }

bool check(int n)
{
    int i = 1, t;
    while(!mark[i]) i++;
    for(t = find(i), i++; i<=n; i++)
        if(mark[i] && find(i) != t) return false;
    return true;
}
int main()
{
    int x, y, i, A, B;
    int n;
    bool flag;
   // freopen("in.txt","r",stdin);
    scanf("%d%d",&x,&y);
    while(x!=-1 && y!=-1)
    {
        for(i = 1; i<=10000; i++) f[i] = i;
        memset(mark,false,sizeof(mark));
        n= 0; flag = true;
        while(x!=0 && y!=0 )
        {
            if(n < x) n = x;
            if(n < y) n = y;
            mark[x] = true; mark[y] = true;
            A = find(x); B = find(y);
            if(A == B) {flag = false;}
            f[A] = B;
            scanf("%d%d",&x,&y);
        }
        if(flag && check(n) )
            printf("Yes\n");
        else
            printf("No\n");
        scanf("%d%d",&x,&y);
    }
    return 0;
}
