#include <iostream>
#include <vector>

#ifdef _WIN32  
#define LL unsigned __int64  
#define out64 "%I64u"  
#define in64 "%I64u"  
#else  
#define LL unsigned long long  
#define out64 "%llu"  
#define in64 "%llu"  
#endif 

#define cl(a) memset(a,0,sizeof(a))
#define ss(a) scanf("%d",&a)
#define sl(a) scanf(in64,&a)
#define pb push_back

using namespace std;

const int N=100100;
int a[N],c[N],e[N],p,b;
LL m;

void prime()
{
    int i,j;
    for (i=2;i<N;i++)
        if (!a[i])
        {
            for (j=i*2;j<N;j+=i)
            {
                if (!a[j]) c[j]=i;
                a[j]=1;
            }
        }
}

void euler()
{
    int i,k;
    for (i=2;i<N;i++)
        if (!a[i]) e[i]=i-1;
        else   
        {
            k=i/c[i];
            if (k%c[i]==0) e[i]=c[i]*e[k];
            else e[i]=(c[i]-1)*e[k];   
        }
}

LL js(int x,int y)
{
    LL k=y,r=x,res=1;
    while (k>0)
    {
        if (k&1) res=(res*r)%p;
        r=(r*r)%p;
        k>>=1;
    }
    return res;
}

void print(int cas,LL z)
{
    printf("Case #%d: "out64"\n",cas,z);
}

int main()
{
    int T,i,cas;
    ss(T);
    prime();
    euler();
    for (cas=1;cas<=T;cas++)
    {
        ss(b);ss(p);sl(m);
        if (p==1)
        {
            if (m==18446744073709551615ULL) 
                printf("Case #%d: 18446744073709551616\n",cas);
            else print(cas,m+1);
            continue;
        }
        LL n=0,r=1,z=0;
        while (r<e[p]&&n<=m)
        {   
            if (js(n,r)==b) z++;
            n++;
            r*=n;
        }
        r=r%e[p];
        while (r!=0&&n<=m)
        {
            if (js(n,e[p]+r)==b) z++;
            n++;
            r=(r*n)%e[p];
        }
        if (n>m)
        {
            print(cas,z);
            continue;
        }
        if (n>0) n--;
        else if (b==0) z++;
        for (i=0;i<p;i++)
            if (js(i,e[p])==b)
            {
                LL k1=0,k2=0;
                if (m>=i) k1=(m-i)/p+1;
                if (n>=i) k2=(n-i)/p+1;
                z=z+(k1-k2);
            }
        print(cas,z);      
    }
    return 0;
}
