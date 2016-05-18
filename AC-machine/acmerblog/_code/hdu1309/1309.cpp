#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;
int main()
{
    int n,i,j,t,k,m[101],l;
    double cost,sum,car,p[101],s;
    while(cin>>t>>cost>>sum>>k)
    {
        if(t<0)
            break;
        j=0;
        for(i=0;i<k;i++)
        {
            cin>>l>>s;
            if(i==0)
                p[j++]=s;
            else
            {
                while(j<l)
                {
                    p[j]=p[j-1];
                    j++;
                }
                p[j++]=s;
            }
        }
        while(j<=t) {
            p[j]=p[j-1];
            j++;
        }
        car=(sum+cost)*(1-p[0]);
        cost=sum/t;
        if(car>=sum)
        {
            cout<<"0 months"<<endl;
            continue;
        }
        j=1;
        for(i=1;i<=t;i++)
        {
            s=p[i];
            car*=(1-s);
            sum-=cost;
            if(car>=sum)
                break;
        }
        if(i==1)
            cout<<"1 month"<<endl;
        else cout<<i<<" months"<<endl;
    }
    return 0;
}