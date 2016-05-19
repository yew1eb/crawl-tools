#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double v,d,n;
    int i,t;
    while(cin >> v >> d)
    {
        t= 0;
        i = 1;
        n = v/d;
        while(1)
        {
            if(n>i)
            {
                n-=i;
                t+=(++i);
            }
            else
            {
                t+=ceil(n);//ä¸è¶³ä¹ç®ä¸ç§
                //æ°å­¦çä¸ä¸ªå½æ°ï¼åè½ï¼ å½æ°è¿ååæ°ä¸å°äºnum çæå°æ´æ°ã
                /*å¦,
                y = 6.04;
                x = ceil( y );
                xä¸º7.0. */
                break;
            }
        }
        cout << t << endl;
    }

    return 0;
}
