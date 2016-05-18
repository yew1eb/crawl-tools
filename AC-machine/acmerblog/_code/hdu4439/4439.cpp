/*
 * Author:  xioumu
 * Created Time:  2012/10/28 17:18:24
 * File Name: I.cpp
 * solve: I.cpp
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clr(x) memset(x,0,sizeof(x))
#define clrs( x , y ) memset(x,y,sizeof(x))
#define out(x) printf(#x" %d\n", x)
#define sqr(x) ((x) * (x))
typedef long long lint;

const int maxint = -1u>>1;
const double esp = 1e-8;
const double PI = acos(-1.0);
const int MAXN = 1000 + 50;

int sgn(const double &x) {  return (x > esp) - (x < -esp); }

int T,N;

struct Point {
    double x,y,v;
    Point() {};
    Point(const double &_x,const double &_y,const double &_v) :
        x(_x),y(_y),v(_v) {};
    void input() {
        scanf("%lf%lf%lf",&v,&x,&y);
    }
}th,po[MAXN];

struct TEvent {
	double angf,angt;
	TEvent() {};
	TEvent(const double &_angf,const double &_angt) :
		angf(_angf),angt(_angt) {};
	bool operator < (const TEvent &A) const {
		return sgn(angf - A.angf) < 0;
	}
}ev[MAXN * 2];

int main(){
    scanf("%d",&T);
    while(scanf("%d",&N) == 1) {
        th.input();
        for(int i = 0 ; i < N ; i++) {
            po[i].input();
        }
        for(int i = 0 ; i < N ; i++) {
			if (sgn(po[i].x - th.x) == 0 && sgn(po[i].y - th.y) == 0) {
				ev[i] = TEvent(-PI,PI);
				continue;
			}
			if (sgn(th.v) == 0) {
				ev[i] = TEvent(0,0);
				continue;
			}
            double d = po[i].v / th.v;
            if (sgn(d - 1.0) > 0) {
				ev[i] = TEvent(-PI,PI);
				continue;
			}
            double ang = atan2(po[i].y - th.y,po[i].x - th.x);
            double del = asin(d);
			ev[i] = TEvent(ang - del,ang + del);
        }
        sort(ev , ev + N);
		//for(int i = 0 ; i < N ; i++) {
			//printf("%lf %lf\n",ev[i].angf,ev[i].angt);
		//}
        for(int i = 0 ; i < N ; i++) {
            ev[i + N] = ev[i];
        }

        int res = maxint;
        
		for(int i = 0 ; i < N ; i++) {
			int ans = 1;
			double needCover = ev[i].angf + 2 * PI;
			double havCover = ev[i].angt;
			//printf("%lf %lf\n",needCover,havCover);
			int j = i + 1;
			if (sgn(havCover - needCover) >= 0) {
				res = min(res,ans);
				break;
			}
			while(j < i + N) {
				if (sgn(havCover - ev[j].angf) >= 0) {
					double willCover = ev[j].angt;
					while(j < i + N && sgn(havCover - ev[j].angf) >= 0) {
						willCover = max(willCover,ev[j].angt);
						j++;
					}
					ans++;
					havCover = willCover;
				}
				else {
					//printf("--%d %d %lf %d\n",i,j,havCover,ans);
					break;
				}
				if (sgn(havCover - needCover) >= 0) {
					res = min(res,ans);
					break;
				}
			}
		}
        printf("%d\n",res == maxint ? 0 : res);
    }
}