#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <complex>
#include <iomanip>

using namespace std;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;

////////////////////////////////////////////////////////////////////////////////
// General 2D geometry, Polygon cutting, Point in polygon
////////////////////////////////////////////////////////////////////////////////
const int INF = 0x3f3f3f3f; const int MINF = 0xc0c0c0c0;
const ld EPS = 1e-9; const ld PI = acos(-1.L);
ld cp(const pt &a, const pt &b) { return a.real()*b.imag() - b.real()*a.imag();}
ld dp(const pt &a, const pt &b) { return a.real()*b.real() + a.imag()*b.imag();}
inline ld sgn(const ld& x) { return abs(x) < EPS ? 0 : x/abs(x); }
inline bool cmp_lex(const pt& a, const pt& b)
{ return a.real() < b.real() || (a.real() == b.real() && a.imag() < b.imag()); }
inline bool cmp_lex_i(const pt &a, const pt &b)
{ return a.imag() < b.imag() || (a.imag() == b.imag() && a.real() < b.real()); }

// handles ALL cases, change occurences of <= to < to exclude endpoints
bool seg_x_seg(pt a1, pt a2, pt b1, pt b2){
  //if (a1==a2 || b1==b2) return false; // uncomment to exclude endpoints
  int s1 = sgn(cp(a2 - a1, b1 - a1)), s2 = sgn(cp(a2 - a1, b2 - a1));
  int s3 = sgn(cp(b2 - b1, a1 - b1)), s4 = sgn(cp(b2 - b1, a2 - b1));
  if(!s1 && !s2 && !s3) { // collinear
    if (cmp_lex(a2, a1)) swap(a1,a2); if (cmp_lex(b2, b1)) swap(b1, b2);
    return !cmp_lex(b2, a1) && !cmp_lex(a2, b1);
    //return cmp_lex(a1, b2) && cmp_lex(b1, a2);//uncomment to exclude endpoints
  } return s1*s2 <= 0 && s3*s4 <= 0; }

inline pt line_inter(const pt &a, const pt &b, const pt &c, const pt &d){
  return a + cp(c - a, d - c)/cp(b - a, d - c) * (b - a); }

// Projection of (a -> p) to vector (a -> b), SIGNED - positive in front
inline ld proj_dist(const pt &a, const pt &b, const pt &p){
  return dp(b - a, p - a) / abs(b - a); }

// SIGNED distance. Pt on the right of vector (a -> b) will be NEGATIVE.
inline ld lp_dist(const pt &a, const pt &b, const pt &p){
  return cp(b - a, p - a) / abs(b - a); }

// Line segment (a, b) to pt p distance.
inline ld lsp_dist(const pt &a, const pt &b, const pt &p){
  return dp(b - a, p - a) > 0 && dp(a - b, p - b) > 0 ?
    abs(cp(b - a, p - a) / abs(b - a)) : min(abs(a - p), abs(b - p)); }

// Closest pt on line segment (a, b) to pt p.
inline pt lsp_closest(const pt &a, const pt &b, const pt &p){
  if (dp(b - a, p - a) > 0 && dp(a - b, p - b) > 0)
    return abs(cp(b - a, p - a))<EPS ? p : line_inter(a, b, p, p+(a-b)*pt(0,1));
  return abs(a - p) < abs(b - p) ? a : b; }

// Area of a polygon (convex or concave). Always non-negative.
ld area(pol v){ ld out=0;
  for(int i = v.size()-1, j = 0; j < v.size(); i = j++) out += cp(v[i], v[j]);
  return abs(out)/2; }

ld peri(pol v) {
    ld out=0;
    for(int i=0, j=v.size(); i<j; i++) {
        out+= abs(v[i]-v[(i+1)%j]);
    }
    return out;
}

long long round3(ld a) {
    return (int) (a*1000 + 0.5);
}

bool sort_area(pol a, pol b) {
    if(round3(area(a)) == round3(area(b))) {
        return peri(a) > peri(b);
    } else {
        return area(a) > area(b);
    }
}

int main() {
    ld ax, ay, bx, by, cx, cy, dx, dy;
    while(cin >> ax>>ay>>bx>>by>>cx>>cy>>dx>>dy && 
        (abs(ax)>EPS ||
            abs(bx)>EPS || 
            abs(cx)>EPS || 
            abs(dx)>EPS || 
            abs(ay)>EPS || 
            abs(by)>EPS || 
            abs(cy)>EPS || 
            abs(dy)>EPS)) {
        pt a(ax,ay), b(bx,by), c(cx,cy), d(dx,dy), o = line_inter(a,c,b,d);
        //cerr << a << " " << b << " " << c << " " << d << " " << o << endl;
        vector<pol>p(4);
        for(int i=0; i<4; i++) {
            p[i].push_back(o);
        }
        p[0].push_back(a);
        p[0].push_back(b);
        p[1].push_back(b);
        p[1].push_back(c);
        p[2].push_back(c);
        p[2].push_back(d);
        p[3].push_back(d);
        p[3].push_back(a);
        sort(p.begin(), p.end(), sort_area);

        for(int i=0; i<4; i++) {
            cout << fixed << setprecision(3) << area(p[i]) << " " << peri(p[i]);
            if(i<3) cout << " ";
        }cout << endl;
    }
}