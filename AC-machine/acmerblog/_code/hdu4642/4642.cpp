/* 鎵捐寰嬪彂鐜板彧璺熷彸涓嬭鐨勯偅涓‖甯佹湁鍏�
 *
 * */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <vector>
#define MID(x,y) ((x+y)>>1)
#define iabs(x) ((x)>0?(x):-(x))
using namespace std;
int main(){
	int t,n,m,a;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j){
				scanf("%d", &a);
			}
		if(a) printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}