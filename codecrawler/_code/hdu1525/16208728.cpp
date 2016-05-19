#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int t,e[101];
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if(a==0&&b==0)break;
        if(a>b)swap(a,b);
        t=0;
        while(a!=0)
        {
            e[t++]=b/a;
            b=b%a;
            swap(a,b);
        }
        int num=0,i;
        for(i=0;i<t;i++)
        {
            if(e[i]>1)break;
            num++;
        }
        if(i==t)
        {
            if(t%2)cout<<"Stan wins"<<endl;
            else cout<<"Ollie wins"<<endl;
        }
        else
        {
            if(num%2==0)cout<<"Stan wins"<<endl;
            else cout<<"Ollie wins"<<endl;
        }
    }
    return 0;
}