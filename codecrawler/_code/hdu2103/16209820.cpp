#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int a[33];
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N,M;
        cin >> M >> N;
        for(int i = 0; i < N; ++i)
            cin >> a[i];
        int ans = 0,pos = -1,Num;
        for(int i = 0; i < M; ++i)
            if(a[i] == 1)
            {
                pos = i;
                break;
            }

        if(pos != -1)
        {
            Num = 1;
            for(int i = pos+1; i < N; ++i)
            {
                ans += Num;
                Num *= 2;
            }
        }
        else
        {
            Num = 1;
            for(int i = M; i < N; ++i)
            {
                ans += Num;
                Num *= 2;
            }
        }
        if(ans != 0)
            cout << ans << "0000 RMB" << endl;
        else
            cout << "0 RMB" << endl;
    }

    return 0;
}
