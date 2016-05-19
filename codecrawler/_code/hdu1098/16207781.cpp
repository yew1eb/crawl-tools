#include<iostream>
#include<algorithm>
using namespace std;
int fun(int m,int n)
{
    int a=m;int b=n;int c;
    if(a>=b)
    {
        while(b)
        {
            c=a%b;a=b;b=c;
        }
        return a;
    }
    else 
    {
        while(a){
        c=b%a;b=a;a=c;
        }
        return b;
    }
}
int main()
{
    int m;
    while(cin>>m)
    {
        if(fun(65,m)==1)
        {
            for(int i=1;;i++)
            {
                if((i*65-18)%m==0)
                {cout<<(i*65-18)/m<<endl;break;}
            }
        }
        else cout<<"no"<<endl;
    }
}