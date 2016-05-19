//hdu 1045  Fire Net

//è¿é¢æææ¯ç»åºä¸å¼ å¾ï¼å¾ä¸­'X'è¡¨ç¤ºwall,'.'è¡¨ç¤ºç©ºå°,å¯ä»¥æ¾ç½®blockhouse
//åä¸æ¡ç´çº¿ä¸åªè½æä¸ä¸ªblockhouseï¼é¤éæwalléå¼ï¼é®å¨ç»åºçå¾ä¸­
//æå¤è½æ¾ç½®å¤å°ä¸ªblockhouse

//äºåå¹éï¼å«äººé½è¯´æ°´é¢ï¼ä½ææ²¡çåºå®æ¯äºåå¾å¹é
//çäºå«äººçè§£é¢æ¥ååè¿æç¹æµæµææç

//è¿é¢æ¯æåå§å¾åå«æè¡ååç¼©ç¹
//å»ºå¾ï¼æ¨ªç«ååºãåçæ¯ä¸åï¼åä¸åç¸è¿çç©ºå°åæ¶çæä¸ä¸ªç¹ï¼æ¾ç¶è¿
//æ ·çåºåä¸è½å¤åæ¶æ¾ä¸¤ä¸ªç¹ãè¿äºç¹ä½ä¸ºäºåå¾çXé¨ãåçå¨å¯¹ææç
//è¡ç¨ç¸åçæ¹æ³ç¼©ç¹ï¼ä½ä¸ºYé¨ã

//è¿è¾¹çæ¡ä»¶æ¯ä¸¤ä¸ªåºåæç¸äº¤é¨å(å³'.'çå°æ¹)ãæåæ±æå¤§å¹éå°±æ¯ç­æ¡ã


#include <stdio.h>
#include <string.h>

#define N 8

int cnt_row, cnt_col;
int row[N][N], col[N][N], r[N], c[N];
char map[N][N];
bool path[N][N], vis[N];

int dfs(int rr)
{
    for(int i = 0; i < cnt_col; ++i)
    {   //rrå°iæè·¯å¾ ä¸ iæ²¡éåè¿
        if(path[rr][i] && vis[i] == false)
        {
            vis[i] = true;
            if(c[i] == -1 || dfs(c[i]))//è¥ i è¿æ²¡å¹éè¿æ è·i
            {   //å¹éçç¹æ¾å°å¦ä¸ä¸ªç¸å¹éçç¹(åi å°±å¯ä»¥è·rrå¹é)
                c[i] = rr;
                r[rr] = i;
                return 1;
            }
        }
    }
    return 0;
}

int maxmatch()
{
    int ans = 0;
    memset(r, -1, sizeof(r));
    memset(c, -1, sizeof(c));
    for(int i = 0; i < cnt_row; ++i)
    {
        if(r[i] == -1)
        {
            memset(vis, false, sizeof(vis));
            ans += dfs(i);
        }
    }
    return ans;
}

int main()
{
    int n;
    while(scanf("%d%*c", &n), n)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
                map[i][j] = getchar();
            getchar();
        }

        memset(row, -1, sizeof(row));
        memset(col, -1, sizeof(col));
        cnt_row = cnt_col = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(map[i][j] == '.' && row[i][j] == -1)
                {           //æ¨ªåç¼©ç¹
                    for(int k = j; map[i][k] == '.' && k < n; ++k)
                        row[i][k] = cnt_row;  //ç»ç¸åçåºåæ è®°åä¸ä¸ªæ°å­
                    cnt_row++;
                }


                if(map[j][i] == '.' && col[j][i] == -1)
                {           //çºµåç¼©ç¹
                    for(int k = j; map[k][i] == '.' && k < n; ++k)
                        col[k][i] = cnt_col;  //ç»ç¸åçåºåæ è®°åä¸ä¸ªæ°å­
                    cnt_col++;
                }
            }
        }

        memset(path, false, sizeof(path));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(map[i][j] == '.')    //è¿è¾¹,'.'çå°æ¹å³ä¸ºç¼©ç¹åç è¡ååçäº¤ç¹
                    path[ row[i][j] ][ col[i][j] ] = true;

        printf("%d\n", maxmatch());  //äºåå¾å¹é
    }
    return 0;
}