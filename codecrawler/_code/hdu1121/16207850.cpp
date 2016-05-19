#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long a[105][105];

bool cha(int i,int s)
{
    for(int j=0;j<s-i;j++)
        if(a[i][j]!=a[i][0])
            return false;
    return true;
}

int main()
{
    int kase;
    cin>>kase;
    while(kase--)
    {
        memset(a,0,sizeof(a));
        int s,c;
        cin>>s>>c;
        for(int j=0;j<s;j++)
            scanf("%lld",&a[0][j]);
        int degree=0;
        int i=0,j=0;
        while(true)
        {
            i++;
            for(int j=0;j<s-i;j++)
                a[i][j]=a[i-1][j+1]-a[i-1][j];
            if(cha(i,s))
            {
                break;
            }
        }
        int t=i;
        /*for(int i=0;i<=t;i++)
        {
            for(int j=0;j<s-i;j++)
            cout<<a[i][j]<<' ';
            cout<<endl;
        }*/
/*
1 2 7 19
1 5 12
4 7
3
*/
        for(int j=0;j<s+c;j++)
            a[s+c-1][j]=a[s+c-1][0];
        for(int i=s+c-2;i>=0;i--)
            for(int j=1;j<s+c;j++)
                a[i][j]=a[i][j-1]+a[i+1][j-1];
        /*for(int i=0;i<=t;i++)
        {
            for(int j=0;j<s+c;j++)
            cout<<a[i][j]<<' ';
            cout<<endl;
        }*/
/*
1 2 7 19 41 76 127
1 5 12 22 35 51 70
4 7 10 13 16 19 22
3 3 3 3 3 3 3
*/
        printf("%lld",a[0][s]);
        for(int j=s+1;j<s+c;j++)
            printf(" %lld",a[0][j]);
        printf("\n");
    }
    return 0;
}
