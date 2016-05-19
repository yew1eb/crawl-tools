#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    int T,N,flag;
    double C,S,Csum,CSsum;
    string s;
    cin >> T;
    while(T--)
    {
        getchar();
        cin >> N;
        flag = Csum = CSsum = 0;
        while(N--)
        {
            cin >> s >> C >> S;
            Csum += C;
            if(S < 60 && S >=0)
                flag = 1;
            CSsum += (C*S);
        }
        if(flag)
            cout << "Sorry!" << endl;
        else
            printf("%.2lf\n",CSsum/Csum);
        if(T)
            cout << endl;
    }

    return 0;
}
