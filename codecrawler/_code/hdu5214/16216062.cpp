//èµç æ¯A 5214
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
     unsigned int left;
     unsigned int  right;
}N[10000005];
int main()
{
    unsigned int T,n,l,r,a,b,c,d;
    cin>>T;
    while(T--)
    {                             
        bool flag=false;
        cin>>n>>l>>r>>a>>b>>c>>d;
        unsigned int leftmin,rightmax;
        N[1].left=l,N[1].right=r;
        for(unsigned int i=2;i<=n;i++)
        {
            N[i].left=(N[i-1].left)*a+b;
            N[i].right=(N[i-1].right)*c+d;
        }
        if(N[1].left>N[1].right)
        swap(N[1].left,N[1].right);
         leftmin=N[1].right,rightmax=N[1].left;
        for( unsigned int i=2;i<=n;i++)
        {
              if(N[i].left>N[i].right)
            swap(N[i].left,N[i].right);
            
            leftmin=min(leftmin,N[i].right);
            rightmax=max(rightmax,N[i].left);
        }
        for(unsigned int i=1;i<=n;i++)
        {
            if(N[i].left>leftmin&&N[i].right<rightmax&&(N[i].left!=N[i].right))
            {
                flag=true;
                break;
            }
        }
        if(flag)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
        
    }
    return 0;
}