#include<iostream>
#include<cstring>
using namespace std;
int num[10000+5];
int main()
{
    int n,m;
    while(cin>>n>>m&&n&&m)
    {
        memset(num,0,sizeof(num));
        //int a[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x;
                cin>>x;
                num[x]++;
            }
        }
        int zui=0,second=0;
        for(int i=1;i<=10000;i++)
        {
            if(num[i]>=zui) {zui=num[i];}
        }
        for(int i=1;i<=10000;i++)
        {
            if(num[i]>second&&num[i]<zui) second=num[i];
        }
        //cout<<zui<<' '<<second<<endl;
        int i;
        for( i=1;i<=10000;i++)
        {
            if(num[i]==second){cout<<i;break;}
        }
        for(int j=i+1;j<=10000;j++)
        {
            if(num[j]==second) cout<<' '<<j;
        }
        cout<<endl;    
    }
    return 0;
} 