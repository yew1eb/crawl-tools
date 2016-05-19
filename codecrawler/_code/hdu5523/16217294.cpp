#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn = 300005;
int T, n, s, t;

int main()
{
    //scanf("%d", &T);
    while (scanf("%d%d%d", &n, &s, &t) != EOF)
    {
        if (n == 1) printf("0\n"); 
        else if (s == t) printf("-1\n");
        else if (s == 1 && t == n || s == n&&t == 1) printf("0\n");
        else if (s == 1 && t<n || s == n && t>1) printf("1\n");
        else if (s == t + 1 || s == t - 1) printf("1\n");
        else printf("2\n");
    }
    return 0;
}