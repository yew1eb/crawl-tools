#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
const int M=50006;
struct point{
    int x,y;
};
int cmp(point a,point b){
    if(a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;
}

point p[M],ch[M];

double Cross(point a,point b){
    return a.x*b.y-a.y*b.x;
}
double Cross1(point a,point b,point c){
    a.x=a.x-c.x;
    a.y=a.y-c.y;

    b.x=b.x-c.x;
    b.y=b.y-c.y;
    return Cross(a,b);
}

int ConvexHull(int n){
    sort(p,p+n,cmp);
    int m=0;
    for(int i=0;i<n;i++){
        while(m>1 && Cross1(ch[m-1],p[i],ch[m-2])<=0 )
            m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;i--){
        while(m>k && Cross1(ch[m-1],p[i],ch[m-2])<=0)
            m--;
        ch[m++]=p[i];
    }
    if(n>1)
        m--;
    return m;
}


int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>p[i].x>>p[i].y;
        }
        int m=ConvexHull(n);
        double sum=0;
        for(int i=0;i<m-2;i++){
            for(int j=i+1;j<m-1;j++){
                for(int k=j+1;k<m;k++){
                    double sum1=0.5*(Cross1(ch[j],ch[k],ch[i]));
                    sum=sum>sum1?sum:sum1;
                }
            }
        }
        printf("%0.2lf\n",sum);
    }
    return 0;
}
