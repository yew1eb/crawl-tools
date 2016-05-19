//author: CHC
//First Edit Time:    2015-09-05 19:38
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <limits>
using namespace std;
typedef long long LL;
const int INF = numeric_limits<int>::max();
const LL LL_INF= numeric_limits<LL>::max();

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(__gcd(i,n+1)==1)++cnt;
        }
        printf("%d\n",cnt);
    }
    return 0;
}