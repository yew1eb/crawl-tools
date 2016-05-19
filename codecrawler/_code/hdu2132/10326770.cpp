#include<iostream>
const int MAX=100001;
__int64 s[MAX];
using namespace std;
int main()
{
    __int64 n,m,i,j;
        s[0]=0;
        for(i=1;i<MAX;i++)
        {
            if(i%3==0)
            s[i]=s[i-1]+i*i*i;
            else
            s[i]=s[i-1]+i;
        }
        while(cin>>n&&n>=0)
        {cout<<s[n]<<endl;}
    return 0;
}