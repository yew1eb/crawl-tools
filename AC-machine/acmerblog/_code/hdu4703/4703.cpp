#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int  MAX_  = 101;
typedef long long LL;

struct line {
    int x[2],y[2];
} hor[MAX_], ver[MAX_];

int ans;


int main() {
    int Case, n, h,v, tmp, maxh,minh, maxv,minv;
    int x1,y1,x2,y2;
    scanf("%d",&Case);
    while(Case--) {
        scanf("%d",&n);
        ans = 0;
        h = v =  0;
        for(int i = 0; i < n; i++) {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(y1 == y2) {
                hor[h].x[0] = min(x1,x2);
                hor[h].y[0] = y1;
                hor[h].x[1] = max(x1,x2);
                hor[h++].y[1] = y2;
            } else {
                ver[v].x[0] = x1;
                ver[v].y[0] = min(y1,y2);
                ver[v].x[1] = x2;
                ver[v++].y[1] = max(y1,y2);
            }
        }
        for(int i = 0; i < h - 1; i++) {
            for(int j = i+1; j < h; j++) {
                if(hor[i].x[1] < hor[j].x[0] || hor[i].y[0] == hor[j].y[0]) {
                    continue;
                }
                maxh = min(hor[i].x[1], hor[j].x[1]);
                minh = max(hor[i].x[0], hor[j].x[0]);
                maxv = max(hor[i].y[0], hor[j].y[0]);
                minv = min(hor[i].y[0], hor[j].y[0]);
                tmp = 0;
                for(int k = 0; k < v; k++) {
                    if(ver[k].x[0] >= minh && ver[k].x[0] <= maxh && ver[k].y[0] <= minv && ver[k].y[1] >= maxv){
                        tmp++;
                    }
                }
                ans += (tmp - 1) * tmp /2;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
