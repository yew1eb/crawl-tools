#include <stdio.h>
#include <string.h>
struct node{
 int x,y,r;
}e[300];
struct ppp{
 int x,y;
} now[300][2],ans[300];

ppp trans(int x,int y)
{
 ppp p;
 p.x=x-y;
 p.y=x+y;
 return p;
}

ppp transs(int x,int y)
{
 ppp p;
 p.x=(x+y)/2;
 p.y=(y-x)/2;
 return p;
}

int mins(int x,int y)
{
 return x<y?x:y;
}

int maxs(int x,int y)
{
 return x>y?x:y;
}

ppp solve(int num)
{
 int x,y,r;
 
 for(int i=0;i<=num;i++)
 {
 x=e[i].x;
 y=e[i].y;
 r=e[num].r;
 now[i][0]=trans(x-r,y);
 now[i][1]=trans(x+r,y);
 }
 x=ans[num+1].x;
 y=ans[num+1].y;
 r=e[num+1].r-e[num].r;
 //printf("r=%d\n",r);
 now[num+1][0]=trans(x-r,y);
 now[num+1][1]=trans(x+r,y);
 //for(int i=0;i<=num+1;i++) 
 // printf("(%d %d)-(%d %d)\n",now[i][0].x,now[i][0].y,now[i][1].x,now[i][1].y);
 //printf("num=%d\n",num) ;
 for(int i=1;i<=num+1;i++)
 {
 now[0][0].x=maxs(now[0][0].x,now[i][0].x);
 now[0][0].y=maxs(now[0][0].y,now[i][0].y);
 now[0][1].x=mins(now[0][1].x,now[i][1].x);
 now[0][1].y=mins(now[0][1].y,now[i][1].y);
 }
 //printf("ans=(%d %d)-(%d %d)\n",now[0][0].x,now[0][0].y,now[0][1].x,now[0][1].y);
 /*for(int i=now[0][0].x;i<=now[0][1].x;i++)
 {
 for(int j=now[0][0].y;j<=now[0][1].y;j++) printf("(%d %d) ",i,j);printf("\n");
 }*/
 if ((now[0][0].x+now[0][0].y)%2==0) return transs(now[0][0].x,now[0][0].y);
 if (now[0][0].x<now[0][1].x) return transs(now[0][0].x+1,now[0][0].y);
 return transs(now[0][0].x,now[0][0].y+1);
}

int main()
{
 int cas,n;
 
 //freopen("in.txt","r",stdin);
 scanf("%d",&cas);
 for(int ll=1;ll<=cas;ll++)
 {
 scanf("%d",&n);
 for(int i=0;i<n;i++) scanf("%d %d %d",&e[i].x,&e[i].y,&e[i].r);
 ans[n].x=e[n-1].x;
 ans[n].y=e[n-1].y;
 e[n].r=e[n-1].r*2;
 //ans[n].r*=2;
 for(int i=n-1;i>=0;i--)
 {
 ans[i]=solve(i);
 }
 printf("Case %d:\n",ll);
 for(int i=0;i<n;i++) printf("%d %d\n",ans[i].x,ans[i].y);
 }
}