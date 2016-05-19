/* THE PROGRAM IS MADE BY PYY */
/*----------------------------------------------------------------------------//

http://acm.hdu.edu.cn/showproblem.php?pid=2001

        计算两点间的距离

        Date  : 2011/2/27 Thursday
        Begin : 15:00
        End   : 15:18
//----------------------------------------------------------------------------*/

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
#define powerp(a, b) (abs(a - b)*abs(a - b))
using namespace std;
int main()
{
        double a, b, c, d;
        while (cin >> a >> b >> c >> d) {
                cout << setprecision(2) << fixed
                     << sqrt(powerp(a, c) + powerp(b, d))
                     << endl;
        }
        return 0;
}