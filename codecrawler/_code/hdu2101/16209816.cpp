#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int A,B;
    while(cin >> A >> B)
    {
        if((A+B)%86)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }

    return 0;
}
