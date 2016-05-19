#include<iostream>
#include<cmath>
#define ll long long 

using namespace std;

int t;
int n,ans;

bool Isprime(int m)
{
    int i,isqrt=(int)sqrt(m);
    bool pd=true;
    if(m==2)pd=true;
    else if(m%2==0)pd=false;
    else 
    for(i=3;i<=isqrt;i+=2){
        if(m%i==0){
            pd=false;
            break;
        }
    }
    return pd;
}

int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        if(n==4)ans=2;
        else if(Isprime(n))ans=n-1;
        else ans=0;
        cout<<ans<<endl;
    }
    return 0;
}
