
#include  
#include  
#include  
#include  
#include  
using namespace std; 
 
const int N=1003,INF=100000; 
 
struct date 
{ 
    int mon,day,h,min; 
    bool operator >=(const date& y) 
    { 
        if (mon>y.mon) return true; 
        if (mony.day) return true; 
        if (dayy.h) return true; 
        if (h=y.min) return true; 
        else return false; 
    } 
}a[N]; 
 
int f[N][N],y[N]; 
bool v[N]; 
 
int main() 
{ 
    int i,j,n,ty,ans; 
    char ch; 
 
    freopen("in","r",stdin); 
    while (1) 
    { 
        scanf("%d\n",&n); 
        if (n==0) break; 
        if (n=1;i--) 
        { 
            scanf("%d:%d:%d:%d %d %c\n",&a[i].mon,&a[i].day,&a[i].h, 
                  &a[i].min,&j,&ch); 
            if (ch=='+') v[i]=true; 
            else v[i]=false; 
        } 
        y[1]=0; 
        for (i=2;i=a[i-1]) y[i]=y[i-1]+1; 
            else y[i]=y[i-1]; 
        f[1][1]=1; 
        if (v[1]) f[1][0]=INF; 
        else f[1][0]=0; 
        for (i=2;i=a[j]) ty=y[j]+1; 
                    else ty=y[j]; 
                    if (ty!=y[i]) continue; 
                    f[i][i]=min(f[i][i],f[i-1][j]+1); 
                } 
            } 
            else 
            { 
                for (j=1;j=a[j]) ty=y[j]+1; 
                    else ty=y[j]; 
                    if (ty!=y[i]) continue; 
                    f[i][i]=min(f[i][i],f[i-1][j]+1); 
                } 
            } 
        } 
        ans=INF; 
        for (i=1;i=INF) ans=n; 
        printf("%d\n",ans); 
    } 
} 
