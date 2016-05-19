    #include <iostream>
    #include <string.h>
    #include <cstdio>

    using namespace std;

    const int MAXN = 60;
    int n;
    char temp[MAXN][2];
    char flag[2];
    int c[MAXN][MAXN];

    int match[MAXN];
    bool vis[MAXN];

    int change(char ch)
    {
        if (ch == 'A')
        {
            return 14;
        }
        else if (ch == 'J')
        {
            return 11;
        }
        else if (ch == 'Q')
        {
            return 12;
        }
        else if (ch == 'K')
        {
            return 13;
        }
        else if (ch == 'T')
        {
            return 10;
        }
        else
        {
            return ch - '0';
        }
    }

    bool dfs(int u)
    {
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && c[u][i])
            {
                vis[i] = true;

                if (match[i] == -1 || dfs(match[i]))
                {
                    match[i] = u;
                    return true;
                }
            }
        }

        return false;
    }

    void solve()
    {
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            memset(vis, false, sizeof(vis));
            ans += dfs(i);
        }

        cout << ans << endl;
    }

    void input()
    {
        int t;

        cin >> t;

        while (t--)
        {
            cin >> n;

            for (int i = 0; i < n; i++)
            {
                scanf("%s", temp[i]);
            }

            memset(c, 0, sizeof(c));
            memset(match, -1, sizeof(match));

            for (int i = 0; i < n; i++)
            {
                scanf("%s", flag);

                for (int j = 0; j < n; j++)
                {
                    if (change(flag[0]) > change(temp[j][0]))
                    {
                        c[i][j] = 1;
                    }
                    else if (change(flag[0]) == change(temp[j][0]))
                    {
                        if (flag[1] == 'H')
                        {
                            c[i][j] = 1;
                        }
                        else if (flag[1] == 'S' && temp[j][1] != 'H')
                        {
                            c[i][j] = 1;
                        }
                        else if (flag[1] == 'D' && temp[j][1] == 'C')
                        {
                            c[i][j] = 1;
                        }
                    }
                }
            }

            solve();
        }
    }

    int main()
    {
        input();
        return 0;
    }
