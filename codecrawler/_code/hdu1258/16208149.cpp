#include<iostream>
using namespace std;
int a[15],tmp[15];
int t,n;
bool flag;
int dfs(int s,int index,int cnt)
{
  //cntæ¯è®°å½æ°ç»çä¸æ  
  if(s==t)
  {
    flag=1;
    printf("%d",tmp[0]);
    for(int i=1;i<cnt;i++)
    printf("+%d",tmp[i]);
    printf("\n");
    return 0;
  }
  for(int j=index;j<n;j++)
  {
    if(j==index||a[j-1]!=a[j])
    {
      //è¿éé¿åéå¤ã å¾å·§å¦ãã 
       tmp[cnt]=a[j];//æ¾å¥è®°å½æ°ç»
       dfs(s+a[j],j+1,cnt+1);
    }
  }
  return 0;
}
int main()
{
  while(scanf("%d%d",&t,&n)!=EOF)
  {
    flag=0;
    if(t==0&&n==0) break;
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Sums of %d:\n",t);
    dfs(0,0,0);
    if(!flag)
    printf("NONE\n");
  }
}
