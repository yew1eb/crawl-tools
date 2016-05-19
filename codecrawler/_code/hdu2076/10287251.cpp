#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int h,m,s;
    double x1,x2;
    int T;
    double n;
    cin>>T;
    while(T--)
    {
        cin>>h>>m>>s;
        h%=12;
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(0);
        x1= (h*3600.0+m*60.0+s*1.0)/120.0;
        x2=(m*60.0+s*1.0)/10.0;
         n=abs(x2-x1);
         if(n>180)
             cout<<(360-n-0.5)<<endl;
         else
             cout<<(n-0.5)<<endl;
    }
    return 0;
}