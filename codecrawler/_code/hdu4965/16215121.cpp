#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 6;

struct matrix{
    int m[6][6];
};

matrix a,b,E;

int n,k;

int A[1001][7],B[7][1001],C[1001][1001],D[1001][1001];

void init(){
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
            E.m[i][j]=(i==j);
}

matrix multi(matrix a, matrix b){
    matrix c;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            c.m[i][j]=0;
            for(int h=0;h<k;h++)
                c.m[i][j]=(c.m[i][j]+a.m[i][h]*b.m[h][j])%mod;
        }
    }
    return c;
}

matrix power(matrix c,ll x){
    matrix ans=E,a=c;
    while(x){
        if(x&1){
            ans=multi(ans,a);
            x--;
        }
        x>>=1;
        a=multi(a,a);
    }
    return ans;
}

int main()
{
    while(~scanf("%d%d",&n,&k)){
        if(n==0&&k==0)
            break;
        for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
        scanf("%d",&A[i][j]);
        for(int i=0;i<k;i++)
        for(int j=0;j<n;j++)
        scanf("%d",&B[i][j]);
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                a.m[i][j]=0;
                for(int h=0;h<n;h++)
                    a.m[i][j]+=B[i][h]*A[h][j]%mod;
                a.m[i][j]%=mod;
            }
        }
        /*for(int i=0;i<k;i++){
            for(int j=0;j<k;j++)
                cout<<a.m[i][j]<<" ";
            cout<<endl;
        }*/
        init();
        matrix ans=power(a,n*n-1);
        /*cout<<"****"<<endl;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++)
                cout<<ans.m[i][j]<<" ";
            cout<<endl;
        }*/
        memset(C,0,sizeof(C));
        memset(D,0,sizeof(D));
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                if(A[i][j]==0) continue;
                for(int h=0;h<k;h++){
                    C[i][h]+=A[i][j]*ans.m[j][h];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                if(C[i][j]==0) continue;
                for(int h=0;h<n;h++){
                    D[i][h]+=C[i][j]*B[j][h];
                }
            }
        }
        ll sum=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
             sum+=(D[i][j]%6);
        cout<<sum<<endl;
    }
    return 0;
}