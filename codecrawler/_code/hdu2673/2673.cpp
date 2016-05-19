#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int a[10010];
        for (int i=0; i<n; i++)
        scanf("%d",&a[i]);
        sort(a,a+n);
        int begin=0,end=n-2,flag=1;
        printf("%d",a[n-1]);
        while (begin<=end)
        {
            if (flag) {printf(" %d",a[begin]); begin++;}
            else {printf(" %d",a[end]); end--;}
            flag^=1;
        }
        printf("\n");   
    }
    return 0;
}