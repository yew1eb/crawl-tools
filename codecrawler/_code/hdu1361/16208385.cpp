#include <stdio.h>
#include <string.h>
char origin[30];
int p_seq[30], w_seq[30];
int t = 0, n = 0;
int main()
{
    while (scanf("%d", &t) != EOF&&t > 0)
    {
        while (t--)
        {
            scanf("%d", &n);
            int ori_len = 0;
            for (int i = 0; i <= n - 1; i++)        scanf("%d", &p_seq[i]);
            for (int i = 0; i <= n - 1; i++)
            {
                int left = i > 0 ? p_seq[i] - p_seq[i - 1] : p_seq[i];
                for (int j = 1; j <= left; j++)        origin[ori_len++] = '(';
                int right = 1;
                for (int j = 1; j <= right; j++)    origin[ori_len++] = ')';
                int match = 0,match_left = 0;//match the ')' and '('
                for (int j = ori_len - 1; j >= 0; j--)
                {
                    if (origin[j] == ')') { match++;}
                    else { match--; match_left++; }
                    if (!match) break;
                }
                w_seq[i] = match_left;
            }
            printf("%d",w_seq[0]);
            for (int i = 1; i <= n - 1; i++)     printf(" %d", w_seq[i]);
            printf("\n");
        }
    }
    return(0);
}