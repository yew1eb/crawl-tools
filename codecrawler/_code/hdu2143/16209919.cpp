#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    __int64 A,B,C;
    while(cin >> A >> B >> C)
    {
        int flag = 0;
        if(A+B==C || A+C==B || B+C==A)
            flag = 1;
        if(A*B==C || A*C==B || B*C==A)
            flag = 1;
        if((B!=0 && (A%B==C || C%B==A)) || (C!=0 && (B%C==A || A%C==B)) || (A!=0 && (C%A==B || B%A==C)))
            flag = 1;
        if(flag)
            cout << "oh,lucky!" << endl;
        else
            cout << "what a pity!" << endl;
    }

    return 0;
}
