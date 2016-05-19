#include <stdio.h>
#include <string.h>
int C[50005], n;
typedef int LL;

int lowbit(int x) {return (x&-x);}
void add(int i, int d) {for(; i <= n; i += lowbit(i)) C[i] += d;}
LL query(int i) {LL ret = 0; for(; i > 0; i -= lowbit(i)) ret += C[i]; return ret;}

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
                printf("%d\n",query(y)-query(x-1));
        }
    }
    return 0;
}