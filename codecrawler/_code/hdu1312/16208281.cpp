#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int direct[4][2] = { -1, 0, 1, 0, 0, 1, 0, -1 };  /*å®ä¹æ¹åï¼ å·¦å³ï¼ä¸ä¸*/

char map[21][21];               /*è¾å¥çå­ç¬¦ä¸²*/
bool mark[21][21];              /*æ è®°èµ°è¿çè·¯ç¨*/
bool flag;
int W, H;
int Dx, Dy;            //è®°å½èµ·å§ä½ç½®@ï¼ä»è¿éå¼å§è¿è¡æç´¢
int ans;                //è®°å½æ»¡è¶³çä¸ªæ°ãåå§åä¸º1ï¼å ä¸º@ä¹åå«å¨å
/*****åºä¸æ¯æ ¸å¿ç®æ³ï¼ä¸»è¦æ¯ä»
ä¸ä¸å·¦å³è¿åä¸ªæ¹åè¿è¡æç´¢ï¼æ³¨æ
æ»¡è¶³æç´¢çæ¡ä»¶æ¯ä¸è½è¶çï¼ä¸è½æ¯#ï¼
è¿æå°±æ¯æ²¡ææç´¢è¿ç--ãä¸»è¦æ¯é mark[i][j]
æ¥å®ç°*******/
void DFS( int x, int y )
{
    mark[x][y] = true;
    for( int k = 0; k < 4; k ++ )
    {
        int p = x + direct[k][0];
        int q = y + direct[k][1];
        if( p >= 0 && q >= 0 && p < H && q < W && !mark[p][q] && map[p][q] != '#' )
        {
            ans ++;
            DFS( p, q );
        }
    }
    return;
}

int main()
{
    int i, j, k;
    while( cin >> W >> H && ( W || H ) )   // W -> column, H -> row;
    {
        memset( mark, false, sizeof( mark ) );
        for( i = 0; i < H; i ++ )
            for( j = 0; j < W; j ++ )
            {
                cin >> map[i][j];
                if( map[i][j] == '@' )
                {
                    Dx = i;
                    Dy = j;
                }
            }
        ans = 1;
        DFS( Dx, Dy );
        cout << ans << endl;
    }
}
