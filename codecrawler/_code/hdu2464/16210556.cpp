#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <time.h>
#include <cstdio>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define LL long long
#define MIN INT_MIN
#define MAX INT_MAX
#define PI acos(-1.0)
#define FRE freopen("input.txt","r",stdin)
#define FF freopen("output.txt","w",stdout)
#define N 100005
int min(int a,int b){return a>b?b:a;}
int a[8];
int ga[8][8];
int gb[8][8];
int main () {
    int n , ma, mb;
    int ca = 1;
    while (scanf("%d%d%d",&n,&ma,&mb) && (n + ma+ mb)) {
        int ia,ib,da,db;int i,j;
        memset(ga,0,sizeof(ga));
        memset(gb,0,sizeof(gb));
        for (i = 0; i < n; i++) {
            a[i] = i;
        }
        scanf("%d%d%d%d",&ia,&ib,&da,&db);
        i = ma;
        while (i--) {
            int x,y;
            scanf("%d%d",&x,&y);
            ga[x][y] = ga[y][x] = 1;
        }
        i = mb;
        while (i--) {
            int x,y;
            scanf("%d%d",&x,&y);
            gb[x][y] = gb[y][x] = 1;
        }
        int ans = MAX;
        do {
            int minm = 0;
            for (i = 0; i < n; i++) {
                for (j = i+1; j < n; j++) {
                    if (ga[i][j] != gb[a[i]][a[j]]) {
                        if (ga[i][j]) {
                            minm += min(da,ib);
                        } else {
                            minm += min(db,ia);
                        }
                    }
                }
            }
            ans = min(ans,minm);
        } while (next_permutation(a,a+n));
        printf("Case #%d: %d\n",ca++,ans);
    }
    return 0;
}
