/*
Pro: 0

Sol:

date:
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int t,m;
double f,sum,tmp;
int main(){
    scanf("%d",&t);
    for(int ca = 1; ca <= t; ca ++){
        scanf("%d",&m);
        sum = 0;
        m --; scanf("%lf",&f); sum += f;
        while(m --) scanf("%lf",&tmp), sum += tmp;//这里啊。。。。
        printf("Case %d: %.6f\n",ca,f / sum);
    }
	return 0;
}
