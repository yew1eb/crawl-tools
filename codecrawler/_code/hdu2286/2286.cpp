#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
#define Maxn 1<<12
int Ddc[110];
int n, m, t;
int M, N;
int dp[Maxn];
int pp[Maxn];
bool hash[Maxn];
int co;
int num[Maxn];
//制作Ddc数组，将所有的不可以共存状态存成一个数字
void getmap() {
    char str[1000];
    char st[1000];
    map<string,int>to;
    for (int i = 0 ; i < n; i ++) {
        scanf("%s", st);
        if(to.count(st)) continue;
        to[st] = i;
    }
    getchar();
    memset(Ddc, 0, sizeof(Ddc));
    for (int k = 0; k < m; k ++) {
        gets(st);
        int tm = -1;
        int len = strlen(st);
        for (int i = 0; i <= len; i ++) {
            if(st[i] == ' ' || st[i] == '\0') {
                if(tm != -1) {
                    str[++tm] = '\0';
                    if(to.count(str)) {
                        int a = to[str];
                        Ddc[k] += (1<<a);
                    }
                }
                tm = -1;
            }else {
                str[++tm] = st[i];
            }
        }
    }
}
//获取n里面有多少个1
int getnum(int n)
{
     n = (0x55555555UL&n)+((n>>1)&0x55555555UL);
     n = (0x33333333UL&n)+((n>>2)&0x33333333UL);
     n = (0x0f0f0f0fUL&n)+((n>>4)&0x0f0f0f0fUL);
     n = (0x00ff00ffUL&n)+((n>>8)&0x00ff00ffUL);
     n = (0x0000ffffUL&n)+((n>>16)&0x0000ffffUL);
    return n;
}
//y内是否有x，有返回true
bool Judge(int y, int x) {
    if ((x&y) == x) return true;
    return false;
}

void pri() {
    memset(dp, -1, sizeof(dp));
    memset(hash, 0, sizeof(hash));
    M = 1<<n;
    N = M - 1;
    co = -1;
    pp[++co] = 0;
    for (int i = 1; i < M; i ++) {
        bool mark = true;
        for (int j = 0; j < m; j ++) {
            if(Judge(i,Ddc[j])) {
                mark = false;
                break;
            }
        }
        if(mark) {
            pp[++co] = i;
            hash[i] = true;
        }
    }
    hash[0] = true;
    pp[++co] = N;
}
int Min(int x, int y) {
    return x > y ? y : x;
}
int getans() {
    dp[0] = 0;
    for (int i = 1; i <= co; i ++) {
        for (int j = 0; j < co; j++) {
            if(i == j) continue;
            if(!(dp[j]+1)) continue;
            for (int L = 0; L < co; L ++) {
                if(pp[j]&pp[L]) continue; //i和L中存在相同的东西
                if(pp[i]&pp[L]) continue; //j和L中存在相同的东西
                if((n- num[pp[j]] - num[pp[L]])>t) continue; //从起始岸到终岸的船上的东西超过了t件
                if((n- num[pp[i]] - num[pp[L]])>t) continue; //从终岸到的起始岸船上的东西超过了t件
                if(dp[i]+1) {
                    dp[i] = Min(dp[i], dp[j]+1);
                }else {
                    dp[i] = dp[j]+1;
                }
            }
        }
    }
    return dp[co];
}
void init() {
    memset(num, 0, sizeof(num));
    M = 1<<12;
    for (int i = 0; i < M; i ++) {
        num[i] = getnum(i);
    }
}
//注意要先处理掉没有限制条件的，不然L的范围不只到co-1
int main()
{
    init();
    while(scanf("%d%d%d", &n, &m, &t) != EOF) {
        getmap();
        if(!m) {
            int tmp = n/t;
            if(t*tmp < n) tmp ++;
            printf("%d\n", tmp*2-1);
            continue;
        }
        pri();
        int ans = getans();
        if(ans+1) {
            ans = ans*2 - 1;
            printf("%d\n", ans);
        }else {
            printf("-1\n");
        }
    }
    return 0;
}