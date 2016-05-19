#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//æ©å±æ¬§å éå¾,è¿åaï¼bçgcdï¼æ±å¾xï¼yä½¿ax+by=d
int extend_gcd(int a,int b,int &x,int &y)
{
    int t,m;
    if((b==0)&&(a==0)) return -1;
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    else
    {
        m=extend_gcd(b,a%b,x,y);
        t=x;x=y;y=t-a/b*y;
    }
    return m;
}

int main(void)
{
    int a,b,x0,y0,c,d,x,y,t,s,sum,sum2,rx,ry,tx,ty;
    bool flag;
    while(cin>>a>>b>>c)
    {
        if(a==0&&b==0&&c==0)
            break;
        flag=false;
        if(a<b)
        {
            swap(a,b);
            flag=true;
        }
        d=extend_gcd(a,b,x0,y0);
        sum=sum2=1000000000;
        a/=d;
        b/=d;
        x=c/d*x0;
        y=c/d*y0;
        s=-x/b-1;
        t=y/a+1;
        for(int i=s;i<=t;++i)
        {
            if(abs(x+b*i)+abs(y-a*i)<sum||(abs(x+b*i)+abs(y-a*i)==sum&&a*abs(x+b*i)+b*abs(y-a*i)<sum2))
            {
                sum=abs(x+b*i)+abs(y-a*i);
                sum2=a*abs(x+b*i)+b*abs(y-a*i);
                rx=abs(x+b*i);
                ry=abs(y-a*i);
            }
        }
        if(flag)
            swap(rx,ry);
        cout<<rx<<" "<<ry<<endl;
    }
    return 0;
}
