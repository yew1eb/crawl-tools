#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
long long fun(long long n);
int main()
{

    long long n,i;
    long long  t;
    while (cin >> t)
    {

        for (i = 0; i < t; i++)
        {
            cin >> n;
            cout << fun(n + 1) << endl;
        }
    }
    return 0;
}

long long fun(long long n)
{

    if (n == 1)return 0;
    else
    {
        long long j = 1;
        while (1)
        {
            j *= 2;
            if (j >= n)break;
        }
        if (j == n)return 2 * fun(j / 2) + j / 2;
        else
        {
            j /= 2;
            return fun(j)+n-j+fun(n-j);
        }
    }
}
