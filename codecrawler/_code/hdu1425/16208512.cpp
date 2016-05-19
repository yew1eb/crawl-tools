#include <iostream>
using namespace std;
#include <algorithm>
#include <cstring>
int a[1000010];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,m,i;

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++)
        {
            scanf("%d",a+i);
        }
        sort(a,a+n,cmp);
        int flag=0;
        for(i=0;i<n,m>0;m--,i++)
        {
            if(!flag)
            {
                printf("%d",a[i]);
                flag=1;
            }
            else
                printf(" %d",a[i]);
        }
        printf("\n");
    }
    return 0;
}