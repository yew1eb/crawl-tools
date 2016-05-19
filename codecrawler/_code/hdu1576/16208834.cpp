#include<iostream>
using namespace std;

const int MOD=9973;

void extendGcd(int a,int b,int &x,int &y)   //æ©å±gcdï¼å¯ä»¥æ±åºgcd(a,b)ä»¥åax+by=gcd(a,b)ä¸­x,yçå¼
{
    if(b==0)
    {
        x=1;
        y=0;

        return;
    }
    else
    {
        extendGcd(b,a%b,x,y);
        
        int tmp=x;
        x=y;
        y=tmp-a/b*y;
    }
}
        
int main()
{
    int t,n,b,x,y,tmp;

    cin>>t;
    while(t--)
    {
        cin>>n>>b;

        extendGcd(b,MOD,x,y);  //è§£åºbx+9973y=1çx

        x*=n;   //æ­¤æ¶çxä¸ºbx1-9973y1=nä¸­çè§£x1äº

        tmp=(x%MOD+MOD)%MOD;   //é²æ­¢xä¸ºè´ï¼æé¢æxå¿ä¸ºæ­£æ°

        cout<<tmp<<endl;
    }

    return 0;
}
