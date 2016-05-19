#include <cstdio>  
#include <cstdlib>  
#include <cmath>  
#include <cstring>  
#include <ctime>  
#include <algorithm>  
#include <iostream>
#include <sstream>
#include <string>
#define oo 0x13131313
#define maxn 1000000+10
using namespace std;
struct point{
    double x,y;
};
point A[maxn];
int N;
double ansX,ansY;
double Sarea;
void input()
{
    ansX=0;ansY=0;Sarea=0;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        scanf("%lf%lf",&A[i].x,&A[i].y);
    }
}
void init()
{
    freopen("a.in","r",stdin);
    freopen("a.out","W",stdout);
}
void get_Sarea()
{
    for(int i=1;i<=N;i++)
    {
        int j=i+1;
        if(j==N+1) j=1;
        Sarea+=(A[i].x*A[j].y-A[j].x*A[i].y)*0.5;
    }
}
void get_ansXansY()
{
    for(int i=1;i<=N;i++)
    {
        int j=i+1;
        if(j==N+1) j=1;
        double area=(A[i].x*A[j].y-A[j].x*A[i].y)*0.5;
        ansX+=area*(A[i].x+A[j].x); //  area*(A[i].x+A[j].x+0)/3 è´¨ç¹çéé  
        ansY+=area*(A[i].y+A[j].y);
    }
    ansX=ansX/(3*Sarea);    
    ansY=ansY/(3*Sarea);
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        input();
        get_Sarea();
        get_ansXansY();
        printf("%.2lf %.2lf\n",ansX,ansY);
    }
    return 0;
}
  