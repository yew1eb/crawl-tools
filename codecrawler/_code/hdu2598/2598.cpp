#include<stdio.h>
#include<string.h>
char s[10000];
int map[111][111];
int main()
{
     int n,i,j,flag=0,x,y,xx,yy,cg;//cg表示交换是否成功  flag表示输入是否依旧是up right down left 
     while(scanf("%s",s)!=EOF)
     {
         if(strcmp(s,"MOVE")==0)
         {
              if(flag==1)
              {
                 if(cg==1) printf("MOVED\n");
                 else printf("FAILED\n");
                 cg=1;
                  flag=0;
              }
         }
         else if(strcmp(s,"SHOW")==0)
         {

                if(flag==1)
                {
                        if(cg==1) printf("MOVED\n");
                            else printf("FAILED\n");
                         cg=1;
                         flag=0;
                }
                 for(i=1;i<=n;i++)
                 {
                     for(j=1;j<n;j++)
                        printf("%d ",map[i][j]);
                     printf("%d\n",map[i][j]);
                 }
                 printf("\n");
         }
         else if(strcmp(s,"up")==0)
         {
             if(cg==0) continue;
                 flag=1;
                 xx=x-1;yy=y;
                 if(xx<1||xx>n||yy<1||yy>n) cg=0;
                 else
                    {
                        int temp;
                        temp=map[x][y];map[x][y]=map[xx][yy];map[xx][yy]=temp;
                         //temp=x; x=xx;xx=temp; temp=y; y=yy;yy=temp;
                         x=xx;y=yy;
                    }
         }
        else if(strcmp(s,"left")==0)
         {
                 if(cg==0) continue;
                 flag=1;
                 xx=x;yy=y-1;
                 if(xx<1||xx>n||yy<1||yy>n) cg=0;
                 else
                    {
                        int temp;
                        temp=map[x][y];map[x][y]=map[xx][yy];map[xx][yy]=temp;
                         //temp=x; x=xx;xx=temp; temp=y; y=yy;yy=temp;
                         x=xx;y=yy;
                    }
         }
        else if(strcmp(s,"right")==0)
        {
                 if(cg==0) continue;
                 flag=1;
                 xx=x;yy=y+1;
                 if(xx<1||xx>n||yy<1||yy>n) cg=0;
                 else
                    {
                        int temp;
                        temp=map[x][y];map[x][y]=map[xx][yy];map[xx][yy]=temp;
                         //temp=x; x=xx;xx=temp; temp=y; y=yy;yy=temp;
                         x=xx;y=yy;
                    }
        }
        else if(strcmp(s,"down")==0)
        {
                 if(cg==0) continue;
                 flag=1;
                 xx=x+1;yy=y;
                 if(xx<1||xx>n||yy<1||yy>n) cg=0;
                 else
                    {
                        int temp;
                        temp=map[x][y];map[x][y]=map[xx][yy];map[xx][yy]=temp;
                         //temp=x; x=xx;xx=temp; temp=y; y=yy;yy=temp;
                         x=xx;y=yy;
                    }
        }
        else
            {
              if(flag==1)
              {
                 if(cg==1) printf("MOVED\n");
                 else printf("FAILED\n");
              }
                flag=0;
                n=0;cg=1;
                //printf("s=%s\n",s);
                for(i=0;s[i]!='\0';i++) n=n*10+s[i]-'0';
               // printf("n=%d\n",n);
                for(i=1;i<=n;i++)
                    for(j=1;j<=n;j++)
                      {
                         scanf("%d",&map[i][j]);
                         if(map[i][j]==0) {x=i;y=j;}
                      }
            }
     }
     if(flag==1)//如果最后一个命令是MOVE  要在所有输入结束后输出下面的结果
              {
                 if(cg==1) printf("MOVED\n");
                 else printf("FAILED\n");
              }

}