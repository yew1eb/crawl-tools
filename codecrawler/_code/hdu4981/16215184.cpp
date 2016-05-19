#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1005;

int N, arr[maxn];

int main () {
    while (scanf("%d", &N) == 1) {
        for (int i = 1; i <= N; i++)
            scanf("%d", &arr[i]);
        int pos = (N + 1) / 2, s = 0;
        sort(arr + 1, arr + N + 1);
        for (int i = 1; i <= N; i++)
            s += arr[i];
        printf("%s\n", s >= arr[pos] * N ? "NO" : "YES");
    }
    return 0;
}