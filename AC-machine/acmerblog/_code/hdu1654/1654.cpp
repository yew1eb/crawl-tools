#include<stdio.h>
#include<string.h>
char str[50], a[15], b[15], c[15];
int A, B, C, v[128], num[128], cnt, vis[15][128], hash[15];
void init()
{
    int i, j, k, x, y, z;
    A = strchr(str, '+') - str;
    B = strchr(str, '=') - strchr(str, '+') - 1;
    C = strlen(str) - (strchr(str, '=') - str) - 1;
    x = y = z = 0;
    for(i = 0, j = A - 1; str[i] != '+'; i ++, j --)
    {
        a[j] = str[i];
        if(str[i + 1] != '+' && v[str[i + 1]] > v[str[i]])
            x -= v[str[i]];
        else
            x += v[str[i]];
    }
    for(++ i, j = B - 1; str[i] != '='; i ++, j --)
    {
        b[j] = str[i];
        if(str[i + 1] != '=' && v[str[i + 1]] > v[str[i]])
            y -= v[str[i]];
        else
            y += v[str[i]];
    }
    for(++ i, j = C - 1; str[i]; i ++, j --)
    {
        c[j] = str[i];
        if(str[i + 1] && v[str[i + 1]] > v[str[i]])
            z -= v[str[i]];
        else
            z += v[str[i]];
    }
    if(x + y == z)
        printf("Correct ");
    else
        printf("Incorrect ");
}
int dfs(int cur, int s)
{
    int i, j, k, x, y, z, unx, uny, unz;
    if(cur == C)
    {
        if(s == 0 && num[a[A - 1]] != 0 && num[b[B - 1]] != 0 && num[c[C - 1]] != 0)
        {
            ++ cnt;
            if(cnt >= 2)
                return 1;
        }
        return 0;
    }
    z = 0;
    unx = 1;
    if(cur >= A)
    {
        x = 0;
        unx = 0;
    }
    else if(num[a[cur]] != -1)
    {
        x = num[a[cur]];
        unx = 0;
    }
    for(i = (unx ? 0 : 9); i < 10; i ++)
    {
        if(unx && hash[i])
            continue;
        if(unx)
        {
            hash[i] = 1;
            x = num[a[cur]] = i;
        }
        uny = 1;
        if(cur >= B)
        {
            y = 0;
            uny = 0;
        }
        else if(num[b[cur]] != -1)
        {
            y = num[b[cur]];
            uny = 0;
        }
        for(j = (uny ? 0 : 9); j < 10; j ++)
        {
            if(uny && hash[j])
                continue;
            if(uny)
            {
                hash[j] = 1;
                y = num[b[cur]] = j;
            }
            unz = 1;
            if(num[c[cur]] != -1)
                unz = 0;
            z = (x + y + s) % 10;
            k = (x + y + s) / 10;
            if(unz)
            {
                if(!hash[z])
                {
                    hash[z] = 1;
                    num[c[cur]] = z;
                    if(dfs(cur + 1, k))
                        return 1;
                    hash[z] = 0;
                    num[c[cur]] = -1;
                }
            }
            else
            {
                if(z == num[c[cur]])
                {
                    if(dfs(cur + 1, k))
                        return 1;
                }
            }
            if(uny)
            {
                hash[j] = 0;
                num[b[cur]] = -1;
            }
        }
        if(unx)
        {
            hash[i] = 0;
            num[a[cur]] = -1;
        }
    }
    return 0;
}
void solve()
{
    int i, j, k;
    if(A > C || B > C)
    {
        printf("impossible\n");
        return ;
    }
    memset(num, -1, sizeof(num));
    memset(hash, 0, sizeof(hash));
    cnt = 0;
    dfs(0, 0);
    if(cnt == 0)
        printf("impossible\n");
    else if(cnt == 1)
        printf("valid\n");
    else
        printf("ambiguous\n");
}
int main()
{
    v['I'] = 1, v['X'] = 10, v['C'] = 100, v['M'] = 1000;
    v['V'] = 5, v['L'] = 50, v['D'] = 500;
    for(;;)
    {
        gets(str);
        if(str[0] == '#')
            break;
        init();
        solve();
    }
    return 0;
}