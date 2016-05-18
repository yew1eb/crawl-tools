#include <iostream>

#include <cmath>

using namespace std;

const double eps = 1e-8;

int main()

{

    int test, cas;

    double x1, y1, tx, ty, x, y;

    cin >> test;

    for (cas = 1; cas <= test; cas++)

    {

        cin >> x1 >> y1;

        x = x1; y = y1;

        do {

            tx = x;

            ty = y;

            x = x1 + sqrt(ty);

            y = y1 + sqrt(tx);

        } while (fabs(x - tx) > eps || fabs(y - ty) > eps);

        printf("Case %d: %.6f %.6f/n", cas, x, y);

    }

    return 0;

}