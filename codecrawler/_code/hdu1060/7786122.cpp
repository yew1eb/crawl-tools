#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    double m;
    int T;
    cin>>T;
    while(T--){
        while(cin>>n){
            m = n*log10(n*1.0);
            m -=(long long )m;
            cout<<(int)pow(10.0,m)<<endl; 
        }
    }
    return 0;
}
/*
m = n^n;
Á½±ßÈ¡¶ÔÊý logm = n*logn;
½«m·Ö³É10^x*y;
Ôò½á¹ûÎª10^(logy) 
*/