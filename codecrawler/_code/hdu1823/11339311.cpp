#include <cstdio>
#include <algorithm>

using namespace std;

#define lson (o<<1)
#define rson ((o<<1)|1)

const int maxh = 100 + 10;
const int maxa = 1000 + 10;
int mmax[maxh<<2][maxa<<2];

void build_A(int O, int o, int L, int R) {      //»îÆÃ¶È½¨Ê÷
    mmax[O][o] = -1;
    if(L == R) return;
    int M = (L + R) >> 1;
    build_A(O, lson, L, M);
    build_A(O, rson, M+1, R);
}

void build_H(int o, int L, int R) {     //Éí¸ß½¨Ê÷
    build_A(o, 1, 0, 1000);
    if(L == R) return;
    int M = (L + R) >> 1;
    build_H(lson, L, M);
    build_H(rson, M+1, R);
}

void Insert_A(int O, int o, int L, int R, int A, int D) {       //¸ù¾Ý»îÆÃ¶È½¨Ê÷
    if(L == R) {
        mmax[O][o] = max(mmax[O][o], D);
        return;
    }
    int M = (L + R) >> 1;
    if(A <= M) Insert_A(O, lson, L, M, A, D);
    else Insert_A(O, rson, M+1, R, A, D);
    mmax[O][o] = max(mmax[O][lson], mmax[O][rson]);
}

void Insert(int o, int L, int R, int H, int A, int D) {
    Insert_A(o, 1, 0, 1000, A, D);
    if(L == R) return;
    int M = (L + R) >> 1;
    if(H <= M) Insert(lson, L, M, H, A, D);
    else Insert(rson, M+1, R, H, A, D);
}

int query_A(int O, int o, int L, int R, int A1, int A2) {       //¸ù¾Ý»îÆÃ¶È²éÑ¯
    if(A1 <= L && R <= A2) return mmax[O][o];
    int M = (L + R) >> 1;
    int Max1 = -1, Max2 = -1;
    if(A1 <= M) Max1 = query_A(O, lson, L, M, A1, A2);
    if(A2 > M) Max2 = query_A(O, rson, M+1, R, A1, A2);
    return (Max1 > Max2) ? Max1 : Max2;
}

int query(int o, int L, int R, int H1, int H2, int A1, int A2) {
    if(H1 <= L && R <= H2) return query_A(o, 1, 0, 1000, A1, A2);
    int M = (L + R) >> 1;
    int Max1 = -1, Max2 = -1;
    if(H1 <= M) Max1 = query(lson, L, M, H1, H2, A1, A2);
    if(H2 > M) Max2 = query(rson, M+1, R, H1, H2, A1, A2);
    return (Max1 > Max2) ? Max1 : Max2;
}

int main() {
    int M;
    char op;
    while(scanf("%d", &M) == 1 && M) {
        build_H(1, 100, 200);
        for(int i = 0; i < M; i++) {
            getchar();
            op = getchar();
            if(op == 'I') {
                int H, A, D;
                double AA, DD;
                scanf("%d%lf%lf", &H, &AA, &DD);
                A = (int)(AA * 10);
                D = (int)(DD * 10);
                Insert(1, 100, 200, H, A, D);
            } else {
                int H1, H2, A1, A2;
                double AA, BB;
                scanf("%d%d%lf%lf", &H1, &H2, &AA, &BB);
                A1 = (int)(AA * 10);
                A2 = (int)(BB * 10);
                if(A1 > A2) swap(A1, A2);
                if(H1 > H2) swap(H1, H2);
                int ret = query(1, 100, 200, H1, H2, A1, A2);
                ret != -1 ? printf("%.1f\n", ret/10.0) : puts("-1");
            }
        }
    }
    return 0;
}
