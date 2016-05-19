#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    char str[100];
    double p,q;
    double ans=0;
    while(~scanf("%s%lf%lf",str,&p,&q))
    {
        ans=ans+p*q;
    }
    printf("%.1lf\n",ans);//èªå¨ä¼åèäºå¥
    return 0;
}
