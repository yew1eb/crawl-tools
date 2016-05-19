#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;
struct node{
    double x,y;
}p[1005];
bool xlji(double x1,double y1,double x2,double y2)
{
//    printf("%.0f %.0f %.0f %.0f\n",x1,y1,x2,y2);
    if((x1*x2+y1*y2)==0)return true;
    else return false;
}
int main()
{
  int T,i,j,k,n,a[10];
  scanf("%d",&T);
  while(T--)
  {
      multiset<int>st;
      st.clear();
      scanf("%d",&n);
      for(i=1;i<=n;i++)
      scanf("%lf%lf",&p[i].x,&p[i].y);
      if(n!=4){
          printf("NO\n");
      }
      else {
          for(i=1;i<=4;i++)
            for(j=i+1;j<=4;j++)
            {
                int ans=(p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);
                st.insert(ans);
            }
      multiset<int>::iterator it;
      it=st.begin();
      int x=*it;
      it++;
      k=1;
      for(;it!=st.end();it++)
        a[k++]=*it;
        if(x!=a[1]||x!=a[2]||x!=a[3]||2*x!=a[4]||2*x!=a[5])printf("NO\n");   //å¤æ­æ­£åè¾¹å½¢æ¯è¾ç®åçæ¹æ³ï¼çæ¯å¦æ4æ¡è¾¹ç¸ç­ï¼åæ¶ä¸¤æ¡å¯¹è§çº¿æ¯è¾¹çæ ¹å·2å
        else printf("YES\n");
      }
  }
  return 0;
 }