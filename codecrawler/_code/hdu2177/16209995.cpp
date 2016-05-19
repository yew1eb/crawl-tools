#include<iostream>
#include<cmath>
using namespace std;
const double Grs = (sqrt(5.0)+1)/2;
const int N = 1000005;
int a;
int b;
int main()
{
    while(cin>>a>>b)
    {
        if(a==0&&b==0)
        break;
        if(a>b)
        {
            a=b^a;
            b=a^b;
            a=b^a;
        }
        if(a==(int)((Grs)*(b-a)))
        cout<<0<<endl;
        else           //äºåæ¾ä¸ä¸ä¸ªå¥å¼å±å¿
        {
            cout<<1<<endl;

            int tmp=(b-a)/2;
            int tm=a/2;
            int k1=0;int k2=a;
            int s1=0;int s2=b;
            if(a==b)
            {
                cout<<0<<' '<<0<<endl;
            }
            else
            while(k2>=k1+1)//åæ¾ç¸å
            {
                int cnt=(int)((Grs)*(b-a));
                if(a-tm==cnt)
                {
                    cout<<a-tm<<' '<<b-tm<<endl;
                    break;
                }
                else if(a-tm<cnt)//å¤§äº
                {
                    k2=tm;
                    tm=(k1+k2)/2;
                }
                else if(a-tm>cnt)//å°äº
                {
                    k1=tm;
                    tm=(k1+k2)/2;
                }
            }
            while(s2>=s1+1)   //  ä»bå ä¸­å ä¸båå®åæ¯aå¤§
            {
                int tt=(b-tmp)-a;
                int ans=(int)((Grs)*tt);
                if(a==ans)//æ¾å°
                {
                    cout<<a<<' '<<b-tmp<<endl;
                    break;
                }
                else if(a<ans) //å°äº
                {
                    s1=tmp;
                    tmp=(s1+s2)/2;
                }
                else if(a>ans)//å¤§äº
                {
                    s2=tmp;
                    tmp=(s1+s2)/2;
                }
            }
            s2=a;s1=0;
            b=a;tmp=b/2;
            while(s2>=s1)   //ä»bä¸­å   ä¸åå®åæ¯aå°
            {

                int ans=(int)((Grs)*(a-b+tmp));
                if(b-tmp==ans)
                {
                    cout<<b-tmp<<' '<<a<<endl;
                    break;
                }
                else if(b-tmp>ans)//å°äº
                {
                    s1=tmp;
                    tmp=(s1+s2)/2;
                }
                else if(b-tmp<ans) //å¤§äº
                {
                    s2=tmp;
                    tmp=(s1+s2)/2;
                }
            }
        }
    }
}
