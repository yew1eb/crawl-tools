#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
using namespace std;
int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF)
    {

        if ((a == 4 && b == 5) || (a == 5 && b == 4))
        {
            if (a>b)
            {
                cout << "SECOND BIGGER" << endl;
            }
            else
                cout << "FIRST BIGGER" << endl;
            continue;
        }
        if ((a == 7 && b == 8) || (a == 8 && b == 7))
        {
            if (a>b)
            {
                cout << "SECOND BIGGER" << endl;
            }
            else
                cout << "FIRST BIGGER" << endl;
            continue;
        }
        if ((a == 15 && b == 16) || (a == 16 && b == 15))
        {
            if (a>b)
            {
                cout << "SECOND BIGGER" << endl;
            }
            else
                cout << "FIRST BIGGER" << endl;
            continue;
        }
        if ((a == 1 && b == 3) || (a == 3 && b == 1))
        {
            if (a>b)
            {
                cout << "SECOND BIGGER" << endl;
            }
            else
                cout << "FIRST BIGGER" << endl;
            continue;
        }
        if ((a == 12 && b == 13) || (a == 13 && b == 12))
        {
            if (a>b)
            {
                cout << "SECOND BIGGER" << endl;
            }
            else
                cout << "FIRST BIGGER" << endl;
            continue;
        }
        if ((a == 1 && b == 3) || (a == 3 && b == 1))
        {
            if (a>b)
            {
                cout << "SECOND BIGGER" << endl;
            }
            else
                cout << "FIRST BIGGER" << endl;
            continue;
        }
        if (a - b>=8 || b - a>=8)
        {
            if (a<b)
                cout << "FIRST BIGGER" << endl;
            else
                cout << "SECOND BIGGER" << endl;
        }
        else
        {
            if (a > b)
                cout << "FIRST BIGGER" << endl;
            else
                cout << "SECOND BIGGER" << endl;
        }
    }
    return 0;
}
