#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 30;

int R, C;
int num[maxn][maxn];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char DIR[] = "DURL";
int rec[1000];
int ansx, ansy;
bool flag;
int all;        //æ ¼å­æ»æ°

bool judge(int x, int y)
{
    if (x < 0 || y < 0 || x >= R || y >= C) return false;
    return true;
}

void dfs(int x, int y, int ansnum)
{
    if (all == ansnum)
    {
        flag = true;
        return ;
    }
    if (flag) return ;

    int i, j;
    for (i=0; i<4 && !flag; i++)
    {
        if (num[x+dir[i][0]][y+dir[i][1]]) continue;    //å¦ææ­¤æ¹åç´§æ¨çæ ¼å­ï¼å°±continueããpsï¼è¿ä¹ä¸ªå°éè¯¯ï¼å¡äºæå¥½å ä¸ªå°æ¶ãããT Tããã
        for (j=1; !flag; j++)
        {
            int x3 = x + (j+2) * dir[i][0], y3 = y + (j+2) * dir[i][1];
            if (!judge(x3, y3)) break;
            int x1 = x + j * dir[i][0], y1 = y + j * dir[i][1];
            int x2 = x + (j+1) * dir[i][0], y2 = y + (j+1) * dir[i][1];
            if (num[x2][y2] > 0 && num[x1][y1] == 0)
            {
                rec[ansnum] = i;
                int old = num[x2][y2];
                num[x3][y3] += (old - 1);
                num[x2][y2] = 0;

                dfs(x2, y2, ansnum+1);

                num[x2][y2] = old;
                num[x3][y3] -= (old - 1);
                break;
            }
        }
    }
}

int main()
{
    while (scanf("%d %d", &C, &R) != EOF)
    {
        int i, j;
        getchar();
        all = 0;
        for (i=0; i<R; i++)
        {
            for (j=0; j<C; j++)
            {
                char c = getchar();
                if (c >= 'a' && c <= 'z')
                {
                    num[i][j] = c - 'a' + 1;
                    all += num[i][j];
                }
                else
                    num[i][j] = 0;
            }
            getchar();
        }
        flag = false;
        for (i=0; i<R && !flag; i++)
        {
            for (j=0; j<C && !flag; j++)
            {
                if (num[i][j] == 0)
                {
                    for (int k = 0; k<4 && !flag; k++)
                    {
                        int x1 = i + dir[k][0], y1 = j + dir[k][1];
                        int x2 = i + 2 * dir[k][0], y2 = j + 2 * dir[k][1];
                        int x3 = i + 3 * dir[k][0], y3 = j + 3 * dir[k][1];
                        if (!judge(x3, y3)) continue;
                        if (num[x2][y2] > 0 && num[x1][y1] == 0)
                        {
                            memset(rec, -1, sizeof(rec));
                            rec[0] = k;
                            int old = num[x2][y2];
                            num[x3][y3] += (old - 1);
                            num[x2][y2] = 0;

                            dfs(x2, y2, 1);

                            if (flag)
                            {
                                ansx = i;
                                ansy = j;
                            }

                            num[x2][y2] = old;
                            num[x3][y3] -= (old - 1);
                        }
                    }
                }
            }
        }
        printf("%d\n%d\n", ansx, ansy);
        for (i=0; i<all; i++)
            printf("%c", DIR[rec[i]]);
        puts("");
    }
    return 0;
}
