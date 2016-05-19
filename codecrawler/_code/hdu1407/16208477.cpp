#include <iostream>
using namespace std;

int main()
{
    int x,y,z,n;

    while(cin >> n)
    {
        int flag = 0;
        for(x = 1;x<=100;x++)
        {
            for(y = x;y<=100;y++)
            {
                for(z = y;z<=100;z++)
                {
                    if(x*x + y*y + z*z == n)
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag)
                break;
            }
            if(flag)
                break;
        }
        cout << x << " " << y << " " << z <<endl;
    }

    return 0;
}
