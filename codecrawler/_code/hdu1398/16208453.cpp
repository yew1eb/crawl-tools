#include<iostream>
using namespace std;
const int lmax=300;
int c1[lmax+1],c2[lmax+1];
int main()
{
    int n,i,j,k;
    int elem[17]={1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289};
    while(cin>>n && n!=0)
    {
        for(i=0;i<=n;i++)
        {
            c1[i]=1;
            c2[i]=0;
        }
        for(i=2;i<=17;i++)
        {
            for(j=0;j<=n;j++)
                for(k=0;k+j<=n;k+=elem[i-1])
                    c2[j+k]+=c1[j];
            for(j=0;j<=n;j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        cout<<c1[n]<<endl;
    }
    return 0;
}