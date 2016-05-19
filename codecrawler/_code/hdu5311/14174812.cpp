#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 23333;

char str[200];
const char s[100] = "anniversary";
int sl = 11;
int n;

int solve()
{
    for(int i=1; i<=n; ++i) {
        int l1 = 0;
        while(l1<sl-2 && str[i+l1] == s[l1]) l1++;
        if(l1==0) continue;
        for(int j=i+l1; j<=n; ++j) {
            int l2 = 0;
            while(l1+l2<sl-1 && str[j+l2] == s[l1+l2]) l2++;
            if(l2==0) continue;
            for(int k=j+l2; k<=n; ++k) {
                int l3 = 0;
                while(l1+l2+l3<sl && str[k+l3] == s[l1+l2+l3]) l3++;
                if(l1+l2+l3==sl){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", str+1);
        n = strlen(str+1);
        puts(solve() ?"YES":"NO");
    }
    return 0;
}

