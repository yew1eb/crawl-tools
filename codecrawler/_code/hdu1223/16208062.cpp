#include <cstdio>  
#include <cstdlib>  
#include <cmath>  
#include <cstring>  
#include <ctime>  
#include <algorithm>  
#include <iostream>
#include <sstream>
#include <string>
#define oo 0x13131313
const int maxn=52; 
const int L = 25;
const int B = 10000;
using namespace std;
struct Bigint
{
    int operator[](int index) const {
        return digit[index];
    }

    int& operator[](int index) {
        return digit[index];
    }
    int len;
    int digit[L];
};
Bigint F[52][52];
void MEMSET(Bigint &a)
{
    a.len=1;
    memset(a.digit,0,sizeof(a.digit));
}
void add(Bigint &d,const Bigint &a,const Bigint &b)
{
    int temp;
    Bigint c;
    MEMSET(c);
    c.len=max(a.len,b.len)+1;
    for(int i=0,temp=0;i<c.len;i++)
    {
        temp+=a[i]+b[i];
        c[i]=temp%B;
        temp=temp/B;
    }
    if(c[c.len-1]==0) c.len--;
    d=c;
}
void highXlow(Bigint &d,Bigint &a,int &b)
{
    int temp;
    Bigint c;
    MEMSET(c);
    c.len=a.len+1;
    for(int i=0,temp=0;i<c.len;i++)
    {
        temp+=a[i]*b;
        c[i]=temp%B;
        temp=temp/B;
    }
    if(c[c.len-1]==0) c.len--;
    d=c;
}
Bigint ANS[52];
void YCL()
{
    F[1][1].digit[0]=1;
    F[1][1].len=1;
    ANS[1].digit[0]=1;
    ANS[1].len=1;
    for(int i=2;i<=50;i++)
     for(int j=1;j<=i;j++)
     {
         add(F[i][j],F[i-1][j],F[i-1][j-1]);
         highXlow(F[i][j],F[i][j],j);
         add(ANS[i],ANS[i],F[i][j]);
     }
}
void outputBigint(Bigint &ans)
{
    if(ans.len>=1) printf("%d",ans[ans.len-1]);
    for(int i=ans.len-2;i>=0;i--)
    printf("%04d",ans[i]);
    printf("\n");
}
int main()
{
    int T,n;
    cin>>T;
    YCL();
    while(T--)
    {
        cin>>n;
        outputBigint(ANS[n]);    
    }
    return 0;
}
  