#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <assert.h>
#include <queue>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALLL(x) x.begin(),x.end()
#define SORT(x) sort(ALLL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILLL(x,c) memset(x,c,sizeof(x))
using namespace std;
const double eps = 1e-6;
#define LL long long 
#define pb push_back
const int maxn  = 11000;

double a,b , l, r;
// simpsonå¬å¼ç¨å°çå½æ°  
double F(double x){
     return sqrt(b*b*(1-x*x/(a*a)));
}

// ä¸ç¹simpsonæ³ãè¿éè¦æ±Fæ¯ä¸ä¸ªå¨å±å½æ°  
double simpson(double a,double b){
    double c =  a+(b-a)/2;
    return (F(a) + 4*F(c) + F(b))*(b-a)/6;
}
// èªéåºSimpsonå¬å¼ï¼éå½è¿ç¨ï¼ãå·²ç¥æ´ä¸ªåºé´[a,b]ä¸çä¸ç¹simpsonå¼A 
double asr(double a , double b ,double eps ,double A){
    double c = a+ (b-a)/2;
    double L = simpson(a,c) ,R = simpson(c,b);
    if(fabs(A-L-R)<=15*eps) return L + R +(A-L-R)/15;
    return asr(a,c,eps/2,L) + asr(c,b,eps/2,R);
}
// èªéåºSimpsonå¬å¼ï¼ä¸»è¿ç¨ï¼  
double asr(double a, double b, double eps) {  
  return asr(a, b, eps, simpson(a, b));  
}  


int main(){
    int t ;
    cin >>t ;
    while(t--){
        scanf("%lf%lf%lf%lf",&a,&b,&l,&r);
        double ans = asr(l,r,eps);
        ans *= 2;
        printf("%.3f\n",ans);
    }
    return 0;
}