#include<stdio.h>
#include<algorithm>
using namespace std;
bool comp(int x,int y)
{
    return x>y;
}
int a[1000001];
int main()
{
    int s,n,m,i;
    while(~scanf("%d %d",&n,&m))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n,comp);
        for(i=0;i<m;i++)
        {
            if(i==0) {printf("%d",a[0]);}
            else {printf(" %d",a[i]);}
        }
        printf("\n");
    }
    return 0;
}
 
