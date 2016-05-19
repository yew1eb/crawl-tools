#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=500005;
typedef long long ll;
ll T,a,b,f[100][3];
char s[2][100]={"FIRST BIGGER","SECOND BIGGER"};

int main()
{
    f[1][0]=1;    f[1][1]=1;
    f[2][0]=1;    f[2][1]=8;
    for (int i=3;i<=10;i++) { f[i][0]=2;    f[i][1]=i-2;}
    for (int i=11;i<=18;i++) {f[i][0]=3;    f[i][1]=i-10;} 
    f[35][0]=4;    f[35][1]=7;
    f[36][0]=4;    f[36][1]=8;    
    f[53][0]=5;    f[53][1]=7;
    f[54][0]=5;    f[54][1]=8;    
    f[85][0]=6;    f[85][1]=7;
    f[86][0]=6;    f[86][1]=8;
    while (~scanf("%lld%lld",&a,&b))
    {
        int flag=1;
        if (a>b) swap(a,b),flag^=1;
        if (f[a][1]==f[b][1]) flag=flag^(f[a][0]<f[b][0]?1:0);
        else 
        {
            if ((b==5||b==8||b==13||b==16)&&a==b-1) flag^=1;
        }
        puts(s[flag]);
    }
    return 0;
}