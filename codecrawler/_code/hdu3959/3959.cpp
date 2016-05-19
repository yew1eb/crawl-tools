#include <cstdio>

typedef long long typen;

typen gcd (typen a , typen b){
    return b?gcd(b,a%b):a;
}

typen n,m;
int main ()
{
    int cas;
    scanf("%d",&cas);
    for (int I=1 ; I<=cas ; ++I)
    {
        scanf("%I64d%I64d",&n,&m);
        typen x=1;
        typen tmp=m;
        for ( ; tmp<n ; ++x,tmp*=m);
        //printf("x=%d\n",x);
        typen p,q;
        p=tmp*x;q=n;
        typen d=gcd (p,q);
        printf("Case %d: %I64d/%I64d\n",I,p/d,q/d);
    }
    return 0;
}
