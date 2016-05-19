//=====================================================
//Name       :hdu 3492 Segment
//Author     :zhxfl
//copyright  :http://blog.sina.com.cn/s/articlelist_1736064691_0_1.html
//Description:给N条线段，问是否存在直线可以和所有线段相交
//Algorithm  :这条线段一定是由边界点连接而成的，这题有可能所有直线在同一个点上
//=====================================================
#include <iostream>  
#include <cmath>  
#include<cstdio>
using namespace std ;  
#define maxn 1000
double const eps=1e-8;   
struct point {  
    double x, y ;    
};
int  sign(double x) {  
    if(fabs(x) <= eps ) return 0 ;  
    if(x > 0) return 1 ;  
    return -1 ;         
}
struct Seg {  
    point a, b ;     
}seg[maxn],tmp;
int  n ,Tsame;
double multiply(point p1, point p2, point p3) {  
    return (p3.x - p1.x) * (p2.y - p1.y) - (p2.x - p1.x) * (p3.y - p1.y) ;  
}
bool Insect(Seg u, Seg v) {  //u直线 v线段
    double d3 = multiply(u.a, u.b, v.a) ;   
    double d4 = multiply(u.a, u.b, v.b) ;   
    if (sign(d3) * sign(d4)<=0) return true ;  
    return false ;         
}  
bool same(point a,point b){    
    if(sign(a.x-b.x)==0&&sign(a.y-b.y)==0)return 1;
    else return 0;
}
bool Judge(point a,point b) {
    if(same(a,b))return 0;
    Seg tmp;
    int i;
    tmp.a=a,tmp.b=b ;  
    Tsame=0;
    for(i=0;i<n;i++) {  
        if(!Insect(tmp, seg[i])) return 0;      
    }    
    return 1 ;  
}
bool Sol(){
    int i,j;
    Tsame=1;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(Judge(seg[i].a,seg[j].b))return 1;
            if(Judge(seg[i].a,seg[j].a))return 1;
            if(Judge(seg[i].b,seg[j].a))return 1;
            if(Judge(seg[i].b,seg[j].b))return 1;
        }
    }
    if(Tsame)return 1;
    return 0;
}
int main() {  
    int T,i,j;
    //freopen("a.txt","r",stdin);
    scanf("%d", &T) ;  
    while(T--) {   
        scanf("%d", &n) ;  
        for(i=0;i<n;i++)
            scanf("%lf%lf%lf%lf",&seg[i].a.x,&seg[i].a.y,&seg[i].b.x,&seg[i].b.y);
        if(Sol()){
            puts("Yes");
        }else puts("No");  
    }  
    return 0 ;  
}