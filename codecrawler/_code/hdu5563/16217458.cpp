#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
//point
const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(double x) {
    if(fabs(x)<eps) return 0;
    if(x < 0) return -1;
    else return 1;
}
struct Point{
    double x, y;
    Point() {}
    Point(double _x, double _y){
        x = _x; y = _y;
    }
    Point operator -(const Point& b)const {
        return Point(x - b.x, y-b.y);
    }
    double operator ^(const Point& b)const {
        return x*b.y-y*b.x;
    }
    double operator *(const Point& b)const {
        return x*b.x+y*b.y;
    }
    int operator ==(const Point& b)const{  //ç²¾åº¦å¤ç   å¤æ­ä¸¤ç¹æ¯å¦ç¸ç­ 
        return !(sgn(x-b.x)&&sgn(y-b.y));
    }

    void transXY(double B){
        double tx = x, ty = y;
        x = tx*cos(B)-ty*sin(B);
        y = tx*sin(B)+ty*cos(B);
    }
};
double dist(Point a, Point b){
    return sqrt((a-b)*(a-b));
}

bool jg(Point* P,int n){
    int a[5] = {0, 1, 2, 3, 4};
    do{
        int ok = 1; 
        double bz1 = dist(P[a[0]], P[a[2]]); 
        for(int i = 1; i < 5; i++){
            if(fabs(bz1-dist(P[a[i]], P[a[(i+2)%5]]))>=1e-4)//æ¯è¾ä»ä»¬çå¯¹è§çº¿é¿åº¦
            {    
                    ok = 0;
                    break;
            }
        }
        double bz2 = dist(P[a[0]], P[a[1]]);
        for(int i = 1; i < 5; i++){
            if(fabs(bz2-dist(P[a[i]], P[a[(i+1)%5]]))>=1e-4)//æ¯è¾ç¸é»è¾¹çé¿åº¦ 
            {    
                    ok = 0;
                    break;
            }
        }
        if(ok) return 1; 
    }while(next_permutation(a, a+n));
    return 0;
}


int main() {
    Point a[5];
    int n; 
    scanf("%d", &n);
    while(n--){
        for(int i = 0; i < 5; i++) {
            cin >> a[i].x >> a[i].y ;
        }
        if(jg(a, 5))cout << "Yes" << endl;
        else cout << "No"<< endl;
    } 
    
} 