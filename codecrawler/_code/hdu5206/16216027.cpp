#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define LL __int64
typedef long long ll;
#define PI 3.1415926
#define eps 1e-7
double dist(double a,double b,double c,double a1,double b1,double c1)
{
    return sqrt((a-a1)*(a-a1)+(b-b1)*(b-b1)+(c-c1)*(c-c1));
}
int main()
{
    int t,i,j,k,p;
    int Case=0;
    cin>>t;
    while(t--)
    {
        double x1[4];
        double x2[4];
        double x3[4];
        double x4[4];
        double x,y,z;
        cin>>x1[0]>>x1[1]>>x1[2]>>x2[0]>>x2[1]>>x2[2]>>x3[0]>>x3[1]>>x3[2]>>x4[0]>>x4[1]>>x4[2];
        int flag=0;
     //æä¸¾x1çä¸ç§é»ç¹æåµã
        if(((x1[0]-x3[0])*(x1[0]-x2[0])+(x1[1]-x3[1])*(x1[1]-x2[1])+(x1[2]-x3[2])*(x1[2]-x2[2]))==0&&dist(x1[0],x1[1],x1[2],x2[0],x2[1],x2[2])==dist(x1[0],x1[1],x1[2],x3[0],x3[1],x3[2]))
        {
            x=x2[0]+x3[0]-x1[0];
            y=x2[1]+x3[1]-x1[1];
            z=x2[2]+x3[2]-x1[2];
            if(x==x4[0]&&y==x4[1]&&z==x4[2])
                flag=1;
        }
        if(((x1[0]-x4[0])*(x1[0]-x2[0])+(x1[1]-x4[1])*(x1[1]-x2[1])+(x1[2]-x4[2])*(x1[2]-x2[2]))==0&&dist(x1[0],x1[1],x1[2],x2[0],x2[1],x2[2])==dist(x1[0],x1[1],x1[2],x4[0],x4[1],x4[2]))
        {
            x=x2[0]+x4[0]-x1[0];
            y=x2[1]+x4[1]-x1[1];
            z=x2[2]+x4[2]-x1[2];
            if(x==x3[0]&&y==x3[1]&&z==x3[2])
                flag=1;
        }
        if(((x1[0]-x4[0])*(x1[0]-x3[0])+(x1[1]-x4[1])*(x1[1]-x3[1])+(x1[2]-x4[2])*(x1[2]-x3[2]))==0&&dist(x1[0],x1[1],x1[2],x3[0],x3[1],x3[2])==dist(x1[0],x1[1],x1[2],x4[0],x4[1],x4[2]))
        {
            x=x3[0]+x4[0]-x1[0];
            y=x3[1]+x4[1]-x1[1];
            z=x3[2]+x4[2]-x1[2];
            if(x==x2[0]&&y==x2[1]&&z==x2[2])
                flag=1;
        }
        cout<<"Case #"<<++Case<<":"<<" ";
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
