#include<iostream>
#define max 2001
using namespace std;
long long c[max][max]={0}; 
void com()
{
    int i,j;
    for(i=0;i<max;i++)
    {
        c[i][0]=1;
    }
    c[1][1]=1;
    for(i=2;i<max;i++)
    {
        for(j=1;j<=i;j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
}
int f(int x)
{
    int re=1;
    for(int i=2;i<=x;i++)
      {
        re*=i;
    }
    return re;
}//æ±é¶ä¹
//c[m][n]ä¸ºmånçå¼
int main()
{
    com();
    int t ;
    cin>>t;
    while(t--)
    {
        string a;
        int b,d;
        cin>>a>>b>>d;
        if(a[0]=='A')
        {
            cout<<c[b][d]*f(d)<<endl;
        }
        else if(a[0]=='C')
        {
            cout<<c[b][d]<<endl;
        }
    }
    return 0;
}