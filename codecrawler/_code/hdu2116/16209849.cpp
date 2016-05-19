#include<iostream>
using namespace std;
int main()
{
    int K; 
    while(cin>>K)
    {
        __int64 a,b,max=1;
        scanf("%I64d%I64d",&a,&b);
        if (K==64)max=0x7fffffffffffffff;
        else max=(max<<(K-1))-1;
        if(((a>0&&b>0)&&(max-a<b))||((a<0&&b<0)&&(-max-1-a>b)))cout<<"Yes"<<endl;
        else cout<<"WaHaHa"<<endl;
    }
    return 0;
}