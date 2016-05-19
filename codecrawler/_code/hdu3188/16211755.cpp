#include <iostream>
using namespace std;

int main()
{
    int n,a,b,c;
    cin >> n;
    while(n--)
    {
        cin >> a >> b >> c;
        if(a+b > c && a+c > b && b+c > a)
        {
            if(a == b || b == c || a == c)
            cout << "perfect" << endl;
            else
            if(a*a+b*b==c*c || b*b+c*c==a*a || a*a+c*c==b*b )
            cout << "good" << endl;
            else
            cout << "just a triangle" << endl;
        }
    }

    return 0;
}


