#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a,b,c,T;
    __int64 s,l;
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>c;
        l=1;
        s=a%c;
        while(b>1)
        {
            if(b%2==1)
            {
                b--;
                l*=s;
                l%=c;
            }
            else
            {
                s*=s;
                s%=c;
                b/=2;
            }
        }
        printf("%I64d\n",s*l%c);
    }
}
