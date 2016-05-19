#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a%b) : a; }
LL lcm(LL a, LL b) { return a / gcd(a,b) * b; }
struct Rat {
  LL a, b;
  Rat(LL a=0):a(a),b(1) { }
  Rat(LL x, LL y):a(x),b(y) {
    if(b < 0) a = -a, b = -b;
    LL d = gcd(a, b); if(d < 0) d = -d;
    a /= d; b /= d;
  }
};
Rat operator + (const Rat& A, const Rat& B) {
  LL x = lcm(A.b, B.b);
  return Rat(A.a*(x/A.b)+B.a*(x/B.b), x);
}
Rat operator - (const Rat& A, const Rat& B) { return A + Rat(-B.a, B.b); }
Rat operator * (const Rat& A, const Rat& B) { return Rat(A.a*B.a, A.b*B.b); }
void updatemin(Rat& A, const Rat& B) {
  if(A.a*B.b > B.a*A.b) A.a = B.a, A.b = B.b;
}

Rat k(360, 1);
void print(int x, int y){
    int ax = abs(x), ay = abs(y);
    if(ax==0){
        printf("0");
        return ;
    }
    if(ax > 180*ay) {
        //cout<<ax<<","<<ay<<endl;
        Rat ans = k - Rat(ax, ay);
        ax = abs(ans.a), ay = abs(ans.b);

    }

    if(ay==1) printf("%d", ax);
    else printf("%d/%d", ax, ay);
}
void solve(int hh, int mm, int ss){
    //hh/12 + 1/12*mm/60 + 1/12*1/60*ss/60;
    //hh*60*60 + mm*60 + ss / 12*60*60;
    Rat h((hh%12)*60*60+mm*60+ss, 12*60*60);
    //mm/60 + 1/60*ss/60
    Rat m(mm*60 + ss, 60*60);
    Rat s(ss, 60);
    Rat a;
    a = (h - m)*k;
    print(a.a, a.b);printf(" ");

    a = (h - s)*k;
    print(a.a, a.b);printf(" ");

    a = (m - s)*k;
    print(a.a, a.b);printf(" \n");
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        solve(hh,mm,ss);
    }
    return 0;
}