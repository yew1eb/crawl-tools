#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#define N 500005
typedef long long LL;
using namespace std;
int n ;
LL X[N] , Y[N] , Z[N];
char str[55];

LL cal(LL k)
{
  LL sum = 0 , x;
  for (int i = 1 ; i <= n; ++ i)
  {
    if (k < X[i]) continue;
    x = min(k , Y[i]);
    sum += (x - X[i]) / Z[i] + 1;
  }
  return sum;
}

void work()
{
  n = 1;
  X[n] = 0;
  sscanf(str , "%I64d %I64d %I64d" , &X[n] , &Y[n] , &Z[n]);
  if (!X[n]) return;
  memset(str , 0 , sizeof(str));
  while (gets(str) , *str)
    ++ n , sscanf(str , "%I64d %I64d %I64d" , &X[n] , &Y[n] , &Z[n]) , memset(str , 0 , sizeof(str));
  LL l = 1 , r = 1LL << 33 , m;
  while (l < r)
  {
    m = (l + r) >> 1;
    if (cal(m) & 1)
      r = m;
    else l = m + 1;
  }
  if (l == 1LL << 33)
    puts("no corruption");
  else printf("%I64d %I64d\n" , l , (cal(l) - cal(l - 1)));
}

int main()
{
  while(gets(str))
    work();
  return 0;
}