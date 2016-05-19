/**
 * ID: ping128
 * LANG: C++
 */

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <math.h>
#include <algorithm>
#include <map>
#include <string.h>

using namespace std;

typedef long long LL;
typedef pair<double, double>PII;
typedef pair<PII, int>PII2;

double dis(double x1, double y1, double x2, double y2)
{
 double xx = x1 - x2;
 double yy = y1 - y2;
 return sqrt(xx * xx + yy * yy);
}

double cx, cy, di;

#define PI 3.141592654
void go()
{
 cx += 10.0 * cos((di / 180.0) * (PI));
 cy += 10.0 * sin((di / 180.0) * (PI));
}

map<int, vector<PII> >pos;

int in[4];
vector<int> turn;

bool cmp2(double a, double b)
{
 return a > b;
}

void search2(int at, int num_turn, int sss, double x, double y)
{
 if(at == sss)
 {
 pos[num_turn].push_back(PII(x, y));
 }
 else
 {
 if(at == 0)
 {
 num_turn = -turn[at];
 }
 else
 {
 num_turn += turn[at - 1] - turn[at];
 }
 
 for(int i = 1; num_turn + i <= 24; i++ )
 {
 x += 10.0 * cos(((double)turn[at] * 45.0 / 180.0) * (PI));
 y += 10.0 * sin(((double)turn[at] * 45.0 / 180.0) * (PI));
 search2(at + 1, num_turn + i, sss, x, y);
 }
 }
}

void cal()
{
 sort(turn.begin(), turn.end(), cmp2);
 // for(int i = 0; i < turn.size(); i++ ) printf("%d ", turn[i]);
 // printf("\n");
 search2(0, 0, turn.size(), 0.0, 0.0);
}

void search(int at)
{
 if(at == 4)
 {
 turn.clear();
 for(int i = 0; i < 4; i++ )
 {
 if(in[i] == 1)
 {
 turn.push_back(-i);
 }
 else if(in[i] == 2)
 {
 turn.push_back(-i - 4);
 }
 }
 cal();
 }
 else
 {
 for(int i = 0; i < 3; i++ )
 {
 in[at] = i;
 search(at + 1);
 }
 }
}

class Solve
{
 public:
 void main2()
 {
 search(0);
 }
};

int main()
{
 // freopen("j.in", "r", stdin);
 // freopen(".out", "w", stdout);

 Solve ___test;
 ___test.main2();
 
 int Test;
 scanf("%d", &Test);
 for(int t = 1; t <= Test; t++ )
 {
 double dx, dy;
 int n;
 cin >> n >> dx >> dy;
 double maxx = dis(0.0, 0.0, dx, dy);
 for(int k = 0; k <= n; k++ )
 {
 int ss = pos[k].size();
 for(int j = 0; j < ss; j++ )
 {
 maxx = min(maxx, dis(pos[k][j].first, pos[k][j].second, dx, dy));
 }
 }
 printf("%.6lf\n", maxx);
 }
//while(1);
return 0;
}