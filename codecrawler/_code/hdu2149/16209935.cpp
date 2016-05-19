/*1.å¯éæ­¥æ°ä¸º1-mçè¿ç»­æ´æ°ï¼ç´æ¥åæ¨¡å³å¯ï¼SG(x) = x % (m+1);*/
#include <iostream>
using namespace std;
int main()
{
    int m,n,i;
    while(cin>>m>>n)
    {
        int x=m%(n+1);
        if(m<=n)
        {
            for(i=m;i<=n;i++)
            {
                if(i!=m)cout<<' ';
                cout<<i;
            }
            cout<<endl;
        }
        else if(!x)cout<<"none"<<endl;
        else cout<<x<<endl;
    }
    return 0;
}