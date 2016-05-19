#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100000 + 5;
struct Peo {
    int h, num;
}p[N];
int n, s[N << 2], res[N];

bool cmp(Peo a, Peo b) {
    return a.h < b.h;
}

void pushup(int k) {
    s[k] = s[k * 2] + s[k * 2 + 1];
}

void build(int k, int left, int right) {
    if (left == right) {
        s[k] = 1;
        return;
    }
    int mid = (left + right) / 2;
    build(k * 2, left, mid);
    build(k * 2 + 1, mid + 1, right);
    pushup(k);
}

void modify(int k, int left, int right, int pos, int val) {
    if (left == right) {
        res[left] = val;
        s[k] = 0;
        return;
    }
    int mid = (left + right) / 2;
    if (pos <= s[k * 2])
        modify(k * 2, left, mid, pos, val);
    else
        modify(k * 2 + 1, mid + 1, right, pos - s[k * 2], val);
    pushup(k);
}

int main() {
    int t, cas = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        build(1, 1, n);
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &p[i].h, &p[i].num);
        sort(p + 1, p + n + 1, cmp);
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            int m = n - i;
            int temp = m - p[i].num;
            if (temp < 0) {
                flag = 1;
                break;
            }
            if (p[i].num < temp)
                modify(1, 1, n, p[i].num + 1, p[i].h);
            else
                modify(1, 1, n, temp + 1, p[i].h);
        }
        printf("Case #%d: ", cas++);
        if (flag) {
            printf("impossible\n"); 
            continue;
        }
        printf("%d", res[1]);
        for (int i = 2; i <= n; i++)
            printf(" %d", res[i]);
        printf("\n");
    }
    return 0;
}