#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.1415926;

int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        double x, y;
        cin >> x >> y;
        double d = x * x + y * y ;
        double s = 0.5 * PI * d;
        int year = ceil(s / 50.0);
        printf("Property %d: This property will begin eroding in year %d.\n", i, year);
        if(i == t)
            printf("END OF OUTPUT.\n");
    }
    return 0;
}