#include  <iostream>
using namespace std;

int main()
{
    int a, b, k;
    while(cin >> a >> b >> k, a || b)
    {
        if(a == b)
        {
            cout << "-1" << endl;
            continue;
        }
        if(k >=5)
        {
            cout << a + b << endl;
            continue;
        }
        char str1[10], str2[10];
        int x = a;
        int y = b;
        x += 10000;
        y += 10000;
        itoa(x, str1, 10);
        itoa(y, str2, 10);
        int flag = 0;
        for(int i = 0; i < k; i++)
        {
            if(str1[4-i] != str2[4-i])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            cout << a + b << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}