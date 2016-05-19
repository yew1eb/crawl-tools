#include <cstdio>
#include<cstring>
#define mod 1000000007
#define LMT 130
#define LL long long
//~的优先级比位移低
//定义在结构体内就爆内存了..
//少在main中定义
//(x>>i)&1,才是判断啊
//给矩阵乘法跪了
using namespace std;
class matrix
{
    public:
    LL mat[LMT][LMT];
    int n,m;
    void init(void)
    {
        memset(mat,0,sizeof mat);
    }
    friend matrix operator*(matrix &,matrix &);
};
matrix matt,trans;
int state[260],lim=1<<8;
matrix operator *(matrix &a,matrix &b)
{
    matrix tem;
    tem.n=a.n;tem.m=b.m;
    tem.init();
    for(int k=0;k<a.m;k++)
      for(int i=0;i<a.n;i++)
      if(a.mat[i][k])
          for(int j=0;j<b.m;j++)
          tem.mat[i][j]=(tem.mat[i][j]+a.mat[i][k]*b.mat[k][j])%mod;
      return tem;
}
bool yes(int  code)
{
    int s=0;
    while(code)
    {
        s+=code&1;
        code>>=1;
    }
    return s%2==0;
}
LL can(int a,int b)
{
    int st,i,j;
    bool end=false;
    if(a==0)return b==255? 1LL:0;
    for(i=0;i<8;i++)
    {
        j=(i+7)%8;
        if((a&(1<<i))&&(a&(1<<j))==0)
        {
            st=i;
            break;
        }
    }
    for(i=st;i!=st||end==false;i=(i+1)%8)
    {
        end=true;
        j=(i+1)%8;
        if(0==(a&(1<<i)))
        {
            if(0==(b&(1<<i)))return 0;
        }
        else
        {
            if((a&(1<<j))&&(b&(1<<i))&&(b&(1<<j)))i++;
            else if((b&(1<<i))==0)continue;
            else return 0;
        }
    }
    return 1LL;
}
void init(void)
{
    lim=0;
    memset(state,-1,sizeof(state));
    for(int i=0;i<1<<8;i++)
    if(yes(i))state[i]=lim++;
    trans.init();
    trans.m=trans.n=lim;
    for(int i=0;i<1<<8;i++)
       for(int j=i+1;j<1<<8;j++)
       if(state[i]!=-1&&state[j]!=-1)
           trans.mat[state[j]][state[i]]=trans.mat[state[i]][state[j]]=can(i,j);
       trans.mat[lim-1][lim-1]=2;
}
matrix pow(matrix t,int n)
{
    matrix tem;
    tem.m=tem.n=lim;
    tem.init();
    for(int i=0;i<lim;i++)
    tem.mat[i][i]=1;
    while(n)
    {
        if(n&1)tem=tem*t;
        t=t*t;
        n>>=1;
    }
    return tem;
}
int main(void)
{
    int T,I,n;
    init();
   scanf("%d",&T);
    for(I=1;I<=T;I++)
    {
        scanf("%d",&n);
        matt=pow(trans,n);
        printf("Case %d: %I64d\n",I,matt.mat[lim-1][lim-1]);
    }
    return 0;
}
