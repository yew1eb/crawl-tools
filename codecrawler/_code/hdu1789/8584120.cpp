#include <cstdio>
#include <algorithm>
#include <queue>
#define N 1000 + 5
using namespace std;
struct node {
    int x, y;
    bool operator < (const node & t) const {
        return (x<t.x)||(x==t.x&&y>t.y);
    }
} f[N];
struct tt {
    int time, y;
    bool operator < (const tt &a) const {
        return (y>a.y)||(y==a.y&&time>a.time);
    }
};
int main() {
    int T, i, j, n, ans ,time;
    tt tmp ;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(i=0; i<n; i++) scanf("%d",&f[i].x);
        for(i=0; i<n; i++) scanf("%d",&f[i].y);
        sort(f,f+n);
        //for(i=0; i<n; i++) printf("%d %d\n",f[i].x,f[i].y);printf("\n");
        ans = time = 0;
        priority_queue<tt> q;
        for(i=0; i<n; i++) {
            if(time<f[i].x) {
                time++;
                // printf("%d %d\n",f[i].x,f[i].y);
                tmp.time = time;
                tmp.y= f[i].y;
                q.push(tmp);
            } else {
                tmp= q.top();
                // printf(" %d %d; %d %d\n",tmp.time,tmp.y, f[i].x,f[i].y);
                if(tmp.time<=f[i].x&&tmp.y <f[i].y) {
                    q.pop();
                    ans += tmp.y;
                    tmp.y = f[i].y;
                    q.push(tmp);
                } else ans += f[i].y;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}







