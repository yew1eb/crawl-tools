#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<ctime>
#include<functional>
#include<algorithm>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MX = 1500 + 5;
const int INF = 0x3f3f3f3f;
const double exps = 1e-3;//æ¯è¦æ±ç²¾åº¦ä½2ä¸ªå°±è¡
const double pi = acos(-1.0);

double fx[MX], fy[MX], best[MX];
double PX[MX], PY[MX];

double Rand(double L, double R) {//åºé´åéæºæ°çæå½æ°
    return (rand() % 10000) / 10000.0 * (R - L) + L;
}

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int T, X, Y, n;
    scanf("%d", &T);
    srand(time(NULL));
    while(T--) {
        scanf("%d%d%d", &X, &Y, &n);
        for(int i = 1; i <= n; i++) {
            scanf("%lf%lf", &PX[i], &PY[i]);
        }

        for(int i = 1; i <= 30; i++) {
            fx[i] = Rand(1, X);
            fy[i] = Rand(1, Y);
            best[i] = INF;
            for(int j = 1; j <= n; j++) {
                best[i] = min(best[i], dist(fx[i], fy[i], PX[j], PY[j]));//è¯ä¼°å½æ°ï¼é å®æ¥è¯ä¼°æ´ä¸ªéç«è¿ç¨çå¥½å
            }
        }

        double step = max(X, Y);//ä¸è¬æ¯æé¿çè·¨åº¦
        while(step > exps) {
            for(int i = 1; i <= 30; i++) {//åå§ç¶æä¸è¬30ä¸ª
                for(int j = 1; j <= 30; j++) {//ä¸è¬å¾ªç¯30æ¬¡å³å¯
                    double angel = Rand(0, 2 * pi);//æä¸¾ä»»ä½è§åº¦ï¼ä½¿å¾å°çæ°ç¹ååå¨æ©æ£
                    double nx = fx[i] + cos(angel) * step;
                    double ny = fy[i] + sin(angel) * step;
                    if(nx < 0 || nx > X || ny < 0 || ny > Y) continue;

                    double d = INF;
                    for(int k = 1; k <= n; k++) {
                        d = min(d, dist(nx, ny, PX[k], PY[k]));
                    }
                    if(d > best[i]) {
                        best[i] = d;
                        fx[i] = nx;
                        fy[i] = ny;
                    }
                }
            }
            step *= 0.85;//éç«ï¼å¸¸æ°ï¼ä¸ç®¡
        }
        int t = 1;
        for(int i = 1; i <= 30; i++) {
            if(best[i] >= best[t]) {//æ¾å°éç«åçç¶æä¸­ï¼æä¼ç
                t = i;
            }
        }

        printf("The safest point is (%.1lf, %.1lf).\n", fx[t], fy[t]);
    }
    return 0;
}
