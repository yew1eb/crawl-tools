#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
//#include <stdlib>
using namespace std;
struct p
{
    int num;//é¢ç®æ°
    int h;//å°æ¶
    int f1;//åé
    int m;//ç§
    int pos;//è®°å½ä½ç½®
} f[140];


int cmp(p x,p y)
{
    if(x.num==y.num)
    {
        if(x.h==y.h)
        {
            if(x.f1==y.f1)
            {
                return x.m<y.m;
            }
            else
                return x.f1<y.f1;
        }
        else
            return x.h<y.h;
    }
    else
        return x.num>y.num;
}
int main()
{
    int i;
    char ch;
    int n,g,s,c,m1;
    while(scanf("%d%d%d%d%d",&n,&g,&s,&c,&m1))
    {
        if((n+g+s+c+m1)==0)
            break;


        for(i=1; i<=n; i++)
        {
            scanf("%d%d%c%d%c%d",&f[i].num,&f[i].h,&ch,&f[i].f1,&ch,&f[i].m);
            f[i].pos=i;
        }
        sort(f+1,f+n+1,cmp);
        int sum;
        for(i=1; i<=n; i++)
        {
            if(f[i].pos==m1)
            {
                sum=i;
                break;
            }
        }
        if(sum<=g)
            printf("Accepted today? I've got a golden medal :)\n");
        else if(sum<=(g+s))
        {
            printf("Accepted today? I've got a silver medal :)\n");
        }
        else if(sum<=(g+s+c))
        {
            printf("Accepted today? I've got a copper medal :)\n");
        }
        else
            printf("Accepted today? I've got an honor mentioned :)\n");
    }
    return 0;
}