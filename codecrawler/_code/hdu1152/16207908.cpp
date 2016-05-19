#include<cstdio>
#include<iostream>
#include<fstream>
using namespace std;
int x[100001],y[100001];
int main()
{
    int n;
    //fstream cin("d:\\test.txt");
    while(cin>>n && n)
    {
        int i,t,sum1=0,sum2=0,xx,yy;
        for(i=0;i<(n+1)/2;++i)
            cin>>x[i]>>y[i];
        t=(n+1)/2-1;
        for(i=0;i<(n+1)/2-1;++i)
        {
            if(x[i]<x[t])
            {
                if(y[i]>y[t])
                    sum2++;
                else if(y[i]<y[t])
                    sum1++;
            }
            else if(x[i]>x[t])
            {
                if(y[i]>y[t])
                    sum1++;
                else if(y[i]<y[t])
                    sum2++;
            }
        }
        for(i=(n+1)/2;i<n;++i)
        {
            cin>>xx>>yy;
            if(xx<x[t])
            {
                if(yy>y[t])
                    sum2++;
                else if(yy<y[t])
                    sum1++;
            }
            else if(xx>x[t])
            {
                if(yy>y[t])
                    sum1++;
                else if(yy<y[t])
                    sum2++;
            }
        }
        cout<<sum1<<" "<<sum2<<endl;
    }
    return 0;
}
