/*
 * Author: NomadThanatos
 * Created Time: 2011/3/10 18:47:54
 * File Name: E.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
#define SZ(v) ((int)(v).size())

const int MAXINT = -1u>>1;
const int MAXN = 1000 + 50;
const double EPS = 1e-9;

int N;
bool can;
bool vis[MAXN];
double nw,ne;
double x[MAXN],y[MAXN],r[MAXN];

int sgn(const double &x) {return (int)((x > EPS) - (x < -EPS));}

void dfs(const int &i) {
 vis[i] = true;
 for(int j = 0 ; j < N ; j++) {
 if (sgn(sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) - r[i] - r[j]) <= 0 && !vis[j]) dfs(j);
 }
 if (sgn(y[i] - r[i]) <= 0) can = false;
 if (sgn(x[i] - r[i]) <= 0) {
 nw = min(nw,y[i] - sqrt(r[i] * r[i] - x[i] * x[i]));
 }
 if (sgn(x[i] + r[i] - 1000) >= 0) {
 ne = min(ne,y[i] - sqrt(r[i] * r[i] - (1000.0 - x[i]) * (1000.0 - x[i])));
 }
}

int main() {
 while(scanf("%d",&N) == 1 && N) {
 ne = nw = 1000.0;
 for(int i = 0 ; i < N ; i++) {
 scanf("%lf%lf%lf",x + i,y + i,r + i);
 vis[i] = false;
 }
 can = true;
 for(int i = 0 ; i < N ; i++) {
 if (!vis[i] && sgn(y[i] + r[i] - 1000.0) >= 0) {
 dfs(i);
 }
 }
 if (can) {
 printf("0.00 %0.2lf 1000.00 %0.2lf\n",nw,ne);
 }
 else printf("IMPOSSIBLE\n");
 }
 return 0;
}