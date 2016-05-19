#include <iostream>
using namespace std;

int main()
{
    int a,b,t,i,max;
    while(cin >> a >> b)
    {
        cout << a << " " << b << " ";
        if(a>b)//å¤§å°ä¸ç¡®å®
        {
            t = a;
            a = b;
            b = t;
        }
        max = 0;
        for(i = a; i<=b; i++)
        {
            int n = i, sum = 1;
            while(n-1)//ç­äº1æ¶å°±ç»æ
            {
                if(n%2)
                    n = 3*n+1;
                else
                    n = n/2;
                sum++;
            }
            if(sum>max)
            max = sum;
        }
        cout << max << endl;
    }

    return 0;
}
