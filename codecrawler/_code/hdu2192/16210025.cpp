#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1000000];

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m,i;
        scanf("%d",&m);
        for(i = 0;i<m;i++)
        scanf("%d",&a[i]);
        sort(a,a+m);
        int l = 1,tem = a[0],max = 1;
        for(i = 1;i<m;i++)
        {
            if(a[i] == tem)
            {
                l++;
            }
            else
            {
                tem = a[i];
                l = 1;
            }
            if(l > max)
            max = l;
        }
        printf("%d\n",max);
    }

    return 0;
}
