#include <cstdio>  
#include <cstdlib>  
#include <cmath>  
#include <cstring>  
#include <ctime>  
#include <algorithm>  
#include <iostream>
#include <sstream>
#include <string>
#define oo 0x13131313
#define pi 3.1415926
#define exp 10e-6
using namespace std;
int N,L;
struct point{
    double x,y;
};
point A[1050];
point stk[1050];
int s=0;
int k;
int start;
double ans;

double dist(point a,point b)
{
    return     sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double crossdet(double x1,double y1,double x2,double y2)
{
    return x1*y2-x2*y1;
}
double cross(point a,point b,point c)
{
    return crossdet(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}
double dotdet(double x1,double y1,double x2,double y2)
{
    return x1*x2+y1*y2;
}
double dot(point a,point b,point c)
{
    return dotdet(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}
int sgn(double x)
{
    if(fabs(x)<exp) return 0;
    if(x<0) return -1;
    else return 1;
}int cmp(point a,point b)        // å½åç§¯ä¸º0æ¶éè¿ç¹ç§¯æ¯è¾çcmp 
{
    double temp=cross(A[1],a,b);
    double temp1;
    if(sgn(temp)==0)
    {
        temp1=dot(a,A[1],b);
        return sgn(temp1)<0;    // ç¹é èµ·ç¹è¿çæåé¢ 
    }
    else return sgn(temp)>0;
}
/*
int cmp(point a,point b)       //å½åç§¯ä¸º0æ¶éè¿è·ç¦»æ¯è¾çcmp 
{
    double temp=cross(A[1],a,b);
    double temp1;
    if(sgn(temp)==0)
    {
         return dist(a,A[1])<dist(b,A[1]);
    }
    else return sgn(temp)>0;
}
/*
int cmp(const void *i,const void *j)  //qsortçcmp 
{
    point *a=(point *)i,*b=(point *)j;
    double re=cross(A[1],*a,*b);
    if(re==0)
        return dist(*a,A[1])>dist(*b,A[1]);
    return re<0;
}
*/
void input()
{
    memset(stk,0,sizeof(stk));
    memset(A,0,sizeof(A));
    s=0;ans=0;
    cin>>N>>L;
    for(int i=1;i<=N;i++)
    {
        scanf("%lf%lf",&A[i].x,&A[i].y);
    }
}
void findmin(int &k)        //å¯»æ¾æå°çy,åæ¶æå°çè¯éxå°ç 
{
     k=1;
    for(int i=2;i<=N;i++)
    {
        if(sgn(A[i].y-A[k].y)<0)
        k=i;
        else if(sgn(A[i].y-A[k].y)==0&&(A[i].x-A[k].x)<0)
        k=i;
    }
}
void solve()                
{
    findmin(start); 
    swap(A[1],A[start]);//å°ç»èæ³¨æ 
//    qsort(A+2,N-1,sizeof(A[1]),cmp); 
    sort(A+2,A+N+1,cmp);
    for(int i=1;i<=2;i++)
    {
        stk[++s]=A[i];    //ä¸å¼å§äºä¸ªè¯å®å¨çç¹å¥æ  
    } 
    for(int i=3;i<=N;i++)
    {
        while(sgn(cross(stk[s-1],stk[s],A[i]))<=0&&s>=2)   //1.é²æ­¢ä¸é¢ç2ä¸ªç¹éæ  2.è¥stk[i-1]A[i]ä¸å¨stk[i-1]A[s]çéæ¶éæ¹å éæ  å¯»æ¾æ´å¥½çå¸å  
            s--;
        stk[++s]=A[i];                                       //å¥æ   æç»æ éé¢è³å°æ3ä¸ªç¹ ä¹æ¾ç¶å¯ç¥è¥å³ä½¿åªæ3ä¸ªç¹ å3ä¸ªç¹é½å¨å¸åä¸  
    }
    for(int i=2;i<=s;i++)
    {
        ans+=dist(stk[i],stk[i-1]);
    }
    ans+=dist(stk[1],stk[s]);
}
void init()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout); 
}
int main()
{
    int T;
    //init();
    cin>>T;
    int ttt=0;
    while(T--)
    {
        if(ttt++) printf("\n");
        input();
        solve();
        if(N==1) ans=0;
        else if(N==2) ans=dist(A[1],A[2]); 
        ans=ans+2*pi*L;                //ç±é¢ç®æ¾ç¶åå¶ å¸åå¨é¿å é£ä¸ªåçé¢ç§¯ 
        printf("%.0lf\n",ans);
    }
}
  