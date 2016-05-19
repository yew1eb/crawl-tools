#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1010;

struct node {
    int p, h;
    bool operator <(const node& rhs)const {
        return p<rhs.p||(p==rhs.p&&h<rhs.h);
    }
} a[maxn];

int main()
{
    int T;
    int n, m, i;
    double sum;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        for(i=0; i<m; i++)
            scanf("%d%d",&a[i].p,&a[i].h);
        sort(a,a+n);
        sum =  0.0;
        i = 0;
        while(n) {
            if(a[i].p*a[i].h >=n) {
                sum += n*1.0/a[i].p;
                break;
            } else {
                sum += a[i].h;
                n -= a[i].p*a[i].h;
            }
            i++;
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}

