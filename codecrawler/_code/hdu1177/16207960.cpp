#include <stdio.h>
#include <algorithm>
using namespace std;

struct AC
{
    int num,h,m,s;
    int no;
    int k;//k=1éï¼2é¶ï¼3éï¼4,å®æ°å¥
} a[200];

int cmp(AC x,AC y)
{
    if(x.num!=y.num)
    return x.num>y.num;
    if(x.h!=y.h)
    return x.h<y.h;
    if(x.m!=y.m)
    return x.m<y.m;
    return x.s<y.s;
}

int main()
{
    int n,g,s,c,m,i;
    while(~scanf("%d%d%d%d%d",&n,&g,&s,&c,&m))
    {
        if(n+g+s+m+c == 0)
            break;
        for(i = 0; i<n; i++)
        {
            a[i].no = i+1;
            scanf("%d %d:%d:%d",&a[i].num,&a[i].h,&a[i].m,&a[i].s);
        }
        sort(a,a+n,cmp);
        //printf("====\n");
        for(i = 0; i<n; i++)
        {
            if(g)
            {
                a[i].k = 1;
                g--;
            }
            else if(s)
            {
                a[i].k = 2;
                s--;
            }
            else if(c)
            {
                a[i].k = 3;
                c--;
            }
            else
            {
                a[i].k = 4;
            }
        }
        for(i = 0; i<n; i++)
        {
            if(a[i].no == m)
            {
                if(a[i].k == 1)
                    printf("Accepted today? I've got a golden medal :)\n");
                else if(a[i].k == 2)
                    printf("Accepted today? I've got a silver medal :)\n");
                else if(a[i].k == 3)
                    printf("Accepted today? I've got a copper medal :)\n");
                else if(a[i].k == 4)
                    printf("Accepted today? I've got an honor mentioned :)\n");
                break;
            }
        }
    }

    return 0;
}
