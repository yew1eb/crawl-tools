#include<cstdio>
#include <cassert>
#include<cstring>
#include<algorithm>
using namespace std;
const int MOD=10000;
const int B=10000;
const int SIZEN=505;
const int L=505;
struct Mat{
    int num[40][40];
    void init(int n){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            num[i][j]=i*n+j;
    }
    void change(int n){
        int t_num[40][40];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) t_num[j][n-i-1]=num[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) num[i][j]=t_num[i][j];
    }
    void change1(int n){
        int t_num[40][40];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) t_num[i][n-j-1]=num[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) num[i][j]=t_num[i][j];
    }
    void change2(int n){
        int t_num[40][40];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) t_num[n-i-1][j]=num[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) num[i][j]=t_num[i][j];
    }
    void change3(int n){
        int t_num[40][40];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) t_num[j][i]=num[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) num[i][j]=t_num[i][j];
    }
    void change4(int n){
        int t_num[40][40];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) t_num[n-1-j][n-1-i]=num[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) num[i][j]=t_num[i][j];
    }
    void output(int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) printf("%d ",num[i][j]);
            printf("\n");
        }
    }
};
struct BigInteger {
    BigInteger(int number = 0) : length(!!number) {
        assert(0 <= number && number < B);
        memset(digit, 0, sizeof(digit));
        digit[0] = number;
    }

    BigInteger normalize() {
        while (length && !digit[length - 1]) {
            length --;
        }
        return *this;
    }

    int operator[](int index) const {
        return digit[index];
    }

    int& operator[](int index) {
        return digit[index];
    }

    void output(){
        printf("%d",digit[length-1]);
        for(int i=length-2;i>=0;i--) printf("%04d",digit[i]);
        printf("\n");
    }

    int length, digit[L];
};

bool operator < (const BigInteger &a, const BigInteger &b)
{
    if (a.length != b.length) {
        return a.length < b.length;
    }
    for (int i = 0; i < a.length; ++ i) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return false;
}

BigInteger operator + (const BigInteger &a, const BigInteger &b)
{
    BigInteger c;
    c.length = std::max(a.length, b.length) + 1;
    for (int i = 0, delta = 0; i < c.length; ++ i) {
        delta += a[i] + b[i];
        c[i] = delta % B;
        delta /= B;
    }
    return c.normalize();
}

BigInteger operator - (const BigInteger &a, int b)
{
    assert(0 <= b && b < B);
    BigInteger c;
    c.length = a.length;
    for (int i = 0, delta = -b; i < a.length; ++ i) {
        delta += a[i];
        c[i] = delta;
        delta = 0;
        if (c[i] < 0) {
            c[i] += B;
            delta = -1;
        }
    }
    return c.normalize();
}

BigInteger operator * (const BigInteger &a, const BigInteger &b)
{
    BigInteger c;
    c.length = a.length + b.length;
    for (int i = 0; i < a.length; ++ i) {
        for (int j = 0, delta = 0; j <= b.length; ++ j) {
            delta += a[i] * b[j] + c[i + j];
            c[i + j] = delta % B;
            delta /= B;
        }
    }
    return c.normalize();
}

BigInteger operator / (const BigInteger &a, int b)
{
    assert(0 <= b && b < B);
    BigInteger c;
    c.length = a.length;
    for (int i = c.length - 1, delta = 0; i >= 0; -- i) {
        delta = delta * B + a[i];
        c[i] = delta / b;
        delta %= b;
    }
    return c.normalize();
}
BigInteger operator ^(const BigInteger &a,int b){
    BigInteger ret,ta;
    ret=1;ta=a;
    while(b){
        if(b&1) ret=ret*ta;
        ta=ta*ta;
        b>>=1;
    }
    return ret;
}
Mat mat;
BigInteger ret,tmp;
bool vis[1005];
void dfs(int u,int n){
    if(vis[u]) return;
    vis[u]=1;
    int x=u/n;
    int y=u%n;
    dfs(mat.num[x][y],n);
}
void solve(int n,int c){
    ret=0;
    ret.normalize();
    tmp=c;
    tmp.normalize();
    if(n%2==0){
        ret=ret+(tmp^(n*n));
        ret=ret+(tmp^(n*n/4));
        ret=ret+(tmp^(n*n/2));
        ret=ret+(tmp^(n*n/4));
        ret=ret+(tmp^(n*n/2))*2;
        ret=ret+(tmp^((n*n-n)/2+n))*2;
    }
    else{
        ret=ret+(tmp^(n*n));
        ret=ret+(tmp^(n*n-1)/4+1);
        ret=ret+(tmp^(n*n-1)/2+1);
        ret=ret+(tmp^(n*n-1)/4+1);
        ret=ret+(tmp^((n*n-n)/2+n))*2;
        ret=ret+(tmp^((n*n-n)/2+n))*2;
    }
    ret=ret/8;
    ret.output();
}
int main()
{
    int n,c;
    while(scanf("%d%d",&n,&c)!=EOF)
        solve(n,c);
}