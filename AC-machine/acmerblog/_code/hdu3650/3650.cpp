#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int n, i, now, ans, j, s[24 * 3605], a, b;
int main(){
 while (scanf("%d", &n) == 1 && n){
 memset(s, 0, sizeof(s));
 for (i = 1; i <= n; i++){
 scanf("%d%d", &a, &b);
 s[a]++; s[b + 1]--;
 }
 now = ans = 0;
 for (i = 0; i < 24 * 3600; i++){
 now += s[i];
 ans = max(ans, now);
 }
 printf("%d\n", ans);
 }

}