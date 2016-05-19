#include<iostream>
using namespace std;

int a[1005];
struct NODE
{
    int l,r,gcd;
} GCD[1005];

int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);
}

int lcm(int x,int y)
{
    return x/gcd(x,y)*y;
}

int main()
{
    int T,N,Q,i,j,_gcd;
    bool ok;

    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        cin>>N>>Q;
        for(i=1;i<=N;i++) a[i]=1;
        for(i=0;i<Q;i++)
        {
            cin>>GCD[i].l>>GCD[i].r>>GCD[i].gcd;
            for(j=GCD[i].l;j<=GCD[i].r;j++)
                a[j]=lcm(a[j],GCD[i].gcd);      //æ±æå°å¬åæ°
        }
        ok=true;
        for(i=0;i<Q;i++)
        {
            _gcd=a[GCD[i].l];
            for(j=GCD[i].l+1;j<=GCD[i].r;j++)
                _gcd=gcd(_gcd,a[j]);

            if(_gcd!=GCD[i].gcd)
            {
                ok=false;
                break;
            }
        }
        if(!ok)
            cout<<"Stupid BrotherK!"<<endl;
        else
        {
            for(i=1;i<N;i++)
                cout<<a[i]<<" "; 
            cout<<a[i]<<endl;
        }
    }
    return 0;
}
