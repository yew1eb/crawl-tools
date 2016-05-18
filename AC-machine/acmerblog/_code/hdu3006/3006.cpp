#include <iostream>
#include <cstring>

using namespace std;


int main()
{
    int m,n,k,a;
    int s[1<<15];            //2的15次方
    while(cin>>n>>m)
    {
        int ans=0;
        memset(s,0,sizeof(s));
        while(n--)
        {
            int set=0;
            cin>>k;
            while(k--)
            {
                cin>>a;
                set=set|(1<<(a-1));
            }
            s[set]=1;
            for(int j=0;j<=(1<<14);j++)
            {
                if(s[j])  s[set|j]=1;
            }

        }
        for(int i=0;i<=1<<14;i++)
        {
            if(s[i])
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}