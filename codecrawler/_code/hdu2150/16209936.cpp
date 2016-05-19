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
using namespace std;
struct point{
    long long x,y;
};
int OK=1;
long long crossdet(long long x1,long long y1,long long x2,long long y2)
{
    return x1*y2-x2*y1;
}
long long cross(point a,point b,point c)
{
    return crossdet(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}
long long dotdet(long long x1,long long y1,long long x2,long long y2)
{
    return x1*x2+y1*y2;
}
long long dot(point a,point b,point c)
{
    return dotdet(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}
point A[40][110];
int N;
int K[40];
void input()
{
    OK=1;
    for(int i=1;i<=N;i++)
    {
        cin>>K[i];
        for(int j=1;j<=K[i];j++)
        {
            scanf("%I64d%I64d",&A[i][j].x,&A[i][j].y);
        }
    }
}
int pan(point &s1,point &e1,point &s2,point &e2)
{
    //è·¨ç«å®éª
    long long a1=cross(s1,e1,s2);                //s1-e1 s2 
    long long a2=cross(s1,e1,e2);                //s1-e1 e2
    long long a3=cross(s2,e2,s1);                 //s2-e2 s1
    long long a4=cross(s2,e2,e1);               //s2-e2 s2
    if(a1*a2<0&&a3*a4<0)   return 1;    //åå¨ä¸¤ç«¯
    if((a1==0&&dot(s2,s1,e1)<0)||
       (a2==0&&dot(e2,s1,e1)<0)||
       (a3==0&&dot(s1,s2,e2)<0)||
       (a4==0&&dot(e1,s2,e2)<0))
       return 1;
    return 0; 
}
int solve()
{
    for(int i=1;i<=N;i++)
     for(int j=i+1;j<=N;j++)
       for(int k=1;k<=K[i]-1;k++)
        for(int t=1;t<=K[j]-1;t++)
        {
            if(pan(A[i][k],A[i][k+1],A[j][t],A[j][t+1])==1) {OK=0;return 0;}
        }
}
void init()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout); 
}
int main()
{
//    init();
    while(cin>>N)
    {
        input();
        solve();
        if(OK) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
  