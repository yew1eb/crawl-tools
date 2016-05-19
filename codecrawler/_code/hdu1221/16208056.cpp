#include<iostream>
#include<cmath>
using namespace std;

bool xiao(double x1,double x2)
{
    if(x1-x2<1e-8)
        return true;
    else false;
}

int main()
{
    int num;
    double x,y,r,x1,y1,x2,y2;
    double zx1,zy1,zx2,zy2;
    cin>>num;
    for(int ii=0;ii<num;ii++)
    {
        cin>>x>>y>>r>>zx1>>zy1>>zx2>>zy2;
        x1=zx1<zx2?zx1:zx2;
        x2=zx1<zx2?zx2:zx1;
        y1=zy1<zy2?zy1:zy2;
        y2=zy1<zy2?zy2:zy1;
        double rP=r*r;

        bool flag=false;
        if(rP-(x1-x)*(x1-x)>=0)  //å·¦é¢
        {
            double  kai=sqrt(rP-(x1-x)*(x1-x));
            double t1=kai+y;
            double t2=0-kai+y;
            if((t1<=y2&&t1>=y1)||(t2<=y2&&t2>=y1))
                flag=true;
        }
        if(flag==false&&rP-(x2-x)*(x2-x)>=0) //å³é¢
        {
            double  kai=sqrt(rP-(x2-x)*(x2-x));
            double t1=kai+y;
            double t2=0-kai+y;
            if((t1<=y2&&t1>=y1)||(t2<=y2&&t2>=y1))
                flag=true;
        }

        if(flag==false&&rP-(y1-y)*(y1-y)>=0) //ä¸é¢
        {
            double  kai=sqrt(rP-(y1-y)*(y1-y));
            double t1=kai+x;
            double t2=0-kai+x;
            if((t1<=x2&&t1>=x1)||(t2<=x2&&t2>=x1))
                flag=true;
        }

        if(flag==false&&rP-(y2-y)*(y2-y)>=0)  //ä¸é¢
        {
            double  kai=sqrt(rP-(y2-y)*(y2-y));
            double t1=kai+x;
            double t2=0-kai+x;
            if((t1<=x2&&t1>=x1)||(t2<=x2&&t2>=x1))
                flag=true;
        }

        if(flag)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}