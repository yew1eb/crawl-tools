/*
 * Author: Gatevin
 * Created Time:  2014/8/24 11:54:43
 * File Name: hehe.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;
const double eps(1e-8);
typedef long long lint;

#define maxn 501

int n;
double dpA[maxn + 1][maxn + 1];
double dpB[maxn + 1][maxn + 1];

int d[] = {20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5};

int loop = 0;

int main()
{
    memset(dpA, 0, sizeof(dpA));
    memset(dpB, 0, sizeof(dpB));
    for(int i = 1; i <= maxn; i++)
    {
        dpA[0][i] = 1;
        dpB[i][0] = 1;
    }
    for(int i = 1; i <= maxn; i++)
    {
        for(int j = 1; j <= maxn; j++)
        {
            loop = 0;
            do
            {
                double a = 0;
                for(int k = 0; k < 20; k++)
                {
                    if(i >= d[k])
                        a += dpB[i - d[k]][j];
                    else
                        a += dpB[i][j];
                }
                dpA[i][j] = 1 - a / 20.;
                a = 0;
                for(int h = 0; h < 20; h++)
                {
                    double b = 0;
                    for(int k = -1; k <= 1; k++)
                    {
                        int tmp = (h + 20 + k) % 20;
                        if(j >= d[tmp])
                            b += dpA[i][j - d[tmp]];
                        else
                            b += dpA[i][j];
                    }
                    b = 1 - b / 3.;
                    a = max(a, b);
                }
                dpB[i][j] = a;
                loop++;
            }
            while((i < 20 || j < 20) && loop <= 70);
        }
    }
    while(scanf("%d", &n), n)
        printf("%.12f %.12f\n", dpA[n][n], dpB[n][n]);
    return 0;
}
