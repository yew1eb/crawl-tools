#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int m;
    while(cin >>m && m){
        vector<int> Ni;
        int sum = 0;
        for(int i = 0;i < m;i++){
            int a;
            cin >>a;
            sum ^= a;
            Ni.push_back(a);
        }
        int count = 0;
        for(vector<int>::size_type i = 0;i < Ni.size();i++){
            int a;
            a = Ni[i]^sum;
            if(a < Ni[i])
                count++;
        }
        cout <<count <<endl;
    }
    return 0;
}