#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <vector>
#include <math.h>
#include <string.h>
#include <queue>
#include <string>
#include <stdlib.h>
#include <algorithm>
//#define LL __int64
#define LL long long
#define eps 1e-9
#define PI acos(-1.0)
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 210;

double p[maxn];
double a[maxn][maxn];//增广矩阵
double X[maxn];//解集
int num[maxn];//给每个能给到达的point离散化
int n,m,x,y,d;
int equ,var,cnt;

bool Gauss()
{
    int row,col,max_r,i,j;
    row = 0;
    col = 0;
    while(row < equ && col < var)
    {
        max_r = row;
        for(i = row+1; i < equ; i++)
        {
            if(fabs(a[i][col]) > fabs(a[max_r][col]))
                max_r = i;
        }
        if(max_r != row)
        {
            for(j = col; j <= var; j++)
                swap(a[row][j], a[max_r][j]);
        }
        if(fabs(a[row][col]) < eps)
        {
            col++;
            continue;
        }
        for(i = row+1; i < equ; i++)
        {
            if(fabs(a[i][col]) < eps) continue;
            double t = a[i][col]/a[row][col];
            a[i][col] = 0.0;
            for(j = col+1; j <= var; j++)
                a[i][j] -= a[row][j]*t;
        }
        row++;
        col++;
    }

    for(i = row; i < equ; i++)
        if(fabs(a[i][var]) > eps)
            return false; //无解
    for(i = equ-1; i >= 0; i--)
    {
        if(fabs(a[i][i]) < eps) continue;
        double t = a[i][var];
        for(j = i+1; j < var; j++)
            t -= a[i][j]*X[j];
        X[i] = t/a[i][i];
    }
    return true;
}

void bfs(int s) //bfs找出所有能够到达的点并离散化
{
    queue <int> que;
    que.push(s);
    num[s] = cnt++;
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        for(int i = 1; i <= m; i++)
        {
            if(fabs(p[i]) < eps)
                continue;
            int v = (u+i)%n;
            if(num[v] == -1)
            {
                num[v] = cnt++;
                que.push(v);
            }
        }
    }
}

int main()
{
	int test;
	scanf("%d",&test);
	for(int item = 1; item <= test; item++)
	{
		scanf("%d %d %d %d %d",&n,&m,&y,&x,&d);
		for(int i = 1; i <= m; i++)
		{
			scanf("%lf",&p[i]);
			p[i] /= 100;
		}
		if(x == y)
		{
			printf("0.00\n");
			continue;
		}
		n = 2*(n-1);
		if(d == 1)
            x = n-x;
		memset(num,-1,sizeof(num));
		cnt = 0;
		bfs(x);
		if(num[y] == -1 && num[n-y] == -1) //注意这里是 &&，只有当两个方向都走不到才算走不到
		{
		    printf("Impossible !\n");
		    continue;
		}

		memset(a,0,sizeof(a));
		memset(X,0,sizeof(X));
		equ = var = cnt;

		for(int i = 0; i < n; i++)
		{
		    if(num[i] != -1)
		    {
		        if(i == y || i == n-y) //注意特判终点
                {
                    a[num[i]][num[i]] = 1;
                    a[num[i]][cnt] = 0;
                    continue;
                }
		        a[num[i]][num[i]] = 1;
		        for(int j = 1; j <= m; j++)
		        {
		            int t = (i+j)%n;
		            if(num[t] != -1)
                        a[num[i]][num[t]] -= p[j];
                    a[num[i]][cnt] += j*p[j];
		        }
		    }
		}
		if(Gauss())
            printf("%.2lf\n",X[num[x]]);
        else printf("Impossible !\n");
	}
	return 0;
}
