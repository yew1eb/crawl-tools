#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define pi acos(-1.0)
const int MAXN=1005;//ç¹æ°


struct point
{
    int x,y;
};
point list[MAXN];
int stack[MAXN],top;

int cross(point p0,point p1,point p2) //è®¡ç®åç§¯  p0p1 X p0p2 
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}    
double dis(point p1,point p2)  //è®¡ç® p1p2ç è·ç¦» 
{
    return sqrt((double)(p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}    
bool cmp(point p1,point p2) //æè§æåºå½æ° ï¼ è§åº¦ç¸ååè·ç¦»å°çå¨åé¢ 
{
    int tmp=cross(list[0],p1,p2);
    if(tmp>0) return true;
    else if(tmp==0&&dis(list[0],p1)<dis(list[0],p2)) return true;
    else return false;
}    
void init(int n) //è¾å¥ï¼å¹¶æ  æå·¦ä¸æ¹çç¹æ¾å¨ list[0]  ãå¹¶ä¸è¿è¡æè§æåº   list å­ç¹,ä¸æ [0,n);
{
    int i,k;
    point p0;
    scanf("%d%d",&list[0].x,&list[0].y);
    p0.x=list[0].x;
    p0.y=list[0].y;
    k=0;
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&list[i].x,&list[i].y);
        if( (p0.y>list[i].y) || ((p0.y==list[i].y)&&(p0.x>list[i].x)) )
        {
            p0.x=list[i].x;
            p0.y=list[i].y;
            k=i;
        }    
    }    
    list[k]=list[0];
    list[0]=p0;
    
    sort(list+1,list+n,cmp);
}     

void graham(int n) // stack éå­çæ¯å¸åå¤å´ç¹çä¸æ . [0,top] åå«
{
    int i;
    if(n==1) {top=0;stack[0]=0;}
    if(n==2)
    {
        top=1;
        stack[0]=0;
        stack[1]=1;
    }    
    if(n>2)
    {
        for(i=0;i<=1;i++) stack[i]=i;
        top=1;
        
        for(i=2;i<n;i++)
        {
            while(top>0&&cross(list[stack[top-1]],list[stack[top]],list[i])<=0) top--;
            top++;
            stack[top]=i;
        }    
    }    
}
double sumlen()//å¨é¿è®¡ç®
{
    double sum=0;
    for(int i=1;i<=top;i++)
    {
        sum+=dis(list[stack[i-1]],list[stack[i]]);
    }
    sum+=dis(list[stack[0]],list[stack[top]]);//æ³¨æä¸é¦å°¾ç¸å 
    return sum;
}
        



int main()
{
    int num,R,tt,i;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d%d",&num,&R);
        init(num);
        graham(num);
        double ans=sumlen()+2.0*pi*R;
        printf("%.0lf\n",ans);
        if(tt!=0)
            puts("");
    }
    return 0;
}