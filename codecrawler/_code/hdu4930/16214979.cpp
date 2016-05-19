#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define RD(x) scanf("%d",&x)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define clr0(x) memset(x,0,sizeof(x))
typedef long long LL;

int u[19], v[19], w[19];
int t,s,n,m;

int id(char temp) {
    if (temp=='Y') return 17;
    if (temp=='X') return 16;
    if (temp=='2') return 15;
    if (temp=='A') return 14;
    if (temp=='K') return 13;
    if (temp=='Q') return 12;
    if (temp=='J') return 11;
    if (temp=='T') return 10;
    return temp-'0';
}

bool check() {
    int i,j,k;
    if (v[16]>=1 && v[17]>=1) {
        return 1;
    }

    if (m==2) {
        if (w[16]>=1 && w[17]>=1) return 0;
    }

    if (m==4) {
        for (i=3; i<=15; ++i)
            if (w[i]>=4){
                //ç¸å¼¹
                for (j=i+1; j<=15; ++j)
                    if (v[j]>=4) return 1;
                return 0;
            }
    }

    for (j=3; j<=15; ++j)
        if (v[j]>=4) return 1;

    if (n<m) return 0;

    if (m==1) {
        for (i=3; i<=17; ++i)
            if (w[i]>=1){
                for (j=i+1; j<=17; ++j)
                    if (v[j]>=1) return 1;
                return 0;
            }
    }

    if (m==2) {
        for (i=3; i<=15; ++i)
            if (w[i]>=2) {
                for (j=i+1; j<=15; ++j)
                    if (v[j]>=2) return 1;
                return 0;
            }
    }

    if (m==3) {
        for (i=3; i<=15; ++i)
            if (w[i]>=3) {
                for (j=i+1; j<=15; ++j)
                    if (v[j]>=3) return 1;
                return 0;
            }
    }

    if (m==4) {
        for (i=3; i<=15; ++i)
            if (w[i]>=3){
                //ä¸å¸¦ä¸
                for (j=i+1; j<=15; ++j)
                    if (v[j]>=3) return 1;
                return 0;
            }
    }

    if (m==5) {
        for (i=3; i<=15; ++i)
            if (w[i]>=3){
                //ä¸å¸¦å¯¹
                for (j=i+1; j<=15; ++j)
                    if (v[j]>=3) {
                        break;
                    }
                if (j>=16) return 0;
                for (k=3; k<=15; ++k) {
                    if (k!=j && v[k]>=2) return 1;
                }
                return 0;
            }
    }

    return 0;
}

bool solve() {
    int i,j,k;

    if (u[16]>=1 && u[17]>=1) {
        return 1;
    }

    if (s==4 || s==6) {
        for (i=3; i<=15; ++i)
            if (u[i]>=4) return 1;
    }

    if (s==1) {
        return 1;
    }

    if (s==2) {
        for (i=3; i<=15; ++i)
            if (u[i]>=2) return 1;
    }

    if (s==3) {
        for (i=3; i<=15; ++i)
            if (u[i]>=3) return 1;
    }

    if (s==4) {
        for (i=3; i<=15; ++i)
            if (u[i]>=3) return 1;
    }

    if (s==5) {
        for (i=3; i<=15; ++i)
            if (u[i]>=3){
                for (k=3; k<=15; ++k)
                    if (k!=i && u[k]>=2) return 1;
            }
    }

    for (i=3; i<=17; ++i){
        if (u[i]>=4) {
            clr0(w);
            w[i]=u[i];
            m = u[i];
            if (!check()) return 1;
        }
        else if (u[i]>=3) {
            for (j=3;j<=17;++j)
                if (j!=i && u[j]>=2){
                    clr0(w);
                    w[i]=u[i];
                    w[j]=2;
                    m = u[i] + 2;
                    if (!check()) return 1;
                }
            clr0(w);
            w[i]=u[i];
            m = u[i];
            if (!check()) return 1;
            if (s>3){
                for (j=3;j<=17;++j)
                    if (j!=i) break;
                w[j]=1;
                m = u[i] + 1;
                if (!check()) return 1;
            }
        }
        else if (u[i]>=2){
            clr0(w);
            w[i]=u[i];
            m = u[i];
            if (!check()) return 1;
        }
        else if (u[i]>=1){
            clr0(w);
            w[i]=u[i];
            m = u[i];
            if (!check()) return 1;
        }
    }
    return 0;
}

int main() {
    char a[19], b[19];
    int i;
    RD(t);
    while (t--) {
        clr0(u),clr0(v);
        scanf("%s", a);
        s = strlen(a);
        for (i = 0; i < s; ++i)
            ++u[id(a[i])];

        scanf("%s", b);
        n = strlen(b);
        for (i = 0; i < n; ++i)
            ++v[id(b[i])];
        if(solve())
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}