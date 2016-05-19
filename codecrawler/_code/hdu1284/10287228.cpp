#include<iostream>
using namespace std;
int main()
{
    __int64 n,sum,i;
    while(cin>>n)
    {
        sum=0;
        for(i=0;3*i<=n;i++)
        {
            sum+=(n-i*3)/2+1;//ÏÈ°Ñ3·ÖµÄÓ²±Ò´Ó0¸öµ½×î¶à¸ö
        }
        cout<<sum<<endl;
    }
    return 0;
}