#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const char rep[][10] = {"A", "ABC", "ABAABB"};
const int siz[] = {1, 3, 6};

void draw(int id, int n) {
    for (int i = 0; i < n; i++) {
        int v = i % siz[id];
        printf("%c", rep[id][v]);
    }
}

int main () {
    int cas, n, m, k;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        scanf("%d%d%d", &n, &m, &k);
        printf("Case #%d:\n", kcas);
        if (n < m) printf("Impossible");
        else if (n == m) draw(0, n);
        else {
            if (k == 1) printf("Impossible");
            else if (k == 2) {
                if (n == 8 && m == 7) {
                    printf("AABABBAA");
                } else if (m < 8) printf("Impossible");
                else {
                    draw(0, m-8);
                    draw(2, n-m+8);
                }
            } else {
                if (m < 3) printf("Impossible");
                else {
                    draw(0, m-3);
                    draw(1, n-m+3);
                }
            }
        }
        printf("\n");
    }
    return 0;
}