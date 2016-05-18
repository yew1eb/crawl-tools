#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned __int64
#define ll __int64
//#define ull unsigned long long
//#define ll long long
#define son1 New(p.xl,xm,p.yl,ym),(rt<<2)-2
#define son2 New(p.xl,xm,min(ym+1,p.yr),p.yr),(rt<<2)-1
#define son3 New(min(xm+1,p.xr),p.xr,p.yl,ym),rt<<2
#define son4 New(min(xm+1,p.xr),p.xr,min(ym+1,p.yr),p.yr),rt<<2|1
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define middle (l+r)>>1
#define MOD 1000000007
#define esp (1e-8)
const int INF=0x3F3F3F3F;
const double DINF=10000.00;
//const double 