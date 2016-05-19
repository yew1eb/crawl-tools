/******************************************************
* author:xiefubao
*******************************************************/
#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string.h>
//freopen ("in.txt" , "r" , stdin);
using namespace std;

#define eps 1e-7
const double pi=acos(-1.0);
typedef long long LL;
const int Max=10100;
const int INF=1000000007;

double num[4];
int t;
double getarea(double a,double b,double c)
{
    double all=(a+b+c)/2.0;
    return sqrt(all*(all-a)*(all-b)*(all-c));
}
double solve(double a,double b,double c,double d)
{
    double left=max(b-a,d-c);
    double right=min(a+b,c+d);
    while(abs(right-left)>eps)
    {
        double mid=(right+left)/2.0;
        double midright=(mid+right)/2.0;
        if(getarea(a,b,mid)+getarea(c,d,mid)>getarea(a,b,midright)+getarea(c,d,midright))
            right=midright;
        else
            left=mid;
    }
    return getarea(a,b,left)+getarea(c,d,left);
}
int main()
{
    cin>>t;
    int  kk=1;
    while(t--)
    {
        for(int i=0; i<4; i++)
            scanf("%lf",num+i);
        if(num[0]>=num[1]+num[2]+num[3]||num[1]>=num[0]+num[2]+num[3]||
                num[2]>=num[1]+num[0]+num[3]||num[3]>=num[1]+num[2]+num[0])
        {
            printf("Case %d: -1\n",kk++);
            continue;
        }
        double ans=0;
        sort(num,num+4);
        ans=max(ans,solve(num[0],num[1],num[2],num[3]));
        ans=max(ans,solve(num[0],num[2],num[1],num[3]));
        ans=max(ans,solve(num[0],num[3],num[1],num[2]));
        printf("Case %d: %.6lf\n",kk++,ans);

    }
    return 0;
}
