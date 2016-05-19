#include <iostream>
using namespace std;
//计算a^bmodn
int modexp(int a,int b,int n)
{
    int ret=1;
    int tmp=a;
    while(b)
    {
       //基数存在
       if(b&0x1) ret=ret*tmp%n;
       tmp=tmp*tmp%n;
       b>>=1;
    }
    return ret;
}
int main()
{
    int Z,M,H,a,b,ans;
    cin >> Z;
    while(Z--)
    {
       ans=0;
       cin >> M >> H;
       while(H--)
       {
           cin >> a >> b;
           ans+=modexp(a%M,b,M);//我表示不懂这儿，是看别人写的，我觉得是（a1^b1+.....）%M=(a1^b1)%M+...为什么是（（a%M）^b）%M+....？求解释！
           //(a+b)%c=(a%c+b%c)%c
       }
       cout << ans%M << endl;
    }
    return 0;
}