/*
ÌâÒâ£º
   ¸ø³öÈý¶ÑÊ¯×Ó(m,n,p¸ö)£¬Á½ÈËÃ¿´ÎÖ»ÄÜÈ¡ì³²¨ÄÇÆõÊýf[i]¸ö£¬×îÏÈÈ¡¹âËùÓÐÊ¯×ÓÕßÈ¡Ê¤¡£

Ìâ½â£º
SGº¯Êý½â×éºÏÓÎÏ·
SG¶¨Àí£º  ÓÎÏ·¡°ºÍ¡±µÄSGº¯ÊýµÈÓÚ¸÷×ÓÓÎÏ·SGº¯ÊýµÄNimºÍ¡£
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1100;
int f[20];
int SG[maxn];
bool vis[maxn];

int mex(int n) //minimal excludant
{
    if(SG[n]!=-1) return SG[n];
    int i, t;
    for(i=0; i<=15; ++i)
    {
        t = n - f[i];
        if(t<0) break;
        if(SG[t]==-1)
            SG[t] = mex(t);
        vis[SG[t]] = true;
    }

    for(i=0; vis[i]; ++i);
    return SG[n] = i;
}
void init()
{
    f[0] = f[1] = 1;
    for(int i=2; i<=15; ++i) //f[16]>1000
        f[i] = f[i-1] + f[i-2];

    memset(SG, -1, sizeof SG );
    for(int i=1; i<=1000; ++i)
    {
        memset(vis, 0, sizeof vis );
        mex(i);
    }
}
int main()
{
    int m, n, p;
    init();
    while(~scanf("%d%d%d", &m, &n, &p))
    {
        if(m==0&&n==0&&p==0) break;
        if( (SG[m]^SG[n]^SG[p]) == 0) printf("Nacci\n");
        else printf("Fibo\n");
    }
    return 0;
}
