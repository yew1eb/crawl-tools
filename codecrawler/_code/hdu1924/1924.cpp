#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int N = 5010;//这儿必须是大于5000，要不然就Runtime error
char str[N][25];
int Judge(char c)
{
    if (c == 'I')
    {
        return 1;
    }
    else if (c == 'V')
    {
        return 5;
    }
    else if (c == 'X')
    {
        return 10;
    }
    else if (c == 'L')
    {
        return 50;
    }
    else if (c == 'C')
    {
        return 100;
    }
    else if (c == 'D')
    {
        return 500;
    }
    else if (c == 'M')
    {
        return 1000;
    }
    return 0;
}
void Print(int ans)//输出函数
{
    while (ans)
    {
        if (ans >= 1000)
        {
            printf("M");
            ans -= 1000;
        }
        else if (ans >= 900)//特殊
        {
            printf("CM");
            ans -= 900;
        }
        else if (ans >= 500)
        {
            printf("D");
            ans -= 500;
        }
        else if (ans >= 400)
        {
            printf("CD");
            ans -= 400;
        }
        else if (ans >= 100)
        {
            printf("C");
            ans -= 100;
        }
        else if (ans >= 90)
        {
            printf("XC");
            ans -= 90;
        }
        else if (ans >= 50)
        {
            printf("L");
            ans -= 50;
        }
        else if (ans >= 40)
        {
            printf("XL");
            ans -= 40;
        }
        else if (ans >= 10)
        {
            printf("X");
            ans -= 10;
        }
        else if (ans==9)
        {
            printf("IX");
            ans -= 9;
        }
        else if (ans >= 5 && ans < 9)
        {
            printf("V");
            ans -= 5;
        }
        else if (ans == 4)
        {
            printf("IV");
            ans -= 4;
        }
        else if (ans >= 1 && ans < 4)
        {
            printf("I");
            ans -= 1;
        }
    }
}
int main()
{
    int n, i, ans, j, count = 1;
    while (scanf("%d", &n) != EOF && n)
    {
        memset(str, 0, sizeof(str));
        for (i = 0; i < n; ++i)
        {
            scanf("%s", str[i]);
        }
        ans = 0;
        for(i = 0; i < n; ++i)
        {
            int len = strlen(str[i]);
            for (j = 0; j < len; ++j)
            {
                //只要前面的比后面的小，例如IV表示的是4，应该V- I
                if (Judge(str[i][j]) < Judge(str[i][j + 1]) && j < len - 1 && (str[i][j] == 'I' || str[i][j] == 'X' || str[i][j] == 'C'))
                {
                    ans -= Judge(str[i][j]);
                }
                else
                {
                    ans += Judge(str[i][j]);
                }
            }
        }
        printf("Case ");
        Print(count);
        count ++;
        printf(": ");
        Print(ans);
        printf("\n");
    }
    return 0;
}