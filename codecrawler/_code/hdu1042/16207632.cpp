/*ä¸è¿å¶*/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    void factorial(int n);  //é¶ä¹å½æ°

    int n;

    while(cin>>n)
        factorial(n);
    
    return 0;
}

void factorial(int n)
{
    int a[10001];  
    int places,carry,i,j;

    a[0]=1;
    places=0;   //å½åæ°çæ»ä½æ°
    for(i=1;i<=n;i++)
    {
        carry=0;   //è¿ä½

        for(j=0;j<=places;j++)
        {
            a[j]=a[j]*i+carry;
            carry=a[j]/10000;
            a[j]%=10000;
        }

        if(carry>0)  //å¦æä¸ä¸ªæ°çæ»åä¸ä½å¤§äºä¸ä¸ï¼åååè¿ä½
        {
            places++;
            a[places]=carry;
        }
    }    

    /*
      è¾åº
      æé«ä½åæ ·è¾åºï¼
      å¶ä»ä½å°äº1000çï¼é«ä½è¡¥0
    */
    cout<<a[places];
    for(i=places-1;i>=0;i--)
        cout<<setw(4)<<setfill('0')<<a[i];

    cout<<endl;
}
