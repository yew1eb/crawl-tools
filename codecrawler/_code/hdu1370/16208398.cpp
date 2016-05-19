#include <iostream>
using namespace std;
int exgcd(int a,int b,int &x,int &y)
{
    if(a==0)
    {
        x=0;
        y=1;
        return b;
    }
    int g = exgcd(b%a,a,x,y);
    int tem = y;
    y=x;
    x=tem-(b/a)*y;
    return g;
}
int inv(int a,int n)//æ±éå
{
    int x,y;
    exgcd(a,n,x,y);
    return (x%n+n)%n;
}
int main()
{
    int N,P,E,I,D,ans;
    const int m1=23,m2=28,m3=33,M1=28*33,M2=23*33,M3=23*28,m=23*28*33;
    const int M11 = inv(M1,m1),M22 = inv(M2,m2),M33 = inv(M3,m3);//æ±miçéå 
    scanf("%d",&N);
    while(scanf("%d%d%d%d",&P,&E,&I,&D)!=EOF)
    {
        if(P==-1&&E==-1&&I==-1&&D==-1)break;
        //a[i]*(mi*mi(é)mod ni)å ä¸ºå¨æ±éåçæ¶åå·²ç»mod niäº 
        //(mi*mi(é)mod ni)æ¯ci 
        ans = (P*M1*M11 + E*M2*M22 + I*M3*M33)%m;
        ans -= D;
        if(ans<=0) ans+=m;
        printf("Case %d: the next triple peak occurs in %d days.\n",N++,ans);
        //cout<<"Case "<<N++<<": the next triple peak occurs in "<<i<<" days.\n";
    }
    return 0;
}
