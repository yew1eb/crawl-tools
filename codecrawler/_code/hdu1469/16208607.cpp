#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

const int N = 101;
const double eps = 1e-8;
const double pi = acos(-1.0);

struct cpoint {//C++æé å½æ°,é»è®¤ç¼ºçå¼ä¸º(0,0)
    double x, y;
    cpoint(double xx = 0, double yy = 0): x(xx), y(yy) {};
};

int dcmp(double x) {//å¤æ­åæ°çç¬¦å·,è´æ°è¿å-1,0è¿å0,æ­£æ°è¿å1
    if (x < -eps) return -1; 
    else return x > eps;
}

double xmult(cpoint p0, cpoint p1, cpoint p2) { // p0p1 ä¸ p0p2 åç§¯
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

bool EqualPoint(cpoint a, cpoint b) {//ä¸¤ç¹ç¸ç­
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

struct cvector {//åé
    cpoint s, e;
    double ang, d;
};

//atan (double x)å¼§åº¦è¡¨ç¤ºçåæ­£å
//atan2(double x,double y)å¼§åº¦è¡¨ç¤ºçåæ­£å,ç¸å½äºatan(x/y)

void setline(double x1, double y1, double x2, double y2, cvector &v) {
    v.s.x = x1; v.s.y = y1;
    v.e.x = x2; v.e.y = y2;
    v.ang = atan2(y2 - y1, x2 - x1);
    //è¿éç d ä»£è¡¨åé(ç´çº¿)ååæ è½´çæªè·,æ­£æ°è¡¨ç¤º åç¹ å¨è¯¥åéçå·¦è¾¹
    //(è¿éé¢è¦æ±å·¦åå¹³é¢äº¤),è´å·åè¡¨ç¤º åç¹ å¨å³è¾¹
    if (dcmp(x1 - x2))          // x1 > x2
        v.d = (x1 * y2 - x2 * y1) / fabs(x1 - x2);
    else v.d = (x1 * y2 - x2 * y1) / fabs(y1 - y2);
}

//å¤åéå¹³è¡
bool parallel(const cvector &a, const cvector &b) {
    double u = (a.e.x - a.s.x) * (b.e.y - b.s.y) - (a.e.y - a.s.y) * (b.e.x - b.s.x);
    return dcmp(u) == 0;
}

//æ±ä¸¤åé(ç´çº¿)äº¤ç¹ (ä¸¤åéä¸è½å¹³è¡æéå)
cpoint CrossPoint(const cvector &a, const cvector &b) {
    cpoint res;
    double u = xmult(a.s, a.e, b.s), v = xmult(a.e, a.s, b.e);
    res.x = (b.s.x * v + b.e.x * u) / (u + v);
    res.y = (b.s.y * v + b.e.y * u) / (u + v);
    return res;
}

//åå¹³é¢äº¤æåºå½æ°[ä¼åé¡ºåº: 1.æè§ 2.åé¢çç´çº¿å¨åé¢çå·¦è¾¹]
static bool VecCmp(const cvector &l, const cvector &r) {
    if (dcmp(l.ang - r.ang)) return l.ang < r.ang;
    return l.d < r.d;
}

cvector deq[N]; //ç¨äºè®¡ç®çåç«¯éå

void HalfPanelCross(cvector vec[],int n,cpoint cp[],int &m)
{
    int i,tn;
    sort(vec,vec+n,VecCmp);
    for(tn=i=1;i<n;i++)
    {
        if(dcmp(vec[i].ang-vec[i-1].ang) != 0)
            vec[tn++]=vec[i];
    }n=tn;
    int bot=0, top=1;
    deq[0]=vec[0], deq[1]=vec[1];
    for(i=2;i<tn;i++)
    {
        if(parallel(deq[top],deq[top-1]) || parallel(deq[bot],deq[bot+1]))return ;
        while(bot<top && dcmp(xmult(vec[i].s,vec[i].e,CrossPoint(deq[top],deq[top-1])))<0)
            top--;
        while(bot<top && dcmp(xmult(vec[i].s,vec[i].e,CrossPoint(deq[bot],deq[bot+1])))<0)
            bot++;
        deq[++top]=vec[i];
    }
    while(bot<top && dcmp(xmult(deq[bot].s,deq[bot].e,CrossPoint(deq[top],deq[top-1])))<0)
        top--;
    while(bot<top && dcmp(xmult(deq[top].s,deq[top].e,CrossPoint(deq[bot],deq[bot+1])))<0)
        bot++;
    
    if(top <= bot+1)return ;
    
    m=0;
    for(i=bot;i<top;i++)
        cp[m++]=CrossPoint(deq[i],deq[i+1]);
    if(bot<top+1)
        cp[m++]=CrossPoint(deq[bot],deq[top]);
    m=unique(cp,cp+m,EqualPoint)-cp;
}

double PolygonArea(cpoint p[], int n) {
    if (n < 3) return 0;
    double s = p[0].y * (p[n - 1].x - p[1].x);
    for (int i = 1; i < n; ++i)
        s += p[i].y * (p[i - 1].x - p[(i + 1) % n].x);
    return fabs(s / 2); // é¡ºæ¶éæ¹åsä¸ºè´
}

int n,m;
cvector v[N];
cpoint cp[N];

int main()
{
    int i,j,time=1;
    cpoint p[N];
    while(scanf("%d",&n),n)
    {
        memset(cp,0,sizeof(cp));
        memset(v,0,sizeof(v));

        m=0;     //mæ¯å¨å±åé,æ³¨æ,åçº¯å¨å¤é¨å½æ°ä¸­åå§å,ææ¶åä¸é è°±

        for(i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        p[n]=p[0];
        
        for(j=0,i=n;i>0;i--)
            setline(p[i].x,p[i].y,p[i-1].x,p[i-1].y,v[j++]);
        n=j;
        
        HalfPanelCross(v,n,cp,m);//åé(ç´çº¿)éå,é¿åº¦;ç¹é,é¿åº¦
        
        printf("Floor #%d\n",time++);
        
        if(!m)printf("Surveillance is impossible.\n");
        else printf("Surveillance is possible.\n");
        puts("");
    }
    return 0;
}