#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct str{
 char s[55];
 int l;
};

bool operator <(str a, str b)
{
 if (strcmp(a.s, b.s) < 0)
 return 1;
 return 0;
}

str st[100010];

int main()
{
 int i,j,k;
 int n;
 while (scanf("%d", &n) != EOF)
 {
 for (i = 0;i < n;i++)
 {
 scanf("%s", st[i].s);
 st[i].l = strlen(st[i].s);
 }
 sort(st,st + n);
 int ans = st[0].l;
 int mx = st[0].l;
 for (i = 1;i < n;i++)
 {
 if (st[i].l > mx)
 mx = st[i].l;
 k = min(st[i - 1].l, st[i].l);
 for (j = 0;j < k;j++)
 {
 if (st[i - 1].s[j] != st[i].s[j])
 break;
 }
 ans += st[i].l - j;
 }
 ans = ans * 2 - mx + n;
 printf("%d\n", ans);
 }
 return 0;
}