#include <cstdio>
#include <cstring>
#include <cmath>

const double eps = 1e-8;
const double PI = acos(-1.0);

struct Tran {
    double x, y, r;
    double v[3][3];
    Tran() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                v[i][j] = 0;
    }
    void init() {
        scanf("%lf%lf%lf", &x, &y, &r);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                v[i][j] = 0;
        v[0][0] = cos(r);
        v[0][1] = sin(r);
        v[1][0] = -sin(r);
        v[1][1] = cos(r);
        v[2][0] = x * (1 - cos(r)) + y * sin(r);
        v[2][1] = y * (1 - cos(r)) - x * sin(r);
        v[2][2] = 1;
    }

    Tran operator * (Tran c) {
        Tran ans;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    ans.v[i][j] += v[i][k] * c.v[k][j];
        return ans;
    }
} tran[15];

int t, n;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        Tran ans;
        for (int i = 0; i < 3; i++)
            ans.v[i][i] = 1;
        for (int i = 0; i < n; i++) {
            tran[i].init();
            ans = ans * tran[i];
        }
        double r = atan2(ans.v[0][1], ans.v[0][0]);
        if (r < 0) r = 2 * PI + r;
        double cosr = ans.v[0][0];
        double sinr = ans.v[0][1];
        double a1 = 1 - cosr;
        double b1 = sinr;
        double b2 = 1 - cosr;
        double a2 = -sinr;
        double c1 = ans.v[2][0];
        double c2 = ans.v[2][1];
        double y = (c1 * a2 - a1 * c2) / (b1 * a2 - a1 * b2);
        double x = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
        printf("%.10lf %.10lf %.10lf\n", x, y, r);
    }
    return 0;
}