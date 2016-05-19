#include<stdio.h>
#include<string.h>
#define size 100100
int n,c[size],x1[size],x2[size],y1[size],y2[size],a[size];

int Lowbit(int k)
{
    return (k&-k);
}
void update(int pos,int num)
{
    while(pos<size)//éè¦  æ¯size  èä¸æ¯<=n
    {
        c[pos]+=num;
        pos+=Lowbit(pos);
    }
}
int sum(int pos)
{
    int s=0;
    while(pos>0)
    {
        s+=c[pos];
        pos-=Lowbit(pos);
    }
    return s;
}



int main()
{
       int i,cas;
       scanf("%d",&cas);
       while(cas--)
       {
           memset(c,0,sizeof(c));
           scanf("%d",&n);
           for(i=1;i<=n;i++) 
           {
               scanf("%d",&a[i]);   
               int k1; 
               k1=sum(a[i]);
               x1[i]=k1; //è¾å¥çiä¸ªæ°ä¸­ æk1ä¸ªæ¯a[i]å°
               x2[i]=i-1-k1; //è¾å¥çiä¸ªæ°ä¸­ æk1ä¸ªæ¯a[i]å¤§
               update(a[i],1);
           }
           memset(c,0,sizeof(c));
           int j=1;//ä»£è¡¨ç°å¨è¾å¥çæ°çä¸ªæ° 
           for(i=n;i>=1;i--,j++) 
           {
                 int k1;
                 k1=sum(a[i]);
                 y1[i]=k1;//è¾å¥a[i]åè¾å¥çé£äºæ°ä¸­æå¤å°ä¸ªæ¯a[i]å°ç
                 y2[i]=j-1-k1; //è¾å¥a[i]åè¾å¥çé£äºæ°ä¸­æå¤å°ä¸ªæ¯a[i]å¤§ç
                 update(a[i],1);
           }
           __int64 ans=0;
           for(i=1;i<=n;i++)
           {
              // printf("x1[%d]=%d x2[%d]=%d y1[%d]=%d  y2[%d]=%d\n",i,x1[i],i,x2[i],i,y1[i],i,y2[i]);
              ans+=x1[i]*y2[i]+x2[i]*y1[i];
               // ans+=x1[i]*x2[i];
           }
           printf("%I64d\n",ans);
       }

}