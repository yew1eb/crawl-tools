#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAXSIZE = 1e5 + 100;

//å¾å¤çå­ç¬¦ä¸²ï¼saï¼rankï¼heightåä¸º[0,len)
#define rep(i,n) for(int i = 0; i < n; i++)

int rk[MAXSIZE], sa[MAXSIZE], height[MAXSIZE], wa[MAXSIZE], res[MAXSIZE];
char w[MAXSIZE];  //è½¬å¨å¾å¤çå­ç¬¦ä¸²
int len;

void getSa(int up) {
    int *k = rk, *id = height, *r = res, *cnt = wa;
    rep(i, up) cnt[i] = 0;
    rep(i, len) cnt[k[i] = w[i]]++;
    rep(i, up) cnt[i + 1] += cnt[i];
    for (int i = len - 1; i >= 0; i--) {
        sa[--cnt[k[i]]] = i;
    }
    int d = 1, p = 0;
    while (p < len){
        for (int i = len - d; i < len; i++) id[p++] = i;
        rep(i, len)  if (sa[i] >= d) id[p++] = sa[i] - d;
        rep(i, len) r[i] = k[id[i]];
        rep(i, up) cnt[i] = 0;
        rep(i, len) cnt[r[i]]++;
        rep(i, up) cnt[i + 1] += cnt[i];
        for (int i = len - 1; i >= 0; i--) {
            sa[--cnt[r[i]]] = id[i];
        }
        swap(k, r);
        p = 0;
        k[sa[0]] = p++;
        rep(i, len - 1) {
            if (sa[i] + d < len && sa[i + 1] + d < len && r[sa[i]] == r[sa[i + 1]] && r[sa[i] + d] == r[sa[i + 1] + d])
                k[sa[i + 1]] = p - 1;
            else k[sa[i + 1]] = p++;
        }
        if (p >= len) return;
        d <<= 1, up = p, p = 0;
    }
}

//è®¡ç®rankåheightå¼
void getHeight() {
    int i, k, h = 0;
    rep(i, len) rk[sa[i]] = i;
    rep(i, len) {
        if (rk[i] == 0)
            h = 0;
        else {
            k = sa[rk[i] - 1];
            if (h) h--;
            while (w[i + h] == w[k + h]) h++;
        }
        height[rk[i]] = h;
    }
}

void getSuffix() {
    len = strlen(w);
    int up = 0;
    rep(i, len) {
        w[i] = w[i] - 'a' + 1;
        up = up > w[i] ? up : w[i];
    }
    w[len] = 0;
    getSa(up + 1);
    getHeight();
}

//nlognæ¶é´é¢å¤ç lognæ¶é´æ¥è¯¢åºé´æå¤§æå°å¼
int ddmin[MAXSIZE][32];

void RMQ_init(int A[], int len){
    //len æ°ç»é¿åº¦
    for (int i = 0; i<len; ++i){
        ddmin[i][0] = A[i];
    }
    for (int j = 1; (1 << j) <= len; ++j)
    for (int i = 0; i + (1 << j) - 1<len; ++i){
        ddmin[i][j] = min(ddmin[i][j - 1], ddmin[i + (1 << (j - 1))][j - 1]);
    }
    return;
}

int RMQ_min(int L, int R){
    int k = 0;
    while (1 << (k + 1) <= R - L + 1) k++;
    return min(ddmin[L][k], ddmin[R - (1 << k) + 1][k]);
}

//nlognæ¶é´é¢å¤ç lognæ¶é´æ¥è¯¢åºé´æå¤§æå°å¼
int dmin[MAXSIZE][32];

void LCP_init(int A[], int len){
    //len æ°ç»é¿åº¦
    for (int i = 0; i<len; ++i){
        dmin[i][0] = A[i];
    }
    for (int j = 1; (1 << j) <= len; ++j)
    for (int i = 0; i + (1 << j) - 1<len; ++i){
        dmin[i][j] = min(dmin[i][j - 1], dmin[i + (1 << (j - 1))][j - 1]);
    }
    return;
}

int LCP(int L, int R){
    if (L == R) return len - sa[L];
    //int l = rk[L], r = rk[R];
    if (L>R) swap(L,R);
    L++;
    int k = 0;
    while (1 << (k + 1) <= R - L + 1) k++;
    return min(dmin[L][k], dmin[R - (1 << k) + 1][k]);
}

long long l,r;

void init(){
    l = 0;
    r = 0;
}

long long b[MAXSIZE];

void calb(){
    b[0] = len - sa[0];
    for (int i = 1; i < len; ++i){
        b[i] = b[i-1] + len - sa[i] - height[i];
    }
}

int main(){
    long long v;
    int q;
    while (scanf("%s",w)!=EOF){
        init();
        getSuffix();
        calb();
        LCP_init(height,len);
        RMQ_init(sa,len);
        scanf("%d",&q);
        for (int i=0;i<q;++i){
            scanf("%lld",&v);
            long long k = (l^r^v)+1;
            if (k>b[len-1]){
                l = 0;
                r = 0;
                printf("0 0\n");
                continue;
            }
            //cout<<"k: "<<k<<endl;

            int L = 0, R = len-1;
            int pos;
            while (L<=R){
                int mid = (L+R)>>1;
                if (b[mid]>=k){
                    pos = mid;
                    R = mid -1;
                }
                else L = mid + 1;
            }
            //cout<<"pos: "<<pos<<endl;

            int sublen;
            if (pos == 0) sublen = k;
            else sublen = height[pos] + k - b[pos-1];
            //cout<<"sublen: "<<sublen<<endl;

            L = pos, R = len -1;
            int ll = pos, rr;
            while (L<=R){
                int mid = (L+R)>>1;
                if (LCP(pos,mid)>=sublen){
                    rr = mid;
                    L = mid + 1;
                }
                else R = mid - 1;
            }

            //cout<<"ll: "<<ll<<"rr: "<<rr<<endl;

            l = RMQ_min(ll,rr) + 1;
            r = l + sublen - 1;
            printf("%lld %lld\n",l,r);
        }
    }
    return 0;
}
