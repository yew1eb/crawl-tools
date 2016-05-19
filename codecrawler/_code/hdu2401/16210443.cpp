#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int N,w,d,all;
    while(cin >> N >> w >> d >> all)
    {
        if((N-1)*N/2*w - all == 0)
            cout << N << endl;
        else
            cout << ((N-1)*N/2*w - all)/d << endl;
    }

    return 0;
}
