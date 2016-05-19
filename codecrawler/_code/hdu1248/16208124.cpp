/*ç»å°è´¹æå°ï¼ä¹°ä¸è¥¿è±è´¹æå¤å³å¯*/
#include<iostream>
using namespace std;

int main()
{
    int t,n;
    int a,b,c;

    cin>>t;
    while(t--)
    {
        cin>>n;

        a=n/150;
        b=n/200;
        c=n/350;

        int max=-1;
        int tem;
        for(int i=0;i<=a;i++)   //å®ç¾çæ´å
        {
            for(int j=0;j<=b;j++)
            {
                for(int k=0;k<=c;k++)
                {
                    tem=150*i+200*j+350*k;
                    if(max<tem && tem<=n)
                        max=tem;
                }
            }
        }

        cout<<n-max<<endl;
    }
    return 0;
}