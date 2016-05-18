#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct Matrix
{
    long long m[3][3];
};
Matrix E,B;
long long kk,bb,nn,mod;
void Init()
{
    for(int i=1;i<=2;i++)
    for(int j=1;j<=2;j++)
        E.m[i][j]=(i==j);
    B.m[1][1]=B.m[1][2]=1;
    B.m[2][1]=1;
    B.m[2][2]=0;
}
Matrix Multi(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=1;i<=2;i++)
    for(int j=1;j<=2;j++)
    {
        ans.m[i][j]=0;
        for(int k=1;k<=2;k++)
        {
            ans.m[i][j]+=A.m[i][k]*B.m[k][j];
            ans.m[i][j]%=mod;
        }
    }
    return ans;
}
Matrix Pow(Matrix A,int k)
{
    Matrix ans=E;
    while(k)
    {
        if(k&1)
        {
            k--;
            ans=Multi(ans,A);
        }
        else
        {
            k/=2;
            A=Multi(A,A);
        }
    }
    return ans;
}
Matrix Add(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=1;i<=2;i++)
    for(int j=1;j<=2;j++)
    {
        ans.m[i][j]=(A.m[i][j]+B.m[i][j])%mod;
    }
    return ans;
}
Matrix Sum(Matrix mat,long long n)
{
    Matrix ans;
    if(n==0)
    {
        ans.m[1][1]=ans.m[1][2]=0;
        ans.m[2][1]=ans.m[2][2]=0;
        return ans;
    }
    else if(n==1)
    {
        return mat;
    }
    else
    {    //  cnt=A^k
        // sum(n) = A^k+A^2k+...A^(n-1)k  
        //        = cnt+cnt^2+cnt^3+...cnt^(n-1) 
        //   t=sum(n/2)
        // sum(n) = sum(n/2) + cnt^(n/2+1)+cnt^(n/2+2)+...cnt^(n-1)
        // sum(n) =  t +  cnt^(n/2+1)+cnt^(n/2+2)+...cnt^(n-1)
        // sum(n) =  t +  t * cnt^(n/2)   
        //  递归到最后的时候，n为奇数时直接算，相当于 n=39时
        //  sum(39) = cnt^1+cnt^2+...+cnt^39  t=19
        //  sum(39) = sum(19)+sum(19)*cnt^19+ cnt^39 (最后一项是因为n为奇数所余留的一项) 
        Matrix res,t;
        t=Sum(mat,n/2);
        res=Add(t,Multi(Pow(mat,n/2),t));
        if(n&1)
            res=Add(res,Pow(mat,n));
        return res;
    }
}
int main()
{
    while(scanf("%lld%lld%lld%lld",&kk,&bb,&nn,&mod)==4)
    {
        Init();
        Matrix M1=Pow(B,bb);
        Matrix M2=Pow(B,kk);
        Matrix res=Multi(M1,Add(E,Sum(M2,nn-1)));
        printf("%lld\n",res.m[1][2]);
    }
    return 0;
}