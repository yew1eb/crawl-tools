#include <cstdio>
#define maxn 200
using namespace std;
int a[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int sum=0;
        while(n--)
        {
            int x,y;
            scanf("%d(%d)",&x,&y);
            int j=0;
            while(x)
            {
                a[j++]=x%10;//倒着存取
                x/=10;
            }
            int c=0;
            for(int i=j-1;i>=0;i--)//倒着读取
                c=c*y+a[i];
            sum+=c;
        }
        printf("%d\n",sum);
    }
    return 0;
}