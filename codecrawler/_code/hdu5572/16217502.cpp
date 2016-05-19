#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;

typedef long double LD;
const LD pi=acos(-1.0);
const LD eps=1e-10;
int dcmp(LD x){
    if(fabs(x)<=eps)  return 0;
    else  return x<0?-1:1;
}
struct Point
{
    LD x,y;
    Point(){}
    Point(LD _x,LD _y){
        x = _x;y = _y;
    }
};

bool operator < (const Point& a,const Point& b) {
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
bool operator == (const Point& a,const Point &b) {
    return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}

typedef Point Vec;   //Ð¾Ð Ð°Â©

Vec operator + (Vec A,Vec B)  {return Vec(A.x+B.x,A.y+B.y); }

Vec operator - (Point A,Point B)  {return Vec(A.x-B.x,A.y-B.y); }

Vec operator * (Vec A,LD p)  {return Vec(A.x*p,A.y*p); }

Vec operator / (Vec A,LD p)  {return Vec(A.x/p,A.y/p); }

LD Dot (Vec A,Vec B)  { return A.x*B.x+A.y*B.y; }

LD Length(Vec A)  { return sqrt(Dot(A,A)); }

LD Angle(Vec A,Vec B)  { return acos(Dot(A,B)/Length(A)/Length(B)); }

LD Cross(Vec A,Vec B)  { return A.x*B.y-A.y*B.x; }

Vec Rotate(Vec A,LD rad) {
    return Vec(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}

int main (){
   /* Vec pp;
    while(scanf("%lf%lf",&pp.x,&pp.y)!=EOF){
        pp=Rotate(pp,pi/2);
        cout<<pp.x<<"   "<<pp.y<<endl;
    }*/
    LD v1,v2;
    LD x0,y0,x1,y1,x2,y2,r;
    int countt;
    scanf("%d",&countt);
    for(int kk=1;kk<=countt;kk++){
        cin>>x0>>y0>>r;
        cin>>x1>>y1>>v1>>v2;
        cin>>x2>>y2;
        printf("Case #%d: ",kk);
        LD a=v1*v1+v2*v2;
        LD b=v1*(x1-x0)*2+v2*(y1-y0)*2;
        LD c=(x1-x0)*(x1-x0)+(y1-y0)*(y1-y0)-r*r;
        if(b*b-a*c*4<=0){
            if(dcmp(v1)==0){
                LD t=(y2-y1)/v2;
                if(t>=0&&dcmp(x2-v1*t-x1)==0)
                    printf("Yes\n");
                else
                    printf("No\n");
            }
            else{
                LD t=(x2-x1)/v1;
                if(t>=0&&dcmp(y2-t*v2-y1)==0)
                    printf("Yes\n");
                else
                    printf("No\n");
            }
            continue;
        }
        LD t=(-b-sqrt(b*b-a*c*4))/a/2.0;
        if(t<0){
            if(dcmp(v1)==0){
                LD tt=(y2-y1)/v2;
                if(tt>=0&&dcmp(x2-v1*tt-x1)==0)
                    printf("Yes\n");
                else
                    printf("No\n");
            }
            else{
                LD tt=(x2-x1)/v1;
                if(tt>=0&&dcmp(y2-tt*v2-y1)==0)
                    printf("Yes\n");
                else
                    printf("No\n");
            }
            continue;
        }
        int is=0;
        if(dcmp(v1)==0){
            LD tt=(y2-y1)/v2;
            if(tt>=0&&dcmp(x2-v1*tt-x1)==0&&tt<=t)
                is=1;
        }
        else{
            LD tt=(x2-x1)/v1;
            if(tt>=0&&dcmp(y2-tt*v2-y1)==0&&tt<=t)
                is=1;
        }
        if(is==1){
            printf("Yes\n");
            continue;
        }
        Point A,O,C,B;
        A.x=x1,A.y=y1;
        B.x=x2,B.y=y2;
        O.x=x0,O.y=y0;
        C.x=x1+v1*t,C.y=y1+v2*t;
        /*if(dcmp(Length(A-C)-Length(B-C)-Length(A-B))==0){
            printf("Yes\n");
            continue;
        }
        if(dcmp(Angle(A-C,C-O)-Angle(B-C,C-O))==0&&
            dcmp(Angle(A-C,B-C)-2*Angle(A-C,C-O))==0){
            printf("Yes\n");
        }
        else
            printf("No\n");*/


        LD ang=Angle(C-O,A-C);
        Vec dir;
        if(Cross(C-O,A-C)>0)
            dir=Rotate(A-C,-ang*2);
        else
            dir=Rotate(A-C,ang*2);
       // cout<<t<<endl;
       // cout<<dir.x<<"   "<<dir.y<<endl;
       // cout<<C.x<<"  "<<C.y<<endl;
        v1=dir.x,v2=dir.y;
        x1=C.x,y1=C.y;
        if(dcmp(v1)==0){
            LD tt=(y2-y1)/v2;
            if(tt>=0&&dcmp(x2-v1*tt-x1)==0)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else{
            LD tt=(x2-x1)/v1;
            if(tt>=0&&dcmp(y2-tt*v2-y1)==0)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
