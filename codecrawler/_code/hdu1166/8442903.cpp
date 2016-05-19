#include <stdio.h>
#include <string.h>
int C[50005], n;

int lowbit(int x)
{
    return x &(-x);
}

int sum(int x)
{
    int ret = 0;
    while(x>0)
    {
        ret += C[x];
        x -= lowbit(x);
    }
    return ret;
}

int add(int x, int d)
{
    while(x<=n)
    {
        C[x] +=d;
        x += lowbit(x);
    }
}

int main()
{
    int T,cases = 0, x, y, i;
    char s[20];
    scanf("%d",&T);
    while(cases++<T)
    {
        memset(C,0,sizeof(C));
        printf("Case %d:\n",cases);
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&x);
            add(i+1, x);
        }
        while(scanf("%s",s))
        {
            if(s[0]=='E') break;
            scanf("%d%d",&x,&y);
            if(s[0]=='A')   add(x, y);
            if(s[0]=='S')   add(x, -y);
            if(s[0]=='Q')
                printf("%d\n",sum(y)-sum(x-1));
        }
    }
    return 0;
}





