#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn=50001;
struct node
{
    double  x,y;
} st[maxn],num[maxn];
int n,k,e;
double dis(node p1,node p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
int multi(node p1,node p2,node p3)//åç§¯
{
    return (p1.x-p3.x)*(p2.y-p3.y)-(p2.x-p3.x)*(p1.y-p3.y);
}
bool cmp(node p1,node p2)
{
    if(multi(p1,p2,num[0])>0) return true;
    if(multi(p1,p2,num[0])==0&&dis(p1,num[0])<dis(p2,num[0]))return true;
    return false;
}
void Graham()//å¸å
{
    e=2;
    sort(num+1,num+n,cmp);
    st[0]=num[0];
    st[1]=num[1];
    st[2]=num[2];
    for(int i=3; i<n; i++)
    {
        while(e>1&&multi(num[i],st[e],st[e-1])>=0)
            e--;
        st[++e]=num[i];
    }
}
void rotating_calipers()
{
    e++;
    int q=1;
    int ans=0;
    st[e]=st[0];
    for(int i=0; i<e; i++)
    {
        q=1;
        for(int p=i+1; p<e; p++)
        {
            while(multi(st[i],st[q+1],st[p])>multi(st[i],st[q],st[p]))
                q=(q+1)%e;
            ans=max(ans,multi(st[i],st[q],st[p]));
        }
    }//æ±æå¤§è¾¹çæ¹æ³ï¼ä½æ¯è¦èèå°ä¸ä¸å®ä»¥p,p+1ä¸ºåºçä¸è§å½¢ï¼
    double sss=(double)ans/2;
    printf("%.2lf\n",sss);
}
int main()
{
    while(~scanf("%d",&n))
    {
        k=0;//Kè¡¨ç¤ºèµ·å§ç¹
        for(int i=0; i<n; i++)
        {
            scanf("%lf %lf",&num[i].x,&num[i].y);
            if(num[i].x<num[k].x||(num[i].x==num[k].x&&num[i].y<num[k].y)) k=i;
        }
        swap(num[0],num[k]);
        //printf("%d\n",k);
        Graham();
        rotating_calipers();
    }
    return 0;
}
