#include <iostream>

using namespace std;

int n,m,a,b;
int flag;

int main()
{
    while(cin >> n >> m)
    {
        flag = false;
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            cin >> a >> b;
            if(a > b)
                ans ^= a - b - 1;
            else
                ans ^= b - a - 1;
            //if(a - b != 1 && b - a != 1)
                //flag = !flag;
        }
        if(ans)
            cout << "I WIN!" << endl;
        else
            cout << "BAD LUCK!" << endl;
    }
    return 0;
}