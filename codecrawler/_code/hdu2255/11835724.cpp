/*
KMËã·¨
Ëã·¨²½Öè£º
Éè¶¥µãXiµÄ¶¥±êÎªa[i]£¬¶¥µãYiµÄ¶¥±êÎªb[i]
¢¡.³õÊ¼Ê±£¬a[i]ÎªÓëXiÏà¹ØÁªµÄ±ßµÄ×î´óÈ¨Öµ£¬b[j]=0£¬±£Ö¤a[i]+b[j]>=w(i,j)³ÉÁ¢
¢¢.µ±ÏàµÈ×ÓÍ¼ÖÐ²»°üº¬Íê±¸Æ¥ÅäÊ±£¬¾ÍÊÊµ±ÐÞ¸Ä¶¥±êÒÔÀ©´óÏàµÈ×ÓÍ¼£¬Ö±µ½ÕÒµ½Íê±¸Æ¥ÅäÎªÖ¹
¢£.ÐÞ¸Ä¶¥±êµÄ·½·¨
µ±´ÓXiÑ°ÕÒ½»´íÂ·Ê§°Üºó£¬µÃµ½Ò»¿Ã½»´íÊ÷£¬ËüµÄËùÓÐÒ¶×Ó½Úµã¶¼ÊÇX½Úµã£¬¶Ô½»´íÊ÷ÖÐX¶¥µãµÄ¶¥±ê¼õÉÙdÖµ£¬Y¶¥µãµÄ¶¥±êÔö¼ÓdÖµ£¬¶ÔÓÚÍ¼ÖÐËùÓÐµÄ±ß(i,j)£¬
¿ÉÒÔ¿´µ½£º
iºÍj¶¼²»ÔÚ½»´íÊ÷ÖÐ£¬±ß(i,j)ÈÔÈ»²»ÊôÓÚÏàµÈ×ÓÍ¼
iºÍj¶¼ÔÚ½»´íÊ÷ÖÐ£¬±ß(i,j)ÈÔÈ»ÊôÓÚÏàµÈ×ÓÍ¼
i²»ÔÚ½»´íÊ÷ÖÐ£¬jÔÚ½»´íÊ÷ÖÐ£¬a[i]+b[j]À©´ó£¬±ß(i,j)²»ÊôÓÚÏàµÈ×ÓÍ¼
iÔÚ½»´íÊ÷,j²»ÔÚ½»´íÊ÷ÖÐ,±ß(i,j)ÓÐ¿ÉÄÜ¼ÓÈëµ½ÏàµÈ×ÓÍ¼ÖÐ
ÎªÁËÊ¹a[i]+b[j]>=w(i,j)Ê¼ÖÕ³ÉÁ¢,ÇÒÖÁÉÙÓÐÒ»Ìõ±ß¼ÓÈëµ½ÏàµÈ×ÓÍ¼ÖÐ,d=min{a[i]+b[j]-w(i,j)},iÔÚ½»´íÊ÷ÖÐ,j²»ÔÚ½»´íÊ÷ÖÐ

Ê±¼ä¸´ÔÓ¶È:ÐèÒªÕÒO(n)´ÎÔö¹ãÂ·£¬Ã¿´ÎÔö¹ã×î¶àÐèÒªÐÞ¸ÄO(n)´Î¶¥±ê£¬Ã¿´ÎÐÞ¸Ä¶¥±êÊ±Ã¶¾Ù±ßÀ´ÇódÖµ£¬¸´ÔÓ¶ÈÎªO(n2),×ÜµÄ¸´ÔÓ¶ÈÎªO(n4).¼òµ¥ÓÅ»¯¿ÉÒÔ½µµÍµ½O(n3),Ã¿¸öY¶¥µãÒ»¸ö¡°ËÉ³ÚÁ¿¡±º¯Êýslack£¬Ã¿´Î¿ªÊ¼ÕÒÔö¹ãÂ·Ê±³õÊ¼»¯ÎªÎÞÇî´ó¡£ÔÚÑ°ÕÒÔö¹ãÂ·µÄ¹ý³ÌÖÐ£¬¼ì²é±ß(i,j)Ê±£¬Èç¹û²»ÔÚÏàµÈ×ÓÍ¼ÖÐ£¬ÔòÈÃslack[j]±ä³ÉÔ­ÖµÓëA[i]+B[j]-w[i,j]µÄ½ÏÐ¡Öµ¡£ÕâÑù£¬ÔÚÐÞ¸Ä¶¥±êÊ±£¬È¡ËùÓÐ²»ÔÚ½»´íÊ÷ÖÐµÄY¶¥µãµÄslackÖµÖÐµÄ×îÐ¡Öµ×÷ÎªdÖµ¼´¿É¡£
µ«»¹Òª×¢ÒâÒ»µã£ºÐÞ¸Ä¶¥±êºó£¬Òª°ÑËùÓÐµÄslackÖµ¶¼¼õÈ¥d¡£
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 310;
const int INF = 1e9;
int nx, ny;
int g[maxn][maxn];
int linker[maxn], lx[maxn], ly[maxn];//yÖÐ¸÷µãÆ¥Åä×´Ì¬,x,yÖÐµÄ¶¥±ê
int slack[maxn];
bool visx[maxn], visy[maxn];

bool DFS(int x){
    visx[x] = true;
    for(int y=0; y<ny; ++y){
        if(visy[y]) continue;
        int tmp = lx[x] + ly[y] - g[x][y];
        if(tmp == 0){
            visy[y] = true;
            if(linker[y] == -1 || DFS(linker[y])){
                linker[y] = x;
                return true;
            }
        }
        else if(slack[y]> tmp)
            slack[y] = tmp;
    }
    return false;
}

int KM(){
    memset(linker, -1, sizeof linker );
    memset(ly, 0, sizeof ly );
    for(int i=0; i<nx; ++i){
        lx[i] = - INF;
        for(int j=0; j<ny; ++j)
            if(g[i][j]> lx[i])
                lx[i] = g[i][j];
    }
    for(int x=0; x<nx; ++x){
        for(int i=0; i<ny; ++i)
            slack[i] = INF;
        while(true){
            memset(visx, false, sizeof visx );
            memset(visy, false, sizeof visy );
            if(DFS(x)) break;
            int d = INF;
            for(int i=0; i<ny; ++i)
                if(!visy[i] && d>slack[i])
                    d = slack[i];
            for(int i=0; i<nx; ++i)
                if(visx[i])
                    lx[i] -= d;
            for(int i=0; i<ny; ++i){
                if(visy[i]) ly[i] += d;
                else slack[i] -= d;
            }
        }
    }
    int res = 0;
    for(int i=0; i<ny; ++i)
        if(linker[i] != -1)
            res += g[linker[i]][i];
    return res;
}

//HDU 2255
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.cpp","r",stdin);
    freopen("out.cpp", "w", stdout);
#endif // ONLINE_JUDGE
    int n;
    while(~scanf("%d", &n))
    {
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                scanf("%d", &g[i][j]);
        nx = ny = n;
        printf("%d\n" ,KM());
    }
    return 0;
}
