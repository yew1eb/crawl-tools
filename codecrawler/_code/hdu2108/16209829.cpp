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
#define maxn 10001   
using namespace std;
int N;
int OK;
struct point {
    double x,y;
};
point A[maxn];
void input()
{
    OK=1;
    for(int i=1;i<=N;i++)
    {
        scanf("%lf%lf",&A[i].x,&A[i].y);
    }
}
void init()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
}
void solve()
{
    for(int i=1;i<=N;i++)
    {
        int j=i-1;int k=i+1; 
        if(k==N+1) k=1;
        if(j==0) j=N;
        if(((A[i].x-A[j].x)*(A[k].y-A[j].y)-(A[k].x-A[j].x)*(A[i].y-A[j].y))<0) OK=0;
    }
}
int main()
{
    //init();
    while(cin>>N&&N)
    {
        input();
        solve();
        if(OK)
        cout<<"convex"<<endl;
        else cout<<"concave"<<endl;
    }
    return 0;
}
  
  
  
  
  
  
  
  
  
  
  