//#include<cstdio>
//#include<cstring>
//#include<cmath>
//#include<iostream>
//#include<algorithm>
//#include<set>
//#include<map>
//#include<queue>
//#include<vector>
//#include<string>
//
//#define Min(a,b) a<b?a:b
//#define Max(a,b) a>b?a:b
//#define CL(a,num) memset(a,num,sizeof(a));
//#define maxn  30
//#define eps  1e-8
//#define inf 100000000
//#define N  4000000
//#define ll   __int64
//using namespace std;
//
//struct node {
//    int x;
//    int y;
//} a[maxn], ans[maxn];
//
//int cmp(node a, node b) {
//    return a.x < b.x;
//}
//int dp[N], dis[maxn][maxn], pre[N];
//
//int main() {
//    int i, j, n, t, tmp, p, tp, k, x, y;
//    int cas = 0;
//    //freopen("data.txt","r",stdin);
//    scanf("%d", &t);
//    while (t--) {
//        scanf("%d%d", &x, &y);
//        scanf("%d", &n);
//        a[n].x = x;
//        a[n].y = y;
//        for (i = 0; i < n; i++) {
//            scanf("%d%d", &a[i].x, &a[i].y);
//        }
//        for (i = 0; i <= n; i++) {
//            for (j = i + 1; j <= n; j++) {
//                dis[i][j] = dis[j][i] = (a[i].x - a[j].x)*(a[i].x - a[j].x) + (a[i].y - a[j].y)* (a[i].y - a[j].y);
//            }
//        }
//        memset(dp, 0x3f, sizeof (dp));
//        dp[0] = 0;
//        int stat = (1 << n) - 1;
//        for (i = 0; i <= stat; i++) {
//            for (j = 0; j < n; j++) {
//                if (!(i & (1 << j))) {
//                    tp = i | 1 << j;
//                    tmp = dp[i] + 2 * dis[j][n];
//                    if (dp[tp] > tmp) {
//                        dp[tp] = tmp;
//                        pre[tp] = i;
//                    }
//                    for (k = 0; k < n; k++)//濡傛灉涓�娆″幓涓ゅ潡
//                    {
//                        if (!(tp & (1 << k))) {
//                            p = tp | 1 << k;
//                            tmp = dp[i] + dis[j][n] + dis[j][k] + dis[k][n];
//                            if (dp[p] > tmp) {
//                                dp[p] = tmp;
//                                pre[p] = i; // 娉ㄦ剰 杩欓噷鐨勭姸鎬佹槸璁板綍鍘讳袱鍧椾箣鍓嶇殑i
//                            }
//                        }
//                    }
//                }
//            }
//        }
//        printf("Case %d:\n", ++cas);
//        printf("%d\n", dp[stat]);
//        int t = stat;
//        int num = 0;
//        while (t) {
//            bool flag = false;
//            int tmp = t^pre[t];
//            ans[num].y = 25; //鐢ㄦ潵璁板綍涓�娆� 鍙栦袱涓殑绗簩涓厓绱狅紙25琛ㄧず鍒濆鍖栨病鏈夛級
//            for (i = 0; i < n; i++) {
//                if ((tmp >> i)&1) {
//                    if (!flag) {
//                        ans[num].x = i;
//                        flag = true;
//                    } else ans[num].y = i;
//                }
//            }
//            t = pre[t];
//            num++;
//        }
//        sort(ans, ans + num, cmp);
//        for (i = 0; i < num; i++) {
//            if (i == 0)printf("%d", ans[i].x + 1);
//            else printf(" %d", ans[i].x + 1);
//            if (ans[i].y < 25) printf(" %d", ans[i].y + 1);
//        }
//        puts("");
//    }
//}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 22;
const int MAX = 1000010;
int pre[MAX];
int dp[MAX];
int map[MAXN][MAXN];
int num[MAXN];

struct node {
    int x, y;
} Node[MAXN];

int get_dis(node a, node b) {
    return (a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y);
}
bool cmp(node a, node b) {
    return a.x < b.x;
}
int main() {
    node origion;
    int T;
    int N;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d", &origion.x, &origion.y);
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &Node[i].x, &Node[i].y);
        }
        Node[N] = origion;
        for (int i = 0; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                map[i][j] = map[j][i] = get_dis(Node[i], Node[j]);
            }
        }
        int size = (1 << N);
        memset(dp, -1, sizeof (dp));
        dp[0] = 0;
        int dis;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < N; j++) {
                if (!(i & (1 << j))) {
                    dis = dp[i] + 2 * map[N][j];
                    if ((dp[i | (1 << j)] == -1) || (dis < dp[i | (1 << j)])) {
                        dp[i | (1 << j)] = dis;
                        pre[i | (1 << j)] = i;
                    }
                    for (int k = j + 1; k < N; k++) {
                        if (!(i & (1 << k))) {
                            dis = dp[i] + map[N][j] + map[j][k] + map[k][N];
                            if ((dp[i | (1 << j) | (1 << k)] == -1) || dis < dp[i | (1 << j) | (1 << k)]) {
                                dp[i | (1 << j) | (1 << k)] = dis;
                                pre[i | (1 << j) | (1 << k)] = i;
                            }
                        }
                    }
                }
            }
        }
//        printf("Case %d:\n", cas);
//        printf("%d\n", dp[size - 1]);
//        int now = size - 1;
//        int stack[MAXN];
//        int top = 0;
//        while (now) {
//            for (int j = N - 1; j >= 0; j--) {
//                if ((1 << j) & (now - pre[now])) {
//                    stack[++top] = j + 1;
//                }
//            }
//            now = pre[now];
//        }
//        printf("%d", stack[top--]);
//        while (top) {
//            printf(" %d", stack[top--]);
//        }
//        printf("\n");
        int n=N;
        vector<node> sta;
        int s = (1 << n) - 1;
        printf("Case %d:\n", cas);
        printf("%d\n", dp[s]);
        while (s) {
            int b = pre[s];
            node ans;
            ans.x = ans.y = -1;
            for (int i = 0; i < n; i++)
                if (((1 << i) & s) && !((1 << i) & b)) {
                    if (ans.x == -1)
                        ans.x = i;
                    else if (ans.y == -1)
                        ans.y = i;
                }
            sta.push_back(ans);
            s = b;
        }
        sort(sta.begin(), sta.end(), cmp);
        int cnt=0;
        for (int i = 0; i < sta.size(); i++) {
            printf("%d%c", sta[i].x + 1, ++cnt == n ? '\n' : ' ');
            if(sta[i].y!=-1)
                 printf("%d%c", sta[i].y + 1, ++cnt == n ? '\n' : ' ');
        }
    }
    return 0;
}