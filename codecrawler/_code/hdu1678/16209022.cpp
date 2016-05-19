#include <stdio.h>
#include<algorithm>
using namespace std;
#define maxn 20000
int a[maxn];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        int sum=0;
        sort(a,a+n,cmp);
        for(i=2;i<n;i+=3) sum+=a[i];
        printf("%d\n",sum);

    }
    return 0;
}
