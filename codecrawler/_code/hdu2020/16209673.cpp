#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
bool comp(int x,int y)
{
    return abs(x)>abs(y);
}
int main()
{
    int n,i,a[101];
    while(~scanf("%d",&n)&&n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n,comp);
        for(i=0;i<n;i++)
        {
            if(i==0) printf("%d",a[0]);
            else
                printf(" %d",a[i]);
        }
        printf("\n");
    }
    return 0;
}