#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <string>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef long long LL;
const LL mod=10001;
struct Matrix
{
    LL m[33][33];
}E,D;
int M,N;
string s[33],S,T;
int Si,Ti;
void init()
{
    for(int i=1;i<33;i++)
        for(int j=1;j<=33;j++)
            E.m[i][j]=(i==j);
}
Matrix Multi(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=1;i<=M;i++)
        for(int j=1;j<=M;j++)
        {
            ans.m[i][j]=0;
            for(int k=1;k<=M;k++)
                ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%mod;
        }
    return ans;
}
Matrix Pow(Matrix A,LL k)
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
Matrix last(Matrix A,Matrix B,int m,int n,int l)
{
    Matrix ans;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=l;j++)
        {
            ans.m[i][j]=0;
            for(int k=1;k<=n;k++)
                ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%mod;
        }
    return ans;
}
void Print(Matrix A)
{
    for(int i=1;i<=M;i++)
    {
        for(int j=1;j<=M;j++)
            cout<<A.m[i][j]<<" ";
        cout<<endl;
    }
}
Matrix Add(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=1;i<=M;i++)
        for(int j=1;j<=M;j++)
            ans.m[i][j]=(A.m[i][j]+B.m[i][j])%mod;
    return ans;
}
Matrix Sum(Matrix A,LL k)
{
    if(k==0)
        return E;
    if(k==1)
        return A;
    if(k==3)
        return Add(A,Pow(A,3));
    if(((k+1)/2)&1)
        return Add(Sum(A,k-2),Pow(A,k));
    else
        return Multi(Add(E,Pow(A,(k+1)/2)),Sum(A,(k-1)/2));

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>M;
        init();
        for(int i=1;i<=M;i++)
            cin>>s[i];
        cin>>S;
        cin>>T;
        cin>>N;
        Matrix tmp;
        memset(tmp.m,0,sizeof(tmp.m));
        for(int i=1;i<=M;i++)
            for(int j=1;j<=M;j++)
            {
                if(s[i][s[i].size()-1]==s[j][0])
                    tmp.m[i][j]=1;
            }
        //Print(tmp);
        for(int i=1;i<=M;i++)
        {
            if(s[i]==S)
                Si=i;
            if(s[i]==T)
                Ti=i;
        }
        if(!(N&1))
            N--;
        tmp=Sum(tmp,N);
        Matrix ans;
        memset(ans.m,0,sizeof(ans.m));
        ans.m[1][Si]=1;
        ans=last(ans,tmp,1,M,M);
        cout<<ans.m[1][Ti]%mod<<endl;
    }
    return 0;
}