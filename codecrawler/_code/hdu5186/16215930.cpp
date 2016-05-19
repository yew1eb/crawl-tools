#include <bits/stdc++.h>

using namespace std;
int n, b, a[205];
char s[205];

int main()
{
    while(scanf("%d%d", &n, &b) != EOF)
    {
        memset(a, 0, sizeof(a));
        int MAX = 0;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            int len = strlen(s);
            MAX = max(MAX , len);
            reverse(s, s + len);
            for(int i=0; i<len; i++)
            {
                if(s[i] <= '9') a[i] += s[i] - '0';
                else a[i] += s[i] - 'a' + 10;
            }
        }
        for(int i=0; i<MAX; i++)  a[i] %= b;

        int flag = 1;

        for(int  i = MAX -1; i >= 0; i--)
        {
            if(!a[i] && flag && i)
            continue;
            else flag = 0;

            if(a[i] <= 9) putchar(a[i] + '0');
            else putchar(a[i] + 'a' -10);
        }

        cout<<endl;
    }
    return 0;
}
