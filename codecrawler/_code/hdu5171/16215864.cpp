 #include <algorithm>
 #include <iostream>
using namespace std;

 #define ISDIG ((c=getchar())>='0'&&c<='9')
template <typename T>
inline int read(T& x) {
    int c, sign = 1; x = 0;
    while (!(ISDIG || c == '-')) if (c == EOF) return c;
    if (c == '-') sign = -1; else x = x*10 + c - '0';
    while (ISDIG) x = x*10 + c - '0';
    x *= sign;
    return 1;
}

const int MOD = 10000007;
int d[MOD + 10];

int main() {
    int n, k, a, b;
    int t, i; // ä¸´æ¶åéãè®¡æ°å¨

    while (cin >> n >> k) {
        read(a); read(b);
        int s = a + b;
        for (i = 2; i < n; i++) {
            //{æ¾åºåå§Sä¸­æå¤§çä¸¤ä¸ªæ°a,b
            read(t);
            if (t > a) {
                if (t > b) {
                    if (a < b) a = t;
                    else b = t;
                }
                else a = t;
            }
            else if (t > b) b = t;
            //}
            s = (s + t) % MOD;
        }
        if (b > a) swap(a , b); // åè®¾a>=b
        d[0] = a;
        d[1] = a + b;

        //{è®¡ç®åºå¨æcåè¿æ®µå¨æçåç´ ås1
        int c, s1 = d[1];
        for (i = 2; i <= k; i++) {
            d[i] = (d[i-1] + d[i-2]) % MOD;
            s1 = (d[i] + s1) % MOD;
            if (d[i] == a && d[i-1] == b) break;
        }
        c = i;
        //}

        do {
            s = (s + s1) % MOD;
            k -= c;
        } while (k > c);
        // å»æå®æ´çå¨æåï¼è¿æäºæ®ä½çæ«å°¾é¡¹è¦å ä¸
        for (i = 1; i <= k; i++) s = (d[i] + s) % MOD;

        cout << s << "\n";
    }

    return 0;
}
