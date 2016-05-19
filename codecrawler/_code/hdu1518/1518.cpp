#include <iostream>
using namespace std;

int s[23], n, m, k, l;
bool f, v[23];
void dfs(int l, int u, int c)
{
    if (l==0) l = k, u = m-1, c++;
    if (c>2) f = 1;
    if (f) return ;
    for (int i=u;i>=0;--i)
    if (!v[i] && s[i]<=l)
    {
        v[i] = 1;
        dfs(l-s[i], i-1, c);
        if (f) break;
        v[i] = 0;
        if (l==s[i]) return;
        if (l==k) return;
        while (s[i-1]==s[i]) i--;
    }
}

int main()
{
    for (scanf("%d", &n);n;n--)
    {
        scanf("%d", &m);
        for (int i=f=k=l=0;i<m;scanf("%d", &s[i]),v[i]=0,l+=s[i++])
        if (k<s[i]) s[i] = k;
        sort(s, s+m);
        if (l%4==0 && k<=l/4)
        dfs(k=l/4, m-1, 0);
        if (f) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}