#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int A,B;
    int a,b;
    while(n--){
        a=0;b=0;
        cin>>A>>B;
        for(int i=1;i<A;i++)
            if(A%i==0) a+=i;
        for(int i=1;i<B;i++)
            if(B%i==0) b+=i;
        if(A==b&&B==a) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}