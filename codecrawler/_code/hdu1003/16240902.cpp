#include <iostream>
using namespace std;

int main()
{
    int t,n,temp,pos1,pos2,max,now,x,i,j;
    cin>>t;
    for (i=1;i<=t;i++)
    {
        cin>>n>>temp;
        now=max=temp;
        pos1=pos2=x=1;
        for (j=2;j<=n;j++)
        {
            cin>>temp;
            if (now+temp<temp)
                now=temp,x=j;
            else
                now+=temp;
            if (now>max)
                max=now,pos1=x,pos2=j;
        }
        cout<<"Case "<<i<<":"<<endl<<max<<" "<<pos1<<" "<<pos2<<endl;
        if (i!=t)
            cout<<endl;
    }
    return 0;
}