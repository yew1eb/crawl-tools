#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 100005;
struct point{
	long long x,y,id;
};
point d[maxn];
long long dx[maxn],dy[maxn];
bool cmpx(point a,point b){
	return a.x < b.x;
}
bool cmpy(point a,point b){
	return a.y < b.y;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t --){
		int n;
		scanf("%d",&n);
		long long xx,yy;
		for(int i = 0;i < n;i ++){
			scanf("%I64d%I64d",&xx,&yy);
			d[i].x = xx - yy;
			d[i].y = xx + yy;
			d[i].id = i;
		}
		sort(d,d + n,cmpx);
		long long minn = 0;
		long long tx = 0;
		for(int i = 1;i < n;i ++){
			tx += d[i].x - d[0].x;
		}
		minn += tx;
		dx[d[0].id] = tx;
		for(int i = 1;i < n;i ++){
			tx += i * (d[i].x - d[i - 1].x) - (n - i) * (d[i].x - d[i - 1].x);
			dx[d[i].id] = tx; 
		}
		sort(d,d + n,cmpy);
		long long ty = 0;
		for(int i = 1;i < n;i ++){
			ty += d[i].y - d[0].y;
		}
		dy[d[0].id] = ty;
		minn += ty;
		for(int i = 1;i < n;i ++){
			ty += i * (d[i].y - d[i - 1].y) - (n - i) * (d[i].y - d[i - 1].y);
			dy[d[i].id] = ty; 
		}
		for(int i = 0;i < n;i ++){
			if(minn > dx[i] + dy[i])minn = dx[i] + dy[i];
		}
		printf("%I64d\n",minn / 2);
	}
	return 0;
}