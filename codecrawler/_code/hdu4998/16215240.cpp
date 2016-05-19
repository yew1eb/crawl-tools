#include<cstdio>
#include<cmath>
using namespace std;

#define PI acos(-1.0)

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

int n;
Point p[15];  //æè½¬ç¹
double rad[15]; //æè½¬è§åº¦

typedef Point Vector;

Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (Point A, Point B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator * (Vector A, double p) { return Vector(A.x * p, A.y * p); }
Vector operator / (Vector A, double p) { return Vector(A.x / p, A.y / p); }

bool operator < (const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

const double eps = 1e-10;
int dcmp(double x) {
    if(fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}

bool operator == (const Point& a, const Point& b) {
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }  //ç¹ç§¯
double Length(Vector A) { return sqrt(Dot(A, A)); } //æ±åéçæ¨¡
double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); } //æ±ä¸¤ä¸ªåéçå¤¹è§
double Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; } //åä¹

Vector Rotate(Vector A, double rad) {  //åéæè½¬
    return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}

Vector Normal(Vector A) {  //æ±Aåéçæ³åé
    double L = Length(A);
    return Vector(-A.y / L, A.x / L);
}

Point GetLineIntersection(Point P, Vector v, Point Q, Vector w) {  //æ±ç´çº¿äº¤ç¹
    Vector u = P - Q;
    double t = Cross(w, u) / Cross(v, w);
    return P + v * t;
}

Vector Rotate_Point(Vector A) {  
    for(int i = 0; i < n; i++) {
        A = p[i] + Rotate(A - p[i], rad[i]);  //è½¬åä¸ºåéæè½¬
    }
    return A;
}

Vector Get_Mid_Point(Point A, Point B) {  //æ±ä¸­ç¹
    return Vector((A.x + B.x) / 2, (A.y + B.y) / 2);
}

void Get_Ans() {
    Point f1[2], f2[2], mid[2], vec[2];
    f1[0].x = -1;
    f1[0].y = -1;
    f1[1].x = -10;
    f1[1].y = -50;
    for(int i = 0; i < 2; i++) {
        f2[i] = Rotate_Point(f1[i]);
        mid[i] = Get_Mid_Point(f1[i], f2[i]);
        vec[i] = Normal(f1[i] - f2[i]);
    }

    Point ans = GetLineIntersection(mid[0], vec[0], mid[1], vec[1]);
    double ansp = Angle(f1[0] - ans, f2[0] - ans);

    if(Cross(f1[0] - ans, f2[0] - ans) < 0)
        ansp = 2 * PI - ansp;
    if(dcmp(ans.x) == 0) ans.x = 0;
    if(dcmp(ans.y) == 0) ans.y = 0;

    printf("%.10lf %.10lf %.10lf\n", ans.x, ans.y, ansp);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%lf%lf%lf", &p[i].x, &p[i].y, &rad[i]);
            if(dcmp(rad[i] - 2 * PI) == 0 || dcmp(rad[i]) == 0) {
                rad[i] = 0;
                n--;
                i--;
            }
        }
        Get_Ans();
    }
    return 0;
}