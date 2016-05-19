#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
#define inf 0x7fffffff
#define maxn 20050
double rr[maxn];
#define pi acos(-1.0)
struct node{
    int idx;
    double x,y,r;
}a[maxn],b[maxn];


double e[maxn];
double dis(double x1,double y1,double x2,double y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)  );
}
int n,m;

double cal(double len,int idx)
{
    int i,j;
    double s=0;
    s+=len*len;
    rr[idx]=len;
    for(i=2;i<=n;i++){
        len=e[idx]-len;
        s+=len*len;
        if(idx==n)idx=1;
        else idx++;
        rr[idx]=len;
    }
    return s;

}

bool cmp(node a,node b){
    return a.idx<b.idx;
}

double cal1(double lx,int idx){
    double temp=lx;
    double s=0.0;
    for(int i=1;i<=n;i++){
        s+=lx*lx;
        rr[idx]=lx;
        if(lx<0.0||lx>e[idx]||lx>e[idx==1?n:idx-1])return -1.0;
        lx=e[idx]-lx;
        idx++;
        if(idx>n)idx=1;
    }
    if(fabs(temp-lx)>1e-7)return -1.0;
    return s;
}

int main()
{
    int i,j,T,idx,idx1;
    double l,r,m1,m2,chang,len;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%lf%lf",&a[1].x,&a[1].y);
        for(i=2;i<=n;i++){
            scanf("%lf%lf",&a[i].x,&a[i].y);
            e[i-1]=dis(a[i-1].x,a[i-1].y,a[i].x,a[i].y);
        }
        e[n]=dis(a[n].x,a[n].y,a[1].x,a[1].y);
        if(n%2==1){
            idx1=1;
            double x=e[1];
            for(i=2;i<=n;i++){
                if(idx1==n)idx1=1;
                else idx1++;
                if(i%2==0)x-=e[idx1];
                else x+=e[idx1];
            }
            x/=2.0;

            if(x<0 || x>e[1]){
                printf("IMPOSSIBLE\n");continue;
            }
            int flag=1;
            idx1=1;
            double len=x;
            int tot=1;
            b[tot].idx=1;
            b[tot].r=x;
            for(i=1;i<=n-1;i++){
                len=e[idx1]-len;
                if(idx1==n)idx1=1;
                else idx1++;
                tot++;
                b[tot].r=len;
                b[tot].idx=idx1;
                if(len<0 || len>e[idx1]){
                    flag=0;break;
                }

            }
            if(flag){
                printf("%.2f\n",pi*cal(x,1));
                for(i=1;i<=n;i++)
                printf("%.2f\n",rr[i]);
            }
            else printf("IMPOSSIBLE\n");
        }
        else if(n%2==0){
            len=0;idx1=1;
            for(i=1;i<=n-1;i++){
                if(idx1==n)idx1=1;
                else idx1++;
                len=e[i]-len;
            }
            if(e[n]!=len){
                printf("IMPOSSIBLE\n");
                continue;
            }

            l=0;r=e[1];
            idx1=1;
            len=e[1];
            for(i=2;i<=n;i++){
                if(idx1==n)idx1=1;
                else idx1++;
                if(i%2==1){
                    len=e[idx1]-len;
                    r=min(r,len);
                }
                else{
                    len=e[idx1]-len;
                    l=max(l,-len);
                }
            }
            if(l>r){
                printf("IMPOSSIBLE\n");
                continue;
            }
            for(i=0;i<200;i++){
                double d=(l+r)/2.0;
                m1=d;
                m2=(d+r)/2.0;
                if(cal(m2,1)-cal(m1,1)>=0){
                    r=m2;
                }
                else l=m1;
             }
            printf("%.2f\n",cal(l,1)*pi);
            for(i=1;i<=n;i++){
                printf("%.2f\n",rr[i]);
            }

        }
    }
    return 0;
}
