#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
#define FF(i, n) for(int i = 0; i < n; i++)
#define M 85
#define inf 0x3fffffff

int n;

struct mat{
 int x[M][M];
 friend bool operator == (const mat &a, const mat &b)
 {
 FF(i, n) FF(j, n)
 if (a.x[i][j] != b.x[i][j])
 return false;
 return true;
 }
}p[M];

mat matmul(const mat &a, const mat &b)
{
 mat tp;
 FF(i, n) FF(j, n) tp.x[i][j] = 0;
 FF(i, n) FF(k, n) if(a.x[i][k]) FF(j, n) if(b.x[k][j])
 tp.x[i][j] += a.x[i][k]*b.x[j][k];
 return tp;
}

int dis[M][M], m;

void floyd()
{
 FF(i, m) FF(j, m) dis[i][j] = inf;
 FF(i, m) FF(j, m) if (i != j)
 {
 mat o = matmul(p[i], p[j]);
 FF(k, m) if (i != k && k != j && o == p[k]) dis[i][k] = 1;
 }
 FF(k, m) FF(i, m) FF(j, m)
 {
 if (dis[i][k] == inf || dis[k][j] == inf) continue;
 int tp = dis[i][k] + dis[k][j];
 if (tp < dis[i][j]) dis[i][j] = tp;
 }
}

int main()
{
 int t, x, y;
 while (scanf("%d%d", &m, &n), (m||n))
 {
 FF(i, m) FF(j, n) FF(k, n) scanf("%d", &p[i].x[j][k]);
 floyd();
 scanf("%d", &t);
 while (t--)
 {
 scanf ("%d%d", &x, &y);
 --x; --y;
 if (dis[x][y] == inf) puts("Sorry");
 else printf("%d\n", dis[x][y]);
 }
 }
 return 0;
}