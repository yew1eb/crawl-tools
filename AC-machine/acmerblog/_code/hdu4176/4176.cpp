#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 1000
int a[maxn];
int main()
{
    int i,j,t,n,ff=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int maxx=0;
        for(i=1;i<n;i++)
        {
            if(a[i]-a[i-1]>maxx)
                maxx=a[i]-a[i-1];
        }
        printf("Class %d\n",++ff);
        printf("Max %d, Min %d, Largest gap %d\n",a[n-1],a[0],maxx);
    }
}