#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
struct point{
    double x,y;
    bool operator < (point &a){
        return y<a.y || (y == a.y && x<a.x);
    }
};
bool mult(point &sp,point &ep,point &op){
    return (sp.x-op.x)*(ep.y-op.y)
        >=(ep.x-op.x)*(sp.y-op.y);
}
double dist(point &a,point &b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double graham(point *pnt,int n,point res[]){
    int i,len,k=0,top=1;
    sort(pnt,pnt+n);
    if(n==0) return 0; res[0]=pnt[0];
    if(n==1) return 0; res[1]=pnt[1];
    if(n==2) return dist(pnt[0],pnt[1]); res[2]=pnt[2];
    for(i=2;i<n;i++){
        while(top && mult(pnt[i],res[top],res[top-1])) //å·¦è½¬éæ ï¼ä¸å¸å
            top--;
        res[++top]=pnt[i];
    }
    len=top;
    res[++top]=pnt[n-2];
    for(i=n-3;i>=0;i--){
        while(top!=len && mult(pnt[i],res[top],res[top-1]))//ä¸å¸åã
            top--;
        res[++top]=pnt[i];
    }
    double area=0;
    for(i=1;i<=top;i++){
        area+=dist(res[i],res[(i+1)>top?1:(i+1)]);
    }
    
    return area;
}
int main(){
    int n;
    point pnt[105],res[105];
    while(scanf("%d",&n) && n){

        for(int i=0;i<n;i++)
            scanf("%lf %lf",&pnt[i].x,&pnt[i].y);
        printf("%.2lf\n",graham(pnt,n,res));
    }
    return 0;
}