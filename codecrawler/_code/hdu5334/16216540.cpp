#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<string>
#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
using namespace std;
const ll maxn=100005;
int T,n,m,f[maxn];

int main()
{
    //scanf("%d",&T);
    for (int i=1;i<=33000;i++) f[i]=i*i;
    while (~scanf("%d",&n))
    {
        /*if (n<=100000)
        {
            for (int i=1;i<=n;i++)
            {
                putchar('1');
                if (i<n) putchar(' '); else putchar(10); 
            }
        }
        else */
        {
            int k,u,a,b,c,flag=0;
            for (int i=1;i<=33000;i++)
            {
                k=n+f[i];
                u=sqrt(1.0*k);
                u=min(u,k/(i+i-1));
                for (int j=u;j>=i;j--)
                if (k%j==0) 
                {
                    c=i-1;
                    b=j-i;
                    a=k/j-i;
                    if (a+b+c<=100000) flag=true;
                    if (flag) break;
                }
                if (flag) break;
            }
            printf("%d\n",a+b+c);
            flag=0;
            for (int i=1;i<=a;i++) 
            {
                if (flag) printf(" "); else flag=1;
                printf("1");
            }
            for (int i=1;i<=b;i++)
            {
                if (flag) printf(" "); else flag=1;
                printf("2");
            }
            for (int i=1;i<=c;i++) 
            {
                if (flag) printf(" "); else flag=1;
                printf("1");
            }
            putchar(10);
        }
    }
    return 0;
}