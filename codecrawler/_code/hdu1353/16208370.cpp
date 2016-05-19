#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 150
using namespace std;
#define eps 0.000000001

int main()
{
    double v;
    double a,b,c,d;
    while(~scanf("%lf%lf%lf%lf%lf",&v,&a,&b,&c,&d))
    {
        int num1,num2,num3,num4;
        int ff=0;

        for(int i=0;i<=a;i++)
        {
            for(int j=0;j<=b;j++)
            {
                for(int k=0;k<=c;k++)
                {
                    for(int m=0;m<=d;m++)
                    {
                        if(fabs(v-(0.25*i+0.1*j+0.05*k+0.01*m))<=eps)
                        {
                            num1=m;
                            num2=k;
                            num3=j;
                            num4=i;
                            ff=1;
                            break;
                        }
                    }
                }
            }
        }

        if(ff)
        cout<<num4<<" "<<num3<<" "<<num2<<" "<<num1<<endl;
        else
        cout<<"NO EXACT CHANGE"<<endl;

    }
    return 0;
}
