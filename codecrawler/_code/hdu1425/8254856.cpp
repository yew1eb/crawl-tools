#include <cstdio>
#include <cstring>
#define MAXN 1000001
#define M 500000
using namespace std;
bool mark[MAXN];

int main()
{
    int n, m;
    int i, x;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(mark,0,sizeof(mark));
        for(i=0;i<n;++i)
        {
            scanf("%d",&x);
            mark[x+M]= 1;
        }
        for(i=MAXN-1;i>=0;--i)
            if(m&&mark[i])
            {
                --m;
                printf("%d",i-M);
                if(m)printf(" ");
                else printf("\n");
            }
    }
    return 0;
}
