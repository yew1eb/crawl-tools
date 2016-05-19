#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int n, a[100];
    while (cin >> n)
    {
        if (n == 0)  break;
        else
        {
            int count = 0, s1, s2, s3, s4, s5, s6;
            for (int i = 0; i < n; i ++)
            {
                cin >> a[i];
                s1 = a[i] / 100;
                s2 = (a[i] - s1 * 100) / 50;
                s3 = (a[i] - s1 * 100 - s2 * 50) / 10;
                s4 = (a[i] - s1 * 100 - s2 * 50 - s3 * 10) / 5;
                s5 = (a[i] - s1 * 100 - s2 * 50 - s3 * 10 - s4 * 5) / 2;
                s6 = a[i] - s1 * 100 - s2 * 50 - s3 * 10 - s4 * 5 - s5 * 2;
                count = count + s1 + s2 + s3 + s4 + s5 + s6;
            }
            
            cout << count << endl;
        }
    }
    
    return 0; 
}
