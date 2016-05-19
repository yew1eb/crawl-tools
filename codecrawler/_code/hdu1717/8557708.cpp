#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
typedef long long LL;
LL n, m;
char tmp[50];
LL gcd(LL a, LL b)
{
    return b? gcd(b, a%b): a;
}
void solve1()
{
    LL t1=0, t2=0, f1, f2, i;
    n = m = 0;
    for(i=2; i<strlen(tmp)-1; i++)
    if(tmp[i]!='(')
    {
       m = m*10+tmp[i]-'0';
       t2++;
    }
    else
    {
        n = m;
        t1 =t2;
    }
   // cout<<n<<" "<<m<<endl;
    n = m-n;
    f1 = f2 =1;
    for(i=0; i<t1; i++) f1*=10;
    for(i=0; i<t2; i++) f2*=10;
    m = f2-f1;
    LL t = gcd(n,m);
    n /=t;
    m /=t;
}
void solve2()
{
    int len = strlen(tmp);
    double ff = atof(tmp);
    m = n = 1;
    for(int i=0; i<len-2; i++) m *=10;
    n =(LL)(ff*m+0.5);
    LL t = gcd(n,m);
    n /=t;
    m /=t;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>tmp;
        if(strchr(tmp,'('))
        {
            solve1();
        }
        else
        {
            solve2();
        }
        cout<<n<<"/"<<m<<endl;
    }
    return 0;
}
