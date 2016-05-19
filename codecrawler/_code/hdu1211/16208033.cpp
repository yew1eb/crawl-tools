#include<iostream>
#include<cmath>
using namespace std;
int p,q,e,l;
__int64 n;
__int64 mul(int a,int b)
{
    __int64 sum;
    if(b==0)
        return 1;
    if(b==1)
        return a%n;
    else
    {
        __int64 t=mul(a,b/2)%n;

            sum=t%n*t%n;

        if(b%2==1)
            sum=sum*a%n;
    }
    return sum;
}

int main()
{
    
    int i,j;
    int a;
    __int64 temp;
    int ans;    
    while(cin>>p>>q>>e>>l)
    {
        n=p*q;

        for(i=0;i<l;i++)
        {
            cin>>a;
            for(j=0;j<=200;j++)
            {
                temp=mul(j,e);
                
        
                if(temp==a)
                {
                    ans=j;
                    break;
                }
            }
            printf("%c",ans);
        }
        printf("\n");

    }
    return 0;

}