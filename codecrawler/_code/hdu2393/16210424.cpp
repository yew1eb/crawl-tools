#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int max(int a,int b)
{
    int T;
    if(a>b)
    {
        T=a;
        a=b;
        b=T;
    }
    return b;
}

int main()
{
    __int64 a[5];
    int cas;
    cin>>cas;
    int t=1;
    while(cas--)
    {
        cin>>a[1]>>a[2]>>a[3];
        cout<<"Scenario #"<<t<<":"<<endl;
        if(a[1]&&a[2]&&a[3])
        {
            sort(a+1,a+4);
         if(a[3]*a[3]==a[2]*a[2]+a[1]*a[1])
                cout<<"yes"<<endl<<endl;
          else
            cout<<"no"<<endl<<endl;
        }
        else
            cout<<"no"<<endl<<endl;

      t++;
    }

    return 0;
}
