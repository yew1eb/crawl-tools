#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char str1[205], str2[205];
int s1[205], s2[205], s[205];
int main()
{
    int len1, len2, len, i, j, flag;
    while (cin >> str1 >>str2)
    {
        flag = 0;
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        memset(s, 0, sizeof(s));
        len1 = strlen(str1); len2 = strlen(str2);
        for (i = 0; i < len1; i++)
            s1[len1 - i - 1] = str1[i] - 65;
        for (i = 0; i < len2; i++)
            s2[len2 - i - 1] = str2[i] - 65;
        len = max(len1, len2);
        for (i = 0; i <= len; i++)
        {
            s[i] = flag + s1[i] + s2[i];
            if (s[i]>25)
            {
                flag = 1;
                s[i] -= 26;
            }
            else flag = 0;
        }
        flag = 0;
        for (j = i; j >= 0; j--)
        {
            if(flag)
                printf("%c", s[j] + 65);
            if (flag == 0 && s[j] != 0)
            {
                  flag = 1;
                  printf("%c", s[j] + 65);
            }
        }
        printf("\n");
    }
    return 0;
}