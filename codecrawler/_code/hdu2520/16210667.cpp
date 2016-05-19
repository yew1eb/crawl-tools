#include<iostream>
using namespace std;
int main()
{
    int t,v,s,n,i;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            scanf("%d",&n);
            s=0;v=1;
            for(i=1;i<=n;i++)
            {
                s=(s+v)%10000;
                v=(v+2)%10000;
            }
            printf("%d\n",s);
        }
    }
    return 0;
}