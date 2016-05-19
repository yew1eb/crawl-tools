#include <iostream>
using namespace std;
int test(int n,int hex){
    int sum=0;
    while(n){
        sum+=n%hex;
        n=n/hex;
    }
    return sum;
}
int main()
{
    int n;
    while(cin>>n&&n){
        if((test(n,10)==test(n,16))&&(test(n,12)==test(n,16)))
        cout<<n<<" is a Sky Number."<<endl;
        else cout<<n<<" is not a Sky Number."<<endl;
    }
    return 0;
}