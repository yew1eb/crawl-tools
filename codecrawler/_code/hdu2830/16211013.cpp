#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    int R,C,num[1005],a[1005];
    while(~scanf("%d%d",&R,&C))
    {
        getchar();
        int ans = 0;
        memset(num,0,sizeof(num));
        for(int i=1;i<=R;i++)
        {
            for(int j=1;j<=C;j++)
            {
                char c = getchar();
                if(c == '1')
                    ++num[j];
                else
                    num[j] = 0;
                a[j] = num[j];
            }
            sort(a+1,a+1+C,cmp);
            for(int j=1;j<=C && a[j];j++)
                if(a[j]*j > ans)
                    ans = a[j]*j;
            getchar();
        }
        printf("%d\n",ans);
    }
    return 0;
}
