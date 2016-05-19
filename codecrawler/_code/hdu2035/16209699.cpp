#include <iostream>
using namespace std;
int main()
{
    int A,B;
    int res;
    while(cin>>A>>B){
        res=1;
        if(A==0&&B==0) break;
        for(int i=0;i<B;i++)
            res=(res*A)%1000;
        cout<<res<<endl;
    } 
    return 0;
}