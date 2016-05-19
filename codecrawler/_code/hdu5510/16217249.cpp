#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int f[2005];
char s[505][2005];
bool vis[505];
void getfill(char s[])
{
    memset(f, 0, sizeof(f));
    int len = strlen(s);
    for(int i = 1;i < len;i++)
    {
        int j = f[i];
        while(j&&s[i] != s[j])
            j = f[j];
        f[i+1] = (s[i] == s[j])?j+1:0;
    }
}
int find(char a[], char s[])
{
    getfill(s);
    int j = 0;
    int lena = strlen(a);
    int lens = strlen(s);
    for(int i = 0;i < lena;i++)
    {
        while(j&&a[i]!=s[j])
            j = f[j];
        if(a[i]==s[j])
            j++;
        if(j == lens)
            return 1;
    }
    return 0;
}
int main()
{
    int t, n, i, res, k, j, now, tp;
    scanf("%d", &t);
    k = 1;
    while(t--)
    {
        memset(vis, 0, sizeof vis);
        res = -1;
        now = 0;
        tp = 0;
        scanf("%d", &n);
        for(i = 0;i < n;i++)
        {
            scanf("%s", s[i]);
            for(j = 0;j <= i - 1;j++){
                if(vis[j]) continue;
                if(find(s[i], s[j])) vis[j] = 1;
                else res = i;
            }
        }
        if(res != -1) res++;
        printf("Case #%d: %d\n", k++, res);
    }
}
