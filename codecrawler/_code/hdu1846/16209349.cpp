#include<iostream>

using namespace std;

int main()
{
    int cCase;
    cin >>cCase;
    while(cCase--){
        int n,m;
        bool flag = true;
        cin >>n >>m;
        if(m >= n)
            flag = true;
        else if(n%(m+1))
            flag = true;
        else
            flag = false;
        if(flag)
            cout <<"first" <<endl;
        else
            cout <<"second" <<endl;
    }
    return 0;
}