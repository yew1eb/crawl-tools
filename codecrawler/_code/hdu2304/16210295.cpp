#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int T,N,d;
    cin >> T;
    while(T--)
    {
        cin >> N;
        int sum = 0;
        for(int i = 0; i < N; ++i)
        {
            cin >> d;
            if(i != N-1)
                sum += d-1;
            else
                sum += d;
        }
        cout << sum << endl;
    }

    return 0;
}
