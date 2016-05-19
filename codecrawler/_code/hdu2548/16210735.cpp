#include<iostream>
using namespace std;

int main()
{
    int t;
    double a,b,c,d;

    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        printf("%.3lf\n",d/(a+b)*c);
    }
    return 0;
}
