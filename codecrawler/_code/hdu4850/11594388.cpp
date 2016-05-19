#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 26 * 26 * 26 * 26 + 3;

char s[maxn + 10];

bool vis[1000000];

int main()
{
    //printf("%d\n", maxn);
    int i, j, k;
    s[0] = 'z';
    s[1] = 'z';
    s[2] = 'z';
    memset(vis, false, sizeof(vis));
    for(i = 3; i < maxn; i++)
    {
        int now = ((s[i - 3] - 'a') << 15) + ((s[i - 2] - 'a') << 10) + ((s[i - 1] - 'a') << 5);
        char c;
        for(c = 'a'; c <= 'z'; c++)
        {
            if(!vis[now + c - 'a'])
            {
                s[i] = c;
                vis[now + c - 'a'] = true;
                break;
            }
        }
        if(c > 'z') break;
    }
    s[i] = 0;
    /*printf("i = %d, maxn = %d\n", i, maxn);
    //puts(s);
    ///zzzaaaabaaacaaadaaaeaaafaaagaaahaaaiaaaj
    //return 0;
    memset(vis, false, sizeof(vis));
    for(i = 4; i < maxn; i++)
    {
        int now = ((s[i - 3] - 'a') << 15) + ((s[i - 2] - 'a') << 10) + ((s[i - 1] - 'a') << 5) + (s[i] - 'a');
        if(vis[now]) break;
        vis[now] = true;
    }
    printf("%d\n", i);*/

    int n;
    while(scanf("%d", &n) != EOF)
    {
        if(n > maxn)
        {
            puts("Impossible");
            continue;
        }
        char c = s[n];
        s[n] = 0;
        puts(s);
        s[n] = c;
    }
    return 0;
}
