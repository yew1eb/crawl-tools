#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
#define ll __int64
#define up(i,x,y) for(i=x;i<=y;i++)
#define up2(i,x,y) for(i=x;y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define down2(i,x,y) for(i=x;y;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ss(a) scanf("%d",&a)
#define s64(a) scanf("%I64d",&a)
#define w(a) while(a)

int main()
{
    int a,s,i,n;
    w(~ss(n))
    {
        s=0;
        up(i,0,n-1)
        {
            ss(a);
            s^=a;
        }
        if(s)
            printf("Win\n");
        else
            printf("Lose\n");
    }

    return 0;
}
