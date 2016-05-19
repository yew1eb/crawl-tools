#include<cstdio>
#include<algorithm>
#define MAXN 35
using namespace std;

struct S{
    int n, l;
};

bool cmp(S a, S b)
{
    return a.l < b.l;
}

int main()
{
    int t, n;
    S s[MAXN];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &s[i].l, &s[i].n);
        sort(s, s+n, cmp);
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < s[i].n; k++)
            {
                printf(">+");
                for (int j = 0; j < s[i].l - 2; j++)
                    printf("-");
                printf("+>\n");
            }
            printf("\n");
        }
    }
    return 0;
}