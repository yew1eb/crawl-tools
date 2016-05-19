#include "stack"
#include "cstdio"
#include "iostream"
#include "cmath"
#include "set"
#include "sstream"
#include "cctype"
#include "string"
#include "cstring"
#include "algorithm"
#include "queue"
#include "map"
using namespace std;
#define LL long long
#define inf 0x7ffffff
#define pa pair<int,int>
#define pi 3.1415926535897932384626433832795028841971

const int M=55;

int main()
{
    double a,b,c,d;
    while(cin>>a>>b>>c>>d)
    {
        double p,s1,s2;
        p=log(a)/log(c);
        b=p*b;
        s1=b;s2=d;
        if(s1-s2<0.00001&&s1-s2>-0.00001)
           cout<<"=\n";
        else if(s1<s2)
           cout<<"<\n";
        else
           cout<<">\n";  
        
    }
    return 0;
    
    
}