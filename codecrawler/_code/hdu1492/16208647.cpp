#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <algorithm>

const int P_MAX = 100000; // power maximum

int PolyMult (int *a, int pa, int *b, int pb) {
    static int c [P_MAX];
    int pc = pa + pb;
    memset (c, 0, sizeof (*c) * (pc + 1));
    for (int i=0; i<=pa; ++i) {
        for (int k=0; k<=pb; ++k) {
            assert (i + k < P_MAX);
            c [i + k] += a [i] * b [k];
        }
    }
    memcpy (a, c, sizeof (*c) * (pc + 1));
    return pc;
}

int CountFactor (unsigned long long n, int fac) {
    int cnt = 0;
    while (n % fac == 0) {
        n /= fac;
        ++cnt;
    }
    return cnt;
}

int main () {
    static int e [P_MAX];
    std::fill (e, e + P_MAX, 1);

    static int g [P_MAX]; // generator
    unsigned long long n;

#ifdef ONLINE_JUDGE
    while (scanf ("%I64u", &n) == 1 && n) {
#else
    while (scanf ("%llu", &n) == 1 && n) {
#endif
        int twos = CountFactor (n, 2);
        int threes = CountFactor (n, 3);
        int fives = CountFactor (n, 5);
        int sevens = CountFactor (n, 7);

        memset (g, 0, sizeof (*g) * (twos + threes + fives + sevens + 1));
        g [0] = 1;
        int pg = 0; // power of g

        pg = PolyMult (g, pg, e, twos);
        pg = PolyMult (g, pg, e, threes);
        pg = PolyMult (g, pg, e, fives);
        pg = PolyMult (g, pg, e, sevens);

        int sum = 0;
        for (int i=0; i<=pg; ++i) {
            sum += g [i];
        }

        printf ("%d\n", sum);
    }
    return 0;
}
