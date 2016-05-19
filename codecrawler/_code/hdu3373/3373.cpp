#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define INF 1000000001

using namespace std;

int n, d[100010];

typedef struct myNode
{
 int x, y, id;
}Node;
Node a[100010];
bool cmpx(const Node aa, const Node b)
{
 return aa.x < b.x;
}
inline int abs(int x)
{
 return x < 0 ? -x : x;
}
inline int max(int a, int b)
{
 return a > b ? a : b;
}
int main()
{
 int tmp;
 while(scanf("%d",&n) != EOF)
 {
 for(int i = 0; i < n; ++i)
 {
 d[i] = INF, a[i].id = i;
 }
 for(int i = 0; i < n; ++i)
 scanf("%d%d",&a[i].x,&a[i].y);
 sort(a,a+n,cmpx);

 for(int i = 0; i < n; ++i)
 {
 for(int j = i-1; j >= 0; --j)
 {
 tmp = abs(a[i].x-a[j].x);
 if(tmp >= d[i]) break;
 tmp = max(tmp,abs(a[i].y-a[j].y));
 if(tmp < d[i]) d[i] = tmp;
 }
 for(int j = i+1; j < n; ++j)
 {
 tmp = abs(a[i].x-a[j].x);
 if(tmp >= d[i]) break;
 tmp = max(tmp,abs(a[i].y-a[j].y));
 if(tmp < d[i]) d[i] = tmp;
 }
 }
 long long res(0);
 for(int i = 0; i < n; ++i)
 res += d[i];
 printf("%I64d\n",res);
 }
 return 0;
}