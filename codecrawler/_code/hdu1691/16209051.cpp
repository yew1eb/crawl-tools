#include <iostream>
#include <cstdio>
using namespace std;
int map[11][10];
int x[2],y[2];
int abs(int a){return a>0?a:-a;}
bool s(int x,int y,int xi,int xm,int yi,int ym)
{
    return (x<xi||x>xm||y<yi||y>ym);
}
bool legal(int f,int x1,int x2,int y1,int y2)// !fçº¢ï¼fé»
{
    if(x[0]<0||x[1]<0)return 0;//å·²å°å
    if(s(x1,y1,1,10,1,9)||s(x2,y2,1,10,1,9))return 0;//è¶ç
    if(x1==x2&&y1==y2)return 0;//ä¸ç§»å¨
    if(map[x1][y1]==0)return 0;//æ å­
    if( f&&(map[x1][y1]<8||map[x2][y2]>7))return 0;//æ§å¶å«äººæ£æèåèªå·±
    if(!f&&(map[x1][y1]>7||(map[x2][y2]<8&&map[x2][y2]>0)))return 0;
    int mi,ma,i,t,t1,t2;
    switch(map[x1][y1])
    {
        case 1:case 8://å¸
           if(!f&&(s(x1,y1,8,10,4,6)||s(x2,y2,8,10,4,6)))return 0;//ä¹å®«æ ¼
           if( f&&(s(x1,y1,1,3 ,4,6)||s(x2,y2,1,3 ,4,6)))return 0;
           if(abs(x1-x2)+abs(y1-y2)>1)return 0;
           x[f]=x2;y[f]=y2;
           break;
        case 2:case 9://å£«
          if(!f&&(s(x1,y1,8,10,4,6)||s(x2,y2,8,10,4,6)))return 0;
          if( f&&(s(x1,y1,1,3 ,4,6)||s(x2,y2,1,3 ,4,6)))return 0;
          if((abs(x1-x2)!=1||abs(y1-y2)!=1))return 0;//æä¸æ ¼
          break;
        case 3:case 10://è±¡
          t1=y1/2,t2=y2/2;//ä¸å¨å¸¸è§ä½ç½®
          if((y1%2)==0||(y2%2)==0)return 0;
          if(f)
          {
              t1+=x1/2,t2+=x2/2;
              if((x1%2)==0||(x2%2)==0)return 0;
          }
          else
          {
              t1+=(11-x1)/2;t2+=(11-x2)/2;
              if((x1%2)||(x2%2))return 0;
          }
          if(t1%2==0||t2%2==0)return 0;
          if( f&&(x2>5||x1>5))return 0;
          if(!f&&(x2<6||x1<6))return 0;
          if(abs(x1-x2)!=2||abs(y1-y2)!=2)return 0;
          if(map[(x1+x2)>>1][(y1+y2)>>1])return 0;
          break;
        case 4:case 11://é©¬
          if(abs(x1-x2)==1&&abs(y1-y2)==2)
          {
              if(map[x1][(y1+y2)>>1])return 0;
          }
          else if(abs(x1-x2)==2&&abs(y1-y2)==1)
          {
              if(map[(x1+x2)>>1][y1])return 0;
          }
          else return 0;
          break;
        case 5:case 12://è½¦
          if(x1!=x2&&y1!=y2)return 0;
          if(x1==x2)
          {
            mi=min(y1,y2);ma=max(y1,y2);
            for(i=mi+1;i<ma&&map[x1][i]==0;i++);
            if(i!=ma)return 0;
          }
          else
          {
            mi=min(x2,x1);ma=max(x1,x2);
            for(i=mi+1;i<ma&&map[i][y1]==0;i++);
            if(i!=ma)return 0;
          }
          break;
        case 6:case 13://ç®
          if(x1!=x2&&y1!=y2)return 0;
          if(x1==x2)
          {
            mi=min(y1,y2);ma=max(y1,y2);t=0;
            for(i=mi+1;i<ma;i++)
                if(map[x1][i]!=0)t++;
            if(t>1||(t==1&&map[x2][y2]==0)||(t==0&&map[x2][y2]))return 0;
          }
          else
          {
            mi=min(x2,x1);ma=max(x1,x2);t=0;
            for(i=mi+1;i<ma;i++)
               if(map[i][y1]!=0)t++;
            if(t>1||(t==1&&map[x2][y2]==0)||(t==0&&map[x2][y2]))return 0;
          }
          break;
        case 7:case 14://åµ
          if(!f)
          {
              if(x1>5&&(x1-x2!=1||y1!=y2))return 0;
              if(x1<6&&(abs(x1-x2)+abs(y1-y2)!=1||x2>x1))return 0;
          }
          else
          {
              if(x1<6&&(x2-x1!=1||y1!=y2))return 0;
              if(x1>5&&(abs(x1-x2)+abs(y1-y2)!=1||x2<x1))return 0;
          }
          break;
    }
    if(map[x2][y2]==1)x[0]=-1;
    if(map[x2][y2]==8)x[1]=-1;
    map[x2][y2]=map[x1][y1];map[x1][y1]=0;
    if(x[0]==x[1])//çé¢å¯¹é¢
    {
        mi=min(y[0],y[1]);ma=max(y[0],y[1]);
        for(i=mi+1;i<ma&&map[x[0]][i]==0;i++);
        if(i==ma)return 0;
    }
    else if(y[0]==y[1])
    {
        mi=min(x[0],x[1]);ma=max(x[0],x[1]);
        for(i=mi+1;i<ma&&map[i][y[0]]==0;i++);
        if(i==ma)return 0;
    }
    return 1;
}
int main()
{
    int T,C=0;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,f,m;
        for(i=1;i<=10;i++)
         for(j=1;j<=9;j++)
         {
          scanf("%d",&map[i][j]);
          if(map[i][j]==1)x[0]=i,y[0]=j;
          if(map[i][j]==8)x[1]=i,y[1]=j;
         }
        scanf("%d%d",&m,&f);
        int x1,y1,x2,y2,k,flag=0;
        for(k=1;k<=m;k++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(!flag&&!legal(f,x1,x2,y1,y2))flag=k;
            f=!f;
        }
        printf("Case %d: ",++C);
        if(flag)printf("Illegal move on step %d\n",flag);
        else printf("Legal move\n");
    }
}
