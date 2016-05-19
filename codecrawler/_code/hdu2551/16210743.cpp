#include<iostream>
using namespace std;
int main()
{
    int t;
    __int64 x,i;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            scanf("%I64d",&x);
            for(i=1;;i++)
            {
                if(i*i*(i+1)*(i+1)>=4*x)
                    break;
            }
            printf("%I64d\n",i);
        }
    }
    return 0;
}