#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
const int mod=1e9+7;
int f[100010];
void init()
{
    f[0]=1;
    int i,j,k,flag=1;
    for(i=1;i<=100000;i++)
    {
        f[i]=0;
        for(j=1;;j++)
        {
            int t=i-j*(3*j-1)/2;
            int tt=i-j*(3*j+1)/2;
            if(j&1)
                flag=1;
            else
                flag=-1;
            if(t<0&&tt<0)
                break;
            if(t>=0)
                f[i]=(f[i]+flag*f[t])%mod;
            if(tt>=0)
                f[i]=(f[i]+flag*f[tt])%mod;
        }
        f[i]=(f[i]+mod)%mod;
    }
}
int main()
{
    init();
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        cout<<f[n]<<endl;
    }
    return 0;
}
/*
é¢æï¼å°næåæå¤ä¸ªæ­£æ´æ°ä¹åï¼é®æå¤å°ç§ææ³ï¼
å¦5=1+1+1+1+1=1+1+1+2=1+1+3=1+4=5=1+2+2=2+3.å±7ç§

Input:
2
100000
99999

Output:
49037875 
677525748

æ¹æ³ï¼
ç´æ¥å¬å¼ï¼f[n]=â(-1)^(k-1)*(f[n-k*(3*k-1)/2]+f[n-k*(3*k+1)/2])
            å¶ä¸­n-k*(3*k-1)/2>=0,n-k*(3*k+1)/2>=0ï¼
        æ³¨æä¸¤ä¸ªæ¡ä»¶è¦åå¼å¤æ­ï¼æå¤§äº0çå°±å ä¸ç¸åºçfï¼ä¸æ¯ä¸¤ä¸ªåæ¶æç«æèä¸æç«
*/
