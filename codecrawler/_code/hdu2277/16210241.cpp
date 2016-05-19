#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int a[3];
    while(~scanf("%d%d%d",&a[0],&a[1],&a[2]))
    {
        sort(a,a+3);
        if(a[0]==a[1]||(a[1]-a[0])%3==0)
        {
            printf("%d\n",a[1]);
        }
        else if(a[1]==a[2]||(a[2]-a[0])%3==0||(a[2]-a[1])%3==0)
        {
            printf("%d\n",a[2]);
        }
        else
        {
            printf("):\n");
        }
    }
    return 0;
 } 