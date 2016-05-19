#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int g,l,i,j,k,t,n,m,ans=1;
        cin>>g>>l;
        if(l%g!=0){cout<<0<<endl;continue;}//ä¸æç«æ¡ä»¶
        n=l/g;
        m=(int)sqrt(n+0.5);
        for(i=2;i<=m;i++)
        {
            if(n%i==0)
            {
                t=0;
                while(n%i==0)
                {
                    n=n/i;
                    t++;
                }
                ans*=(t+1)*(t+1)*(t+1)-2*t*t*t+(t-1)*(t-1)*(t-1);//å®¹æ¥åç
            }
        }
        if(n>1)
            ans*=6;//ææ°ä¸º1
        cout<<ans<<endl;
    }
    return 0;
}
