#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1000001;
const int M = 1005;
bool isprime[N << 2] = {false}, flag[N][4] = {false} , vis[N] = {false};
int score[N] = {0} , state[N];
int n , k , b[4] , cnt[1 << 4] , get[1 << 4] , id[1 << 4];
bool issquare (LL num) {
    LL t = sqrt(num + 0.0);
    if(t * t == num || (t + 1) * (t + 1) == num || (t - 1) * (t - 1) == num) return true;
    return false;
}
bool cmp (int a , int b) {
    return get[a] > get[b];
}
void Init() {
    for (int i = 0 ; i < N << 2; i ++) {
        isprime[i] = true;
    }
    isprime[1] = false;
    for (int i = 2 ; i < N << 2 ; i ++) {
        if (! isprime[i]) continue;
        for (int j = 2 ; i * j < N << 2 ; j ++) {
            isprime[i * j] = false;
        }
    }
    get[0] = 0;
    for (int i = 1 ; i < 1 << 4 ; i ++) {
        get[i] = get[i >> 1] + (i & 1);
    }
    for (int i = 0 ; i < 1 << 4 ; i ++) {
        id[i] = i;
    }
    sort (id , id + (1 << 4) , cmp);
}
void check(int i) {
    if (vis[i]) return ;
    flag[i][0] = isprime[i];
    int sum = 0 , cnt = 0;
    LL product = 1LL;
    for (int j = 1 ; j * j <= i ; j ++) {
        if(i % j == 0) {
            product = (LL)product * j;
            sum += j;
            cnt ++;
            if (j * j != i) {
                product *= i / j;
                sum += i / j;
                cnt ++;
            }
            if (product == (LL)i * i) {
                product = 1LL;
            }
        }
    }
    flag[i][1] = isprime[cnt];
    flag[i][2] = isprime[sum];
    flag[i][3] = issquare(product);
    for (int j = 0 ; j < 4 ; j ++) {
        score[i] += flag[i][j] ? 1 : 0;
        state[i] += (flag[i][j] ? 1 : 0) << j;
    }
    vis[i] = true;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r" , stdin);
    #endif
    Init();
    int t;
    scanf ("%d", &t);
    while (t --) {
        scanf ("%d %d", &n, &k);
        for (int i = 0 ; i < 1 << 4; i ++) {
            cnt[i] = 0;
        }
        for (int i = 0 ; i < n ; i ++) {
            int a , b;
            scanf ("%d %d", &a, &b);
            check(a);
            cnt[state[a]] += b;
            printf("%d%c", score[a], i == n - 1 ? '\n' : ' ');
        }
        for (int i = 0 ; i < 4 ; i ++) {
            scanf ("%d", &b[i]);
        }
        int ans = - (1 << 20);
        for (int i = 0 ; i < 1 << 16 ; i ++) {
            int remain = k , ret = 0 , cur = 0;
            for (int j = 0 ; j < 1 << 4 ; j ++) {
                if(! (i & (1 << id[j]))) continue;
                if(cnt[id[j]]) {
                    remain --;
                    ret += get[id[j]];
                }
                else remain = -1;
            } 
            if (remain < 0) continue;
            for (int j = 0 ; j < 1 << 4 ; j ++) {
                if(! (i & (1 << id[j]))) continue;
                cur |= id[j];
                if(remain && remain > cnt[id[j]] - 1) {
                    remain -= cnt[id[j]] - 1;
                    ret += (cnt[id[j]] - 1) * get[id[j]];
                }
                else {
                    ret += remain * get[id[j]];
                    remain = 0;
                }
            }
            if (remain == 0) {
                for (int j = 0 ; j < 4 ; j ++) {
                    if(! ((1 << j) & cur) )
                        ret += b[j];
                }
                ans = max (ans , ret);
            }
        }
        printf ("%d\n", ans);
    }
    return 0;
}