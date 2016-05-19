#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<string>
typedef long long ll;
using namespace std;
const ll maxn=100005;
int T,n,m,f[maxn],a[10];

int check(int x)
{
    memset(a,0,sizeof(a));
    for (int i=0;x;x/=10)
        if (a[x%10]) return 0; else a[x%10]=1;
    return 1;
}

void pre()
{
    for (int i=1;i<=100000;i++)
        f[i]=f[i-1]+check(i);
}

int main()
{
    pre();
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        printf("%d\n",f[m]-f[n-1]);
    }
}