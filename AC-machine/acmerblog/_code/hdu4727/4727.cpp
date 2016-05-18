#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int num[100005];

int main()
{
    int T,cas = 1,n,i,x,flag;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        x = -1;
        flag = -1;
        for(i = 0; i<n; i++)
            scanf("%d",&num[i]);
        for(i = 1;i<n;i++)
        {
            if(num[i]-num[i-1]!=1)
            flag = i+1;
        }
        if(flag==-1)
        flag = 1;
        printf("Case #%d: ",cas++);
        printf("%d\n",flag);
    }

    return 0;
}
