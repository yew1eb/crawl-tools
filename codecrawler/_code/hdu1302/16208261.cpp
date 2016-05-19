#include <iostream>
#include <string>
using namespace std;
int main()
{
    double high,up,down,factor;
    while(cin>>high>>up>>down>>factor)
    {
        bool succ=0,fail=0;
        int needday=1;
        double nowpos=0;
        double rate=up*(factor/100.0);
        if(high==0)
            break;
        while(nowpos<=high && nowpos>=0)
        {
            if(up>0)
                nowpos+=up;
            if(nowpos>high)
            {
                succ=1;
                break;
            }
            nowpos-=down;
            up-=rate;
            if(nowpos<0)
            {
                fail=1;
                break;
            }
            needday++;
        }
        if(fail==1)
        {
            cout<<"failure on day "<<needday<<endl;
        }
        else if(succ==1)
        {
            cout<<"success on day "<<needday<<endl;
        }
        
    }
    
    
    
    return 0;
}
