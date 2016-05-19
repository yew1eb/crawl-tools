#include <iostream>
using namespace std;

int main()
{
    int n,a,b,max,sum,max_sum;
    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        max = a;
        max_sum = 0;
        for(int i = a;i<=b;i++)
        {
            sum = 0;
            for(int j = 1;j<=i/2;j++)
            {
                if(i%j==0)
                sum++; //æ±å å­ä¸ªæ°
            }
            if(i!=1)
            sum++;//ä¸æ¯1ï¼å ä¸èªèº«è¿ä¸ªå å­ï¼
            if(sum > max_sum)
            {
                max_sum = sum;
                max = i;//è®°å½å å­æ°æå¤§çæ°
            }
        }
        cout << max << endl;
    }

    return 0;
}
