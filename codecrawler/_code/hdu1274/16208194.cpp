#include <stdio.h>
#include <string.h>

char input[250005];
char str[250005];
int main()
{
    int cas;
    scanf("%d",&cas);
    while (cas--)
    {
        scanf("%s", input);
        int len;
        while (1)
        {
            int flag = 0;
            int c = 0;
            int i, j, k;
            len = strlen(input);
            for (i = 0; i < len; i++)
            {
                if (input[i] >= 'a' && input[i] <= 'z')
                {
                    str[c++] = input[i];
                }
                else if (input[i] >= '0' && input[i] <= '9')
                {
                    int cnt = 0;
                    while (input[i] >= '0' && input[i] <= '9')
                    {
                        cnt *= 10;
                        cnt += input[i] - '0';
                        i++;
                    }
                    if (input[i] != '(')
                    {
                        while (cnt--)
                        {
                            str[c++] = input[i];
                        }
                    }
                    else
                    {
                        int t = 1;
                        int temp = i + 1;
                        while (t != 0)
                        {
                            if (input[temp] == '(')
                            {
                                ++t;
                            }
                            if (input[temp] == ')')
                            {
                                --t;
                            }
                            ++temp;
                        }
                        for (j = 0; j < cnt; ++j)
                        {
                            for (k = i + 1; k < temp - 1; ++k)
                            {
                                str[c++] = input[k];
                                if (input[k] == '(' || input[k] == ')' || (input[k] >= '0' && input[k] <= '9'))
                                {
                                    flag = 1;
                                }
                            }
                        }
                        i = temp - 1;
                    }
                }
            }
            str[c] = 0;
            strcpy(input, str);
            if (flag == 0)
            {
                break;
            }
        }
        puts(str);
    }
    return 0;
}
