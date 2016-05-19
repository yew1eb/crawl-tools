#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int t,n,m,i;
    while(~scanf("%d%d",&n,&m))
    {
        if(n<=m)//n<=måæå¿è
        {
            for(i = n; i<=m; i++)
                if(i==n)
                    printf("%d",i);
                else
                    printf(" %d",i);
            printf("\n");
            continue;
        }
        if(n%(m+1))//å¿èæ
        {
            int flag = 0;
            for(i = 1; i<=m; i++)
            {
                if((n-i)%(m+1)==0)//å¿é¡»çä¸m+1çåæ°
                {
                    if(flag == 0)
                        printf("%d",i);
                    else
                        printf(" %d",i);
                    flag++;
                }
            }
            printf("\n");
        }
        else
            printf("none\n");
    }

    return 0;
}
