#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 5
int has[13 * 4];
char s[5];
int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        memset(has,0,sizeof(has));
        for(int i = 0;i < 5;i++)
        {
            scanf("%s",s);
            int cur;
            if(strlen(s) == 3)
            {
                cur = (s[1] - '0') * 10 + s[2] - '0';
            }
            else
            {
                cur = s[1] - '0';
            }
            cur--;
            has[cur * 4 + s[0] - 'A']++;
        }
        int ans = 5;
        for(int i = 0;i < 10;i++)
        {
            for(int j = 0;j < 4;j++)
            {
                int cnt = 5;
                for(int k = 0;k < 5;k++)
                {
                    int num = (i + k) * 4 + j;
                    if(has[num % (13 * 4)])cnt--;
                }
                ans = min(ans,cnt);
            }
        }
        cout << ans << endl;
    }
}
