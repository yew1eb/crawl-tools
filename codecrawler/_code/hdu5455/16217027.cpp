#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

const int MAXN = 1000000 + 1000;
char s[MAXN];
int posC[MAXN];

int main()
{
    int casen;
    cin >> casen;
    getchar();
    for (int cas = 1; cas <= casen; cas++)
    {
        cin.getline(s, MAXN);
        int len = strlen(s);
        int ans = 0;
        int j = 0;
        int ok = 1;
        for (int i = 0; i < len; i++)
        {
            if (s[i] != 'c'&&s[i] != 'f')
            {
                ok = 0;
                break;
            }
            if (s[i] == 'c')
            {
                posC[j] = i;
                j++;
            }
        }
        if (j == 0)
        {
            ans = (len + 1) / 2;
        }
        else
        {
            ans = j;
            for (int i = 0; i < j - 1; i++)
            {
                int dis = posC[i + 1] - posC[i];
                if (dis <= 2)
                    ok = 0;
            }
            int dis = len - (posC[j - 1] - posC[0]);
            if (dis <= 2)
                ok = 0;
        }

        if (!ok) ans = -1;
        printf("Case #%d: %d\n", cas, ans);
    }
}