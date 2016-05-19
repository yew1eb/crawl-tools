#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >>  n)
    {
        double a, b;
        double suma = 0, sumb = 0;
        while(n--)
        {
            cin >> a >> b;
            if(b != -1)
            {
                suma += a;
                if(b >= 90)
                    sumb += a * 4;
                else if(b >= 80)
                    sumb += a * 3;
                else if(b >= 70)
                    sumb += a * 2;
                else if(b >= 60)
                    sumb += a * 1;
            }
        }
        if(suma == 0)
            cout << "-1" << endl;
        else
            printf("%.2f\n", sumb * 1.0 / suma);
    }
    return 0;
}