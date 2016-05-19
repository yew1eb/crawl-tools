#include <iostream>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
const int maxn = 60005;
const int maxm = 20005;

struct Point {
    int x, y;
    double mag;
    bool operator < (const Point &oth) const {
        return x < oth.x;
    }
} pt[maxn];
struct Query {
    int lx, ly, ux, uy;
    int id, sc;
    double mc;
} qu[maxm];
bool lcmp(const Query &q1, const Query &q2) {
    return q1.lx < q2.lx;
}
bool ucmp(const Query &q1, const Query &q2) {
    return q1.ux < q2.ux;
}
bool idcmp(const Query &q1, const Query &q2) {
    return q1.id < q2.id;
}

int yhash[maxn+maxm+maxm], sz;
int n, m;
int cntC[maxn+maxm+maxm];
double magC[maxn+maxm+maxm];

int Find(int y) {
    int l = 0, r = sz - 1, m;
    while (l < r) {
        m = (l + r) >> 1;
        if (yhash[m] > y)
            r = m - 1;
        else if (yhash[m] < y)
            l = m + 1;
        else
            return m;
    }
    return l;
}

template<class T>
void Modify(int pos, const T &num, T C[]) {
    for ( ; pos <= sz; pos += (pos & (-pos))) {
        C[pos] += num;
    }
}
template<class T>
T GetSum(int pos, const T C[]) {
    T res = 0;
    for ( ; pos > 0; pos -= (pos & (-pos))) {
        res += C[pos];
    }
    return res;
}

int main() {
    int i, j, id, id1, id2;

    while(scanf("%d %d", &n, &m) != EOF) {
        sz = 0;
        for (i = 0; i < n; i++) {
            scanf("%d %d %lf", &pt[i].x, &pt[i].y, &pt[i].mag);
            yhash[sz++] = pt[i].y;
        }
        for (i = 0; i < m; i++) {
            scanf("%d %d %d %d", &qu[i].lx, &qu[i].ly, &qu[i].ux, &qu[i].uy);
            qu[i].id = i; qu[i].sc = 0; qu[i].mc = 0.0;
            yhash[sz++] = qu[i].ly;
            yhash[sz++] = qu[i].uy;
        }
        sort(yhash, yhash + sz);
        j = 1;
        for (i = 1; i < sz; i++) {
            if (yhash[i] != yhash[i-1])
                yhash[j++] = yhash[i];
        }
        sz = j;

        sort(pt, pt + n);
        sort(qu, qu + m, ucmp);
        memset(cntC + 1, 0, sz * 4);
        memset(magC + 1, 0, sz * 8);
        for (i = j = 0; i < m; i++) {
            while (j < n && pt[j].x <= qu[i].ux) {
                id = Find(pt[j].y);
                Modify(id + 1, 1, cntC);
                Modify(id + 1, pt[j].mag, magC);
                j++;
            }
            id1 = Find(qu[i].ly);
            id2 = Find(qu[i].uy);

            qu[i].sc += GetSum(id2 + 1, cntC) - GetSum(id1, cntC);
            qu[i].mc += GetSum(id2 + 1, magC) - GetSum(id1, magC);
        }
        sort(qu, qu + m, lcmp);
        memset(cntC + 1, 0, sz * 4);
        memset(magC + 1, 0, sz * 8);
        for (i = j = 0; i < m; i++) {
            while (j < n && pt[j].x < qu[i].lx) {
                id = Find(pt[j].y);
                Modify(id + 1, 1, cntC);
                Modify(id + 1, pt[j].mag, magC);
                j++;
            }
            id1 = Find(qu[i].ly);
            id2 = Find(qu[i].uy);

            qu[i].sc -= GetSum(id2 + 1, cntC) - GetSum(id1, cntC);
            qu[i].mc -= GetSum(id2 + 1, magC) - GetSum(id1, magC);
        }
        sort(qu, qu + m, idcmp);
        for (i = 0; i < m; i++) {
            printf("%.2lf/%d\n", qu[i].mc + eps, qu[i].sc);
        }
    }
    return 0;
}