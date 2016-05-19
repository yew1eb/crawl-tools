#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 1e5;
int arr[maxn], block[400][10][10];
void clear() {
    fill(arr, arr + maxn, 0);
    for (int a = 0; a < 400; ++a) {
        for (int b = 0; b < 10; ++b) {
            fill(block[a][b], block[a][b] + 10, 0);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        clear();
        int N, M;
        cin >> N >> M;
        int size = sqrt(N);
        for (int a = 0; a < N; ++a) {
            cin >> arr[a];
            for (int b = 0, t = arr[a]; b < 10; ++b, t /= 10) {
                block[a / size][b][t % 10] += 1;
            }
        }
        while (M--) {
            char op;
            cin >> op;
            if (op == 'S') {
                int x, y;
                cin >> x >> y;
                x -= 1;
                for (int a = 0, t = arr[x]; a < 10; ++a, t /= 10) {
                    block[x / size][a][t % 10] -= 1;
                }
                for (int a = 0, t = y; a < 10; ++a, t /= 10) {
                    block[x / size][a][t % 10] += 1;
                }
                arr[x] = y;
            }
            else {
                int l, r, d, p;
                cin >> l >> r >> d >> p;
                l -= 1, r -= 1, d -= 1;
                int res = 0;
                if (l / size == r / size) {//ä¹åè¿éèèæ¼äºï¼ï¼·ï¼¡äºå¾å¤æ¬¡
                    for (int a = l; a <= r; ++a) {
                        for (int b = 0, t = arr[a]; b <= d; ++b, t /= 10) {
                            if (b == d && t % 10 == p) res += 1;
                        }
                    }
                    cout << res << endl;
                    continue;
                }
                for (int a = l; a < (l / size + 1) * size; ++a) {
                    for (int b = 0, t = arr[a]; b <= d; ++b, t /= 10) {
                        if (b == d && t % 10 == p) res += 1;
                    }
                }
                for (int a = l / size + 1; a < r / size; ++a) {
                    res += block[a][d][p];
                }
                for (int a = r / size * size; a <= r; ++a) {
                    for (int b = 0, t = arr[a]; b <= d; ++b, t /= 10) {
                        if (b == d && t % 10 == p) res += 1;
                    }
                }
                cout << res << endl;
            }
        }
    }
    return 0;
}