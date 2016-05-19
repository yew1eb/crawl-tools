#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define REP(i, n) for(int i=0; i<n; i++)
#define FF(i, a, b) for(int i=a; i<b; i++)
#define FD(i, a, b) for(int i=a; i>=b; i--)
#define CLR(a, b) memset(a, b, sizeof(a))
#define PB push_back
#define LL long long
using namespace std;

const int N = 1000;
char ch[N], c;
vector<string> ans;
char stop[10] = "</html>";

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, cas = 1;
    scanf("%d", &t);
    while(t --)
    {
        int cnt = 0;
        ans.clear();
        c = getchar();
        while(true)
        {
            while(c == ' ' || c == '\n' || c == '\t') c = getchar();
            if(c == '<')
            {
                ch[cnt ++] = '<';
                while(c != '>')
                {
                    c = getchar();
                    ch[cnt ++] = c;
                }
                ch[cnt] = '\0';
                ans.push_back(ch);
                cnt = 0;
                if(!strcmp(ch, stop))
                {
                    break;
                }
                c = getchar();
            }
            else
            {
                while(c != ' ' && c != '\n' && c != '<' && c != '\t')
                {
                    ch[cnt ++] = c;
                    c = getchar();
                }
                ch[cnt] = '\0';
                cnt = 0;
                ans.push_back(ch);
            }
        }
        cnt = 0;
        bool flag = false;
        printf("Case #%d:\n", cas ++);
        REP(i, ans.size())
        {
            if(ans[i][0] == '<')
            {
                flag = false;
                if(ans[i][1] != '/')
                {

                    REP(j, cnt) putchar(' ');
                    cout << ans[i] << endl;
                    int len = ans[i].size();
                    if(ans[i][len - 2] != '/') cnt ++;
                    else continue;
                    ch[0] = '<';
                    ch[1] = '/';
                    FF(j, 1, len)
                    {
                        if(ans[i][j] == ' ')
                        {
                            ch[j + 1] = '>';
                            ch[j + 2] = '\0';
                            break;
                        }
                        ch[j + 1] = ans[i][j];
                    }
                    ch[len + 1] = '\0';
                }
                else
                {
                    cnt --;
                    REP(j, cnt) putchar(' ');
                    cout << ans[i] << endl;
                }
            }
            else
            {
                if(!flag)
                {
                    REP(j, cnt) putchar(' ');
                    cout << ans[i];
                    flag = true;
                }
                else cout << " " << ans[i];
                if(ans[i + 1][0] == '<') puts("");
            }
        }
    }
}
