/*
 * Author: yew1eb
 * Created Time:  2014Äê11ÔÂ03ÈÕ ÐÇÆÚÒ» 16Ê±50·Ö09Ãë
 * File Name: t.cpp
 */
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
const int inf = 0x7fffffff;
const ll  INF = 1e18;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int maxn = 600010;

void pre_EKMP(char x[], int m, int next[]){
    next[0] = m;
    int j = 0;
    while(j+1<m && x[j] == x[j+1]) j++;
    next[1] = j;
    int k = 1;
    for(int i=2; i<m; ++i){
        int p = next[k] + k - 1;
        int L = next[i-k];
        if( i+L < p+1 ) next[i] = L;
        else {
            j = max(0, p-i+1);
            while(i+j<m && x[i+j]==x[j]) j++;
            next[i] = j;
            k = i;
        }
    }
}

void EKMP(char x[], int m, char y[], int n, int next[], int extend[]){
    pre_EKMP(x,m,next);
    int j = 0;
    while(j<n && j<m&&x[j]==y[j])j++;
    extend[0] = j;
    int k = 0;
    for(int i=1; i<n; ++i){
        int p = extend[k] + k - 1;
        int L = next[i-k];
        if(i+L<p+1) extend[i] = L;
        else {
            j = max(0, p-i+1);
            while(i+j<n&&j<m&&y[i+j]==x[j]) j++;
            extend[i] = j;
            k = i;
        }
    }
}

char str1[maxn], str2[maxn];
int v[30], sum[maxn];
int next[maxn], extend1[maxn], extend2[maxn];

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        for(int i=0; i<26; ++i) scanf("%d", &v[i]);
        scanf("%s", str1);
        sum[0] = 0;
        int len = strlen(str1);
        for(int i=0; i<len; ++i){
            sum[i+1] = sum[i] + v[str1[i]-'a'];
            str2[i] = str1[len-i-1];
        }
        str2[len] = 0;
        EKMP(str1, len, str2, len, next, extend1);
        EKMP(str2, len, str1, len, next, extend2);
        int ans = -1e8;
        for(int i=1; i<len; ++i){
            int tmp = 0;
            if(i+extend1[i]==len)
                tmp += sum[len-i];
            int j = len - i;
            if(j+extend2[j]==len)
                tmp += sum[len] - sum[j];
            if(tmp>ans) ans = tmp;
        }
        printf("%d\n", ans);
    }
    return 0;
}

