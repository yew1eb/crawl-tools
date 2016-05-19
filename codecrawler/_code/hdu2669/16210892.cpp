#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef __int64 LL;
LL extend_gcd(LL a,LL b,LL &x,LL &y)
{
    if(a == 0 && b == 0) return -1; //æ æå¤§å¬å å­
    if(b == 0)
    {
        x = 1; y = 0;
        return a;
    }
    LL d = extend_gcd(b,a%b,y,x);
    y -= (a/b)*x;
    return d;
}

int main()
{    
    LL a,b;
    while(cin>>a>>b)
    {
        LL x,y,d;
        d = extend_gcd(a,b,x,y);
        if(d == 1)
        {
            while(x < 0)
            {
                x += b/d;
                y -= a/d;
            }
            cout<<x<<' '<<y<<endl;
        }
        else
            cout<<"sorry"<<endl;
    }
    return 0;
}