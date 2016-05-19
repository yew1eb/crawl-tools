#include <iostream>
#include <cstring>
#include <cmath>
#define INF 9223372036854775807ULL
using namespace std;

typedef unsigned long long ull;
const int MAXN = 10000010;
int T, cnt;
ull N, K, ans, factorA[MAXN], factorB[MAXN], totFactor, prime[MAXN], totPrime;
bool isPrime[MAXN];

void getPrime(ull n) {
    memset(isPrime, true, sizeof(isPrime));
    totPrime = 0;
    for (ull i = 2; i <= n; i++) {
        if (isPrime[i]) {
            prime[++totPrime] = i;
        }
        for (ull j = 1; j <= totPrime && i*prime[j] <= n; j++) {
            isPrime[i*prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
}

void getFactor(ull n) {
    /*
    ull now = n;
    totFactor = 0;
    for (ull i = 2; i*i <= n; i++) {
        if (now % i == 0) {
            factorA[++totFactor] = i;
            factorB[totFactor] = 0;
            while (now % i == 0) {
                factorB[totFactor]++;
                now /= i;
            }
        }
    }
    if (now != 1) {
        factorA[++totFactor] = now;
        factorB[totFactor] = 1;
    }
    */
    totFactor = 0;
    ull now = n;
    for (ull i = 1; i <= totPrime && prime[i] <= now; i++) {
        if (now % prime[i] == 0) {
            factorA[++totFactor] = prime[i];
            factorB[totFactor] = 0;
            while (now % prime[i] == 0) {
                factorB[totFactor]++;
                now /= prime[i];
            }
        }
    }
    if (now != 1) {
        factorA[++totFactor] = now;
        factorB[totFactor] = 1;
    }
}

void solve() {
    if (K == 1) {
        cout << "Case " << ++cnt << ": inf" << endl;
    } else {
        getFactor(K);
        ans = INF;
        for (ull i = 1; i <= totFactor; i++) {
            ull temp = N, sum = 0;
            while (temp > 0) {
                sum += temp / factorA[i];
                temp /= factorA[i];
            }
            if (sum / factorB[i] < ans) {
                ans = sum / factorB[i];
            }
        }
        cout << "Case " << ++cnt << ": " << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    getPrime(10000000);
    while (T--) {
        cin >> N >> K;
        solve();
    }
    return 0;
}