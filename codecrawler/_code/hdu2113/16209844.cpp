#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int N,ok = 1;
    while(cin >> N)
    {
        if(ok == 1)
            ok = 0;
        else
            cout << endl;
        int ans = 0;
        while(N)
        {
            if(!(N&1))
                ans += (N%10);
            N /= 10;
        }
        cout << ans << endl;
    }

    return 0;
}
