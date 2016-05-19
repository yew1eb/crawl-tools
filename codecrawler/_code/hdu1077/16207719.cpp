#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
struct node{
    double x,y;
};
node p[305];
const double eps=1e-10;
double distance1(node a,node b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
node O;
void f(node a,node b){

    double k=(-1)*(a.x-b.x)/(a.y-b.y);
    double xita=atan(k);
    node mid;
    mid.x=(a.x+b.x)/2;
    mid.y=(a.y+b.y)/2;
    double len = distance1(a,mid);
    len=sqrt(1.0-len);
    O.x=mid.x+(len*cos(xita));
    O.y=mid.y+(len*sin(xita));
}



int main(){
    int T;
    int n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        int ans=1;
        int tmp=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(distance1(p[i],p[j])>4.000)continue;
                f(p[i],p[j]);
                tmp=0;
                for(int k=0;k<n;k++){
                    if(distance1(p[k],O)<=1.0001)
                        tmp++;
                }
                ans=ans>tmp?ans:tmp;
            }
        }
        printf("%d\n",ans);


    }

    return 0;
}
