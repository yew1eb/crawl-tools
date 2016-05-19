#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <climits>
using namespace std;

#define LS 2*i
#define RS 2*i+1
#define UP(i,x,y) for(i=x;i<=y;i++)
#define DOWN(i,x,y) for(i=x;i>=y;i--)
#define MEM(a,x) memset(a,x,sizeof(a))
#define W(a) while(a)
#define gcd(a,b) __gcd(a,b)
#define LL long long
#define N 10090
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define rank rank1
const int mod = 10007;

int f[N],len,t,cas=1;
char str[N];

int main()
{
    int i,j,k,ans;
    f[0] = 1;
    f[1] = 1;
    for(i = 2;i<N;i++)
    {
        f[i] = (f[i-1]+f[i-2])%mod;
    }
    scanf("%d",&t);
    while(t--)
    {
        ans = 0;
        int cnt = 0;
        scanf("%s",str);
        len = strlen(str);
        str[len++] = '#';
        str[len] = '\0';
        for(i = 1;i<=len;i++)
        {
            if(str[i]=='e'&&str[i-1]=='h')
            {
                cnt++;
                i++;
            }
            else
            {
                if(ans==0)
                {
                    ans = f[cnt];
                }
                else
                {
                    ans = (ans*f[cnt])%mod;
                }
                cnt = 0;
            }
        }
        printf("Case %d: %d\n",cas++,ans);
    }

    return 0;
}
