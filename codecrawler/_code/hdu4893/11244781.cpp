#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;
typedef long long LL;

const int maxn = 100000 + 10;
int n, m;
LL C[maxn], num[maxn], f[maxn];
vector<int> vec;
set<int> s;

void Init()
{
    int  i;
    f[0]=1;
    f[1]=1;
    for(i=2; i<=91; i++) {
        f[i]=f[i-1]+f[i-2];
    }
}

int lowbit(int x)
{
    return x&(-x);
}
void update(int i, LL v)
{
    for(; i<=n; i += lowbit(i)) C[i] +=v;
}

LL getsum(int i)
{
    LL ret=0;
    for(; i>0; i-=lowbit(i)) ret +=C[i];
    return ret;
}

//ÊÊÓÃÓÚÕýÕûÊý
template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret=0;
    while((c=getchar())<'0'||c>'9');
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
}
LL Find(LL x)
{
    int t = lower_bound(f,f+92, x) - f;
    LL k;
    if(t==0) k = 1;
    else {
        if(abs(f[t]- x)<abs(x-f[t-1])) k =f[t];
        else k = f[t-1];
    }
    return k;
}

int main()
{
    Init();
    int  i, j;
    int  a, b, c;
    //freopen("in.txt","r",stdin);
    while(~scanf("%d%d", &n, &m)) {
        memset(num, 0, sizeof(LL)*(n+2) );
        memset(C, 0, sizeof(LL)*(n+2) );
        s.clear();
        set<int>::iterator pos;
        for(i=1; i<=n; ++i) s.insert(i);
        while(m--) {
            scan_d(a);
            scan_d(b);
            scan_d(c);
            //scanf("%d%d%d", &a, &b, &c);
            if(a==1) {
                update(b, c);
                num[b] += c;
                s.insert(b);
            } else if(a==2) {
                LL ans = getsum(c) - getsum(b-1);
                printf("%I64d\n", ans);
            } else if(a==3) {
                vec.clear();
                for( pos = s.lower_bound(b); ((*pos)<=c)&&(pos!=s.end());pos++) {
                    int p = *pos;
                    LL New = Find(num[p]);  //num[p] -> Nearest Fibonacci number
                    update(p, New - num[p]);
                    num[p] = New;
                    vec.push_back(p);
                }

                for(i=0; i<vec.size(); ++i)
                    s.erase(vec[i]);
            }
        }
    }
    return 0;
}
