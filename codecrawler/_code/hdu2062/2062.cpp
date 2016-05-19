#include <iostream>
#include <cstring>
using namespace std;

int seq[25], idx;
long long kind[25];
int vis[25];

void deal(int N, long long M) {
    bool finish = false;
    while (!finish) {
        for (int i = 1; i <= N; ++i) {
            if (M == 1) {
                seq[++idx] = i;
                finish = true;
                break;
            } else if (M > (kind[N-1] + 1)) {
                M -= kind[N-1] + 1;
            } else {
                seq[++idx] = i;
                M -= 1;
                N -= 1;
                break;
            }
        }    
    }
}

int main() {
    int N;
    long long M;
    kind[1] = 1; 
    for (int i = 2; i <= 20; ++i) {
        kind[i] = i * (kind[i-1] + 1); // i个不同元素集合的非空字典序子集个数
    }
    while (cin >> N >> M) {
        memset(vis, 0, sizeof (vis));
        idx = -1;
        deal(N, M);
        int first = 1;
        for (int i = 0; i <= idx; ++i) {
            int x;
            // seq记录的是一个伪序列，即确定一个数字后又将后面的序列重排 
            for (int j = 1; j <= N; ++j) {
                if (!vis[j]) --seq[i];
                if (!seq[i]) {
                    if (first) {
                        cout << j;
                        first = 0;
                    } else cout << " " << j;
                    vis[j] = 1;
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}