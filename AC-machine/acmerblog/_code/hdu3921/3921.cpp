#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define EPS 1e-4
const int MAXN = 201;
int n;
double ans,mi;
struct Point{
		double x,y;
		void input(){
				scanf("%lf%lf",&x,&y);
		}

}ps[MAXN],o;
inline double pdis(Point a,Point b){
		return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int flag[MAXN];
int minodis[MAXN][MAXN];
int mindis[MAXN][MAXN];
double odis[MAXN];
double ppdis[MAXN][MAXN];
int si,ssi,o1,o2,o3,o4;
inline int cmp1(int a,int b){
		return ppdis[a][si] + EPS < ppdis[b][si];
}
inline int cmp2(int a,int b){
		return ppdis[a][ssi] + odis[a] + EPS < ppdis[b][ssi] + odis[b];
}

inline void update(int p1,int p2,int p3,int p4){
	
		double tmp = odis[p1] + ppdis[p1][p2] + ppdis[p2][p3] + ppdis[p3][p4];
		if(tmp+EPS < mi){
			mi = tmp;
			o1 = p1;o2 = p2;o3 = p3;o4 = p4;
		}
		else if(fabs(tmp-mi) < EPS){
			if(odis[p1]+odis[p2]+odis[p3]+odis[p4] < odis[o1]+odis[o2]+odis[o3]+odis[o4]){
				o1 = p1;o2 = p2;o3 = p3;o4 = p4;
			}
		}
}
int main(){
		int cas;
		scanf("%d",&cas);
		for(int kcas = 1; kcas <= cas; ++kcas){
				o.input();
				scanf("%d",&n);
				n = 4*n;
				for(int i = 0; i < n; ++i)ps[i].input();
				for(int i = 0; i < n; ++i){
						odis[i] = pdis(o,ps[i]);
						for(int j = 0; j < n; ++j){
								ppdis[i][j] = pdis(ps[i],ps[j]);
						}
				}
				for(int i = 0; i < n; ++i){
						int cnt = 0;
						for(int j = 0; j < n; ++j){
								if(i == j)continue;
								mindis[i][cnt] = j;
								minodis[i][cnt++] = j;
						}
						si = i;ssi = i;
						sort(mindis[i],mindis[i]+cnt,cmp1);
						sort(minodis[i],minodis[i]+cnt,cmp2);
				}
				ans = 0.0;
				memset(flag,0,sizeof(flag));
				int tmpn = n/4;
				while(tmpn --){
					mi = 1e100;
					for(int i = 0; i < n; ++i){
						if(flag[i])continue;
						for(int j = 0; j < n; ++j){
								if(i == j)continue;
								if(flag[j])continue;
								int t = 0;
								while ((minodis[i][t] == i || minodis[i][t] == j ||flag[minodis[i][t]]))t++;
								int tmp1 = minodis[i][t];
								t++;
								while (minodis[i][t] == i || minodis[i][t] == j ||flag[minodis[i][t]])t++;
								int tmp12 = minodis[i][t];

								t = 0;
								while ((mindis[j][t] == i || mindis[j][t] == j || flag[mindis[j][t]]))t++;
								int tmp2 = mindis[j][t];
								t++;
								while (mindis[j][t] == i || mindis[j][t] == j || flag[mindis[j][t]])t++;
								int tmp22 = mindis[j][t];
								double tmp;
								if(tmp1 == tmp2){
										update(tmp12,i,j,tmp2);
										update(tmp1,i,j,tmp22);
										continue;
								}
								
								update(tmp1,i,j,tmp2);
						}
					}
					ans += mi;
					flag[o1] = flag[o2] = flag[o3] = flag[o4] = 1;
				//	printf("%d %d %d %d\n",o1,o2,o3,o4);
				}
				printf("Case #%d: ",kcas);
				printf("%.2lf\n",ans);
		}
		return 0;
}