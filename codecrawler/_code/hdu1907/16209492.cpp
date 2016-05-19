#include <iostream>
using namespace std;

int main()
{
    int T,N,i,A[50],sum,k;
    cin>>T;
    while (T--)
    {
        cin>>N;            
        sum=0;k=0;
        for (i=0;i<N;i++)
        {
            cin>>A[i];
            sum^=A[i];
            if (A[i]>1)
            {
                k=1;
            }
        }        
        if (k==0)    //å¯¹äºæ¯å é½æ¯1çæåµä¸
        {
            if (N%2==0)
            {
                cout<<"John"<<endl;
            }
            else
            {
                cout<<"Brother"<<endl;
            }
        }
        else
        {
            if (sum==0)   //å¯¹äºå¥å¼å±å¿çæåµä¸
            {
                cout<<"Brother"<<endl;
            }
            else          //å¯¹äºéå¥å¼å±å¿çæåµä¸
            {
                cout<<"John"<<endl;
            }
        }
    }
    return 0;
}