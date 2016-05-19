#include <iostream>
using namespace std;

int main()
{
    int x,y,max_x,min_x,max_y,min_y;
    while(cin >> x >> y)
    {
        if(!x && !y)
            break;
        max_x = min_x = x;
        max_y = min_y = y;
        while(cin >> x >> y)
        {
            if(!x && !y)
                break;
            if(x>max_x)
                max_x = x;
            else if(x<min_x)
                min_x = x;
            if(y>max_y)
                max_y = y;
            else if(y<min_y)
                min_y = y;
        }
        cout << min_x << " " << min_y << " " << max_x << " " << max_y << endl;
    }

    return 0;
}
