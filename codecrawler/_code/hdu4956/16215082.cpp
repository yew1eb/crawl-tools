#include <iostream>
using namespace std;

long long cal(long long l,long long r)//å¸¸è§æ¹æ³æ±åºé´åæ»¡è¶³æ¡ä»¶çæ°æå¤å°ä¸ª
{
    long long result=0;
    for(;l<=r;l++)
    {
        long long temp=l;
        int mul=1;
        int re=0;
        while(temp)
        {
            re+=mul*(temp%10);
            temp/=10;
            mul=(-mul);
        }
        if(re==3)
            result++;
    }
    return result;
}

long long re(long long l,long long r)
{
    return (r+8)/11-(l-1+8)/11;
}

int main()
{
    long long l,r,R;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        for(R=l;R<=r;R++)//ä»å°å°å¤§ï¼è¾åºæå°çé£ä¸ª
        {
            long long result=re(l,R);
            if(cal(l,R)!=result)
            {
                cout<<R<<endl;
                break;
            }
        }
        if(R>r)
            cout<<-1<<endl;
    }
    return 0;
}
