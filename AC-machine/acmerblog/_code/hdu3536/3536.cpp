#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int r, c, m;
int mark[953][957];
bool f[1000];

int main()
{
 while(~scanf("%d%d%d", &r, &c, &m))
 {
 int minx = 2000, miny = 2000, maxx = 0, maxy = 0;
 memset(mark, 0, sizeof(mark));
 memset(f, 0, sizeof(f));
 for(int i = 1; i <= m; i++)
 {
 int x1, x2, y1, y2;
 scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
 minx = x1 < minx ? x1 : minx;
 minx = x2 < minx ? x2 : minx;
 maxx = x1 > maxx ? x1 : maxx;
 maxx = x2 > maxx ? x2 : maxx;
 miny = y1 < miny ? y1 : miny;
 miny = y2 < miny ? y2 : miny;
 maxy = y1 > maxy ? y1 : maxy;
 maxy = y2 > maxy ? y2 : maxy;
 for(int x = x1; x <= x2; x++)
 for(int y = y1; y <= y2; y++)
 mark[x][y] = i;
 }
 int ans = 0;
 for(int x = minx; x <= maxx; x++)
 for(int y = miny; y <= maxy; ++y)
 if(!f[mark[x][y]]) f[mark[x][y]] = true;
 for(int i = 1; i <= m; ++i)
 if(f[i]) ans++;
 printf("%d\n", m - ans);
 }
 return 0;
}