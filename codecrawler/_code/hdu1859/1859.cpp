#include<stdio.h>
struct pp
{
 int x;
 int y;
};
pp ans[1000];
int main()
{
 int i,j;
 int count;
 int max_x,max_y,min_x,min_y;
 bool flag;
 while(scanf("%d%d",&ans[0].x,&ans[0].y)&&(ans[0].x||ans[0].y))
 {
  flag=0;
  min_x=max_x=ans[0].x;
  min_y=max_y=ans[0].y;
   count=1;
S1:  while(scanf("%d%d",&ans[1].x,&ans[1].y))
     {
       if(ans[1].x==0&&ans[1].y==0) {flag=1;break;}
    if(ans[1].x>max_x)  max_x=ans[1].x;
    if(ans[1].x<min_x)  min_x=ans[1].x;
    if(ans[1].y>max_y)  max_y=ans[1].y;
    if(ans[1].y<min_y)  min_y=ans[1].y;
     }
     if(flag==0) goto S1;
     else
     printf("%d %d %d %d\n",min_x,min_y,max_x,max_y);
 }
 return 0;
}