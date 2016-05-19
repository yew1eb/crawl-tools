#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int T;
    cin >> T;
    for (int I = 1; I <= T; ++I) {
        cout << "Case #" << I << ":" << endl;
        int N, M, K;
        cin >> N >> M >> K;
        string ans;
        if (N < M) ans = "Impossible";
        else if (N == M) for (int i = 0; i < N; ++i) ans += 'A';
        else if (K == 1) ans = "Impossible";
        else if (K >= 3) {
            if (M < 3) ans = "Impossible";
            else {
                int t = M - 3;
                for (int i = 0; i <= t; ++i) ans += 'A';
                for (int i = 1; i < N - t; ++i) ans += 'A' + i % 3;
            }
        }
        else {
            if (N == 8 && M == 7) ans = "AABABBAA";
            else if (M < 8) ans = "Impossible";
            else {
                int t = M - 8;
                for (int i = 0; i <= t; ++i) ans += 'A';
                string s("ABAABB");
                for (int i = 1; i < N - t; ++i) ans += s[i % 6];
            }
        }
        cout << ans << endl;
    }
    return 0;
}