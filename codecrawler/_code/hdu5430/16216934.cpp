//#pragma comment(linker, "/STACK:102400000,102400000")
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <iostream>
using namespace std;
#define rd(x) scanf("%d",&x)
#define rd2(x,y) scanf("%d%d",&x,&y)
#define maxn 100005
#define pii pair<int,int>
#define maxn 100005
unsigned euler(unsigned x)
{// å°±æ¯å¬å¼
unsigned i, res=x;
for (i = 2; i < (int)sqrt(x * 1.0) + 1; i++)
if(x%i==0) {
res = res / i * (i - 1);
while (x % i == 0) x /= i; // ä¿è¯iä¸å®æ¯ç´ æ°
}
if (x > 1) res = res / x * (x - 1);
return res;
}
int main()
{
    int t,n;
    rd(t);
    while(t--){
        rd(n);
        printf("%d\n",euler(n+1));
    }
    return 0;
}
