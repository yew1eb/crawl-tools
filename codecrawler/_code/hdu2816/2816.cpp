#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
char num[9][4] = {{' ', ' ', ' ', ' '}, {'A', 'B', 'C', ' '},{'D', 'E', 'F', ' '},{'G', 'H', 'I', ' '},{'J', 'K', 'L', ' '},{'M', 'N', 'O',' '},{'P', 'Q', ' R', 'S'},{'T', 'U', 'V', ' '},{'W', 'X', 'Y', 'Z'}};
string a = "QWERTYUIOPASDFGHJKLZXCVBNM";
string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char fun(char c)
{
    for(int i = 0; i < 52; ++i)
        if(a[i] == c)
            return b[i];
}

int main()
{
    char p[1010];
    string s, t, qian, hou, res;
    bool flag;
    int len, t1;
    while(~scanf("%s", p))
    {
        len = strlen(p);
        flag = true;
        s.clear(); t.clear(); qian.clear(); hou.clear(); res.clear();
        for(int i = 0; i < len; i += 2)
            s += num[(p[i] - '0') - 1][(p[i + 1] - '0') - 1];
        len = s.length();
        t1 = len;
        for(int i = 0; i < len; ++i)
            t += fun(s[i]);
        qian = t.substr(0, (len + 1) / 2);
        hou = t.substr((len + 1) / 2);
        len = qian.length();
        int len1 = hou.length();
        for(int i = 0, j = 0; i < len && j < len1; ++i, ++j)
        {
            res += qian[i];
            res += hou[j];
        }
        if(t1 % 2)
            res += qian[len - 1];
        for(int i = len + len1 - 1; i >= 0; --i)
            cout<<res[i];
        cout<<endl;
    }
    return 0;
}