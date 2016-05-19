#include <CSTDIO>
#include <QUEUE>
using namespace std;

/*
hdu 3976
高斯消元
每个节点的流入电流等于流出电流
R = 总电势差/电流
列出方程：
u[i]代表节点i的电势
Σ((u[j]-u[i])/r[i][j]) + I = 0
I[0] = 1
I[n-1] = -1
*/
const int MAXN = 55;
const double _inf = 1e-9;
double a[MAXN][MAXN], x[MAXN]; // 方程左边的矩阵和等式右边的值， x存放最后结果
int equ, val;	// 方程数 未知数个数
inline double mabs(double _X){return _X<0?-_X:_X;}
int gauss()
{
	int i,j,k,col,max_r;
    for(k=0,col=0;k<equ&&col<val;k++,col++)
    {
        max_r=k;
        for(i=k+1;i<equ;i++)
		{
			if(mabs(a[i][col])>mabs(a[max_r][col]))
				max_r=i;
		}
		if(mabs(a[max_r][col])<_inf) return 0;
		if(k!=max_r)
		{
			for(j=col;j<val;j++)
				swap(a[k][j],a[max_r][j]);
			swap(x[k],x[max_r]);
		}
		x[k]/=a[k][col];
		for(j=col+1;j<val;j++)a[k][j]/=a[k][col];
		a[k][col]=1;
		for(i=0;i<equ;i++)
		{
			if(i!=k)
			{
				x[i]-=x[k]*a[i][k];
				for(j=col+1;j<val;j++)a[i][j]-=a[k][j]*a[i][col];
				a[i][col]=0;
			}
		}
    }
    return 1;
}

int n, m;
double data[MAXN][MAXN];
int main()   
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	int t, cs = 0;
	int i, j;
	double tmp;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		memset(data, 0, sizeof data);
		while (m--)
		{
			scanf("%d%d%lf", &i, &j, &tmp);
			--i, --j;
			data[i][j] = data[j][i] = tmp;
		}
		memset(a, 0, sizeof a);
		memset(x, 0, sizeof x);
		for (i = 0; i< n; ++i)
		{
			for (j = 0; j< n; ++j)
			{
				if (data[i][j])
				{
					a[i][j] += 1.0/data[i][j];
					a[i][i] -= 1.0/data[i][j];
				}
			}
		}
		x[0] = -1;
		x[n-1] = 1;
		equ = val = n;
		gauss();
		printf("Case #%d: %.2lf\n", ++cs, x[0]-x[n-1]);
	}
	return 0;
}
