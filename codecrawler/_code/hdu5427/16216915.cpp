#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-6;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
#define ll long long
#define CL(a) memset(a,0,sizeof(a))

struct node
{
    int num;
    char name[110];
}s[110];

int cmp(node a, node b)
{
    return a.num>b.num;
}

int main ()
{
    int T,n;
    char ch[110];
    scanf ("%d",&T);
    while (T--)
    {
        scanf ("%d",&n);
        getchar();
        for (int i=0; i<n; i++)
        {
            gets(ch);
            int l=strlen(ch);
            s[i].num=(ch[l-4]-'0')*1000+(ch[l-3]-'0')*100+(ch[l-2]-'0')*10+ch[l-1]-'0';
            ch[l-5]='\0';
            strcpy(s[i].name, ch);
        }
        sort(s, s+n, cmp);
        for (int i=0; i<n; i++)
        {
            puts(s[i].name);
        }
    }
    return 0;
}
