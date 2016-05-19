#include<iostream>
using namespace std;
int plist[100001],pcount=0;
int prime(int n){
    int i;
    if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
        return 0;
    for (i=0;plist[i]*plist[i]<=n;i++)
        if (!(n%plist[i]))
            return 0;
    return n>1;
}
void initprime(){
    int i;
    for (plist[pcount++]=2,i=3;i<100000;i++)
        if (prime(i))
            plist[pcount++]=i;
}
__int64 _mode(__int64 a,__int64 m)
{
    __int64 ans=1,exp=m;
    while(exp)
    {        
        if(exp%2==1)
            ans=(ans*a)%m;
        a=(a*a)%m;
        exp=exp/2;
    }
    return ans;
}
int main()
{
    __int64 pp,a;
    int i,j;
    initprime();
    scanf("%I64d %I64d",&pp,&a);
    while(1)
    {
        if(pp==0 &&a==0)
            break;
        if(prime(pp)==1)
        {
            cout<<"no"<<endl;            
        }
        else
        {
            if(_mode(a,pp)==a)
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;    
        }
        scanf("%I64d %I64d",&pp,&a);
    }
    return 0;
}