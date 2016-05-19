#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

const double PI=3.1415926;

int main()
{
    double R,v1,v2;
    while(cin>>R>>v1>>v2)
    {
        double r=(v1/v2)*1.0*R;//åå¿å
        double t1=(R-r)*1.0/v1;//åè¹çäººå°å²¸è¾¹çæ¶é´
        double t2=(PI*R)*1.0/v2;//è·ä¸ä¸ªååçæ¶é´
        if(t1<t2)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }


    return 0;

}
