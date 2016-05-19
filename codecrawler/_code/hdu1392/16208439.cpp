#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
    int x,y;
};
node vex[1000];
bool cmp1(node a,node b)
{
    if(a.y==b.y)
        return a.x<b.x;
    else
        return a.y<b.y;
}
int cross(node,node,node);
double dis(node,node);
bool cmp(node a,node b)
{
 int m=cross(vex[0],a,b);
 if(m==0)
  return dis(vex[0],a)-dis(vex[0],b)<=0?true:false;
 else
  return m>0?true:false;
}
node stackk[1000];
int cross(node a,node b,node c)
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
double dis(node a,node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)*1.0+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    int t;
    while(scanf("%d",&t),t!=0)
    {
        int i;
        for(i=0;i<t;i++)
        {
            scanf("%d%d",&vex[i].x,&vex[i].y);
        }
        if(t==1)
            printf("%.2f\n",0.00);
        else if(t==2)
            printf("%.2f\n",dis(vex[0],vex[1]));
        else
        {
        sort(vex,vex+t,cmp1);
        sort(vex+1,vex+t,cmp);
        memset(stackk,0,sizeof(stackk));
        stackk[0]=vex[0];
        stackk[1]=vex[1];
        int top=1;
        for(i=2;i<t;i++)
        {
            while(i>=1&&cross(stackk[top-1],stackk[top],vex[i])<0)   //å¯¹ä½¿ç¨æè§æåºçi>=1ææ¶å¯ä»¥ä¸ç¨ï¼ä½å ä¸æ»æ¯å¥½ç
                top--;                                           //è¥ä½¿ç¨é»ä¹¦ä¸­ç¬¬äºç§æåºæ¹æ³cmp1åå¿é¡»å ä¸ï¼
            stackk[++top]=vex[i];                                    //æ§å¶<0æ<=0å¯ä»¥æ§å¶éç¹ï¼å±çº¿çï¼å·ä½è§é¢ç®èå®ã
        }


        double s=0;
        for(i=1;i<=top;i++)
            s+=dis(stackk[i-1],stackk[i]);
        s+=dis(stackk[top],vex[0]);
        printf("%.2f\n",s);
        }
    }
}