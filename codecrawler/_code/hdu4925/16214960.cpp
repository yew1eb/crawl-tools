#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

__int64 a[105][105];

void set()
{
    int i,j;
    a[1][1] = 1;
    a[2][2] = 8;
    a[1][2] = 2;
    for(i = 3;i<=100;i++)
    a[i][i] = (8*(i-1)*(i-1));
    for(i = 1;i<=100;i++)
    {
        for(j = i+1;j<=100;j++)
        {
            if(i == 1)
            {
                if(j == 2)
                continue;
                else
            a[i][j] = a[i][j-1]+2;
            }
            else
            a[i][j] = a[i][j-1]+a[i][i]/(i-1);
        }
    }
}

int main()
{
    set();
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(n>m)
        swap(n,m);
        printf("%I64d\n",a[n][m]);
    }

    return 0;
}