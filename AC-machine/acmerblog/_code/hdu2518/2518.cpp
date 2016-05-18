#include<iostream>
#include<cstring>
using namespace std;
int a[10],b[10],flag,visited[10];
int yanzheng(int i)
{
    if(i==1)//和A相连的字母，下同
    {
       if((a[2]!=0&&abs(a[i]-a[2])==1)||(a[3]!=0&&abs(a[i]-a[3])==1)||(a[4]!=0&&abs(a[i]-a[4])==1))
           return -1;
       return 1;
    }
    else if(i==2)
    {
       if((a[1]!=0&&abs(a[i]-a[1])==1)||(a[3]!=0&&abs(a[i]-a[3])==1)||(a[5]!=0&&abs(a[i]-a[5])==1)||(a[6]!=0&&abs(a[i]-a[6])==1))
           return -1;
       return 1;
    }
    else if(i==3)
    {
       if((a[1]!=0&&abs(a[i]-a[1])==1)||(a[2]!=0&&abs(a[i]-a[2])==1)||(a[4]!=0&&abs(a[i]-a[4])==1))
           return -1;
       if((a[5]!=0&&abs(a[i]-a[5])==1)||(a[6]!=0&&abs(a[i]-a[6])==1)||(a[7]!=0&&abs(a[i]-a[7])==1))
           return -1;
       return 1;
    }
    else if(i==4)
    {
       if((a[1]!=0&&abs(a[i]-a[1])==1)||(a[3]!=0&&abs(a[i]-a[3])==1)||(a[6]!=0&&abs(a[i]-a[6])==1)||(a[7]!=0&&abs(a[i]-a[7])==1))
           return -1;
       return 1;
    }
    else if(i==5)
    {
       if((a[2]!=0&&abs(a[i]-a[2])==1)||(a[3]!=0&&abs(a[i]-a[3])==1)||(a[6]!=0&&abs(a[i]-a[6])==1)||(a[8]!=0&&abs(a[i]-a[8])==1))
           return -1;
       return 1;
    }
    else if(i==6)
    {
       if((a[2]!=0&&abs(a[i]-a[2])==1)||(a[3]!=0&&abs(a[i]-a[3])==1)||(a[4]!=0&&abs(a[i]-a[4])==1))
           return  -1;
       if((a[5]!=0&&abs(a[i]-a[5])==1)||(a[7]!=0&&abs(a[i]-a[7])==1)||(a[8]!=0&&abs(a[i]-a[8])==1))
           return -1;
       return 1;
    }
    else if(i==7)
    {
       if((a[3]!=0&&abs(a[i]-a[3])==1)||(a[4]!=0&&abs(a[i]-a[4])==1)||(a[6]!=0&&abs(a[i]-a[6])==1)||(a[8]!=0&&abs(a[i]-a[8])==1))
           return  -1;
       return 1;
    }
    else 
    { 
       if((a[5]!=0&&abs(a[i]-a[5])==1)||(a[6]!=0&&abs(a[i]-a[6])==1)||(a[7]!=0&&abs(a[i]-a[7])==1))
           return -1;
       return 1;
    }
}
void dfs(int i,int num)
{
    int j;
    if(num==8)//满足条件
    {
        flag++;
        if(flag==1)
          for(j=1;j<=8;j++)
              b[j]=a[j];
    }
    else
    {
            int nima;
            if(a[i]!=0)
            {
               nima=yanzheng(i);
               if(nima==1)
                   dfs(i+1,num);
            }
            else
            {
                for(j=1;j<=8;j++)
                {
                    if(visited[j]==0)
                    {
                       a[i]=j;
                       nima=yanzheng(i);
                       if(nima==-1)
                           a[i]=0;
                       else
                       {
                           visited[j]=-1;
                           i++;
                           num++;
                           dfs(i,num);
                           visited[j]=0;
                           a[i]=0;
                           i--;
                           num--;
                       }
                    }
                }
            }
    }
}
int main()
{
    int T,i,j,num;
    while(scanf("%d",&T)!=EOF)
    {
       for(i=1;i<=T;i++)
       {
          num=0;
          flag=0;
          memset(visited,0,sizeof(visited));
          for(j=1;j<=8;j++)
          {
              scanf("%d",&a[j]);
              if(a[j]!=0)
              {
                  num++;
                  visited[a[j]]=-1;
              }
          }
          dfs(1,num);
          printf("Case %d: ",i);
          if(flag==0)
              printf("No answer\n");
          else if(flag==1)
          {
              for(j=1;j<8;j++)
                  printf("%d ",b[j]);
              printf("%d\n",b[8]);
          }
          else
              printf("Not unique\n");
       }
    }
    return 0;
}