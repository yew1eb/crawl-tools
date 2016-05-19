#include <stdio.h>
#include <string.h>

int hash[30];
int arr[100];
int n;

int check(int x)
{
    int i;

    for(i=2;i<x;i++)
        if(x%i==0)
            return 0;

    return 1;
}

void DFS(int order,int index)
{
   int i;

   arr[order]=index;hash[index]=1;
   
   if(order==n)
   {
     if(check(arr[order]+arr[1]))
     {
        printf("1");
       for(i=2;i<=n;i++)
        printf(" %d",arr[i]);
       printf("\n");
     }
     
     return ;
   }

   for(i=1;i<=n;i++)
   {
       if(!hash[i]&&check(arr[order]+i))
       {
           DFS(order+1,i);
           hash[i]=0;//æ³¨æåæº¯
       }
   }

  return ;
}

int main()
{
    int flag=1;

    while(scanf("%d",&n)!=EOF)
    {
      printf("Case %d:\n",flag++);
     
      memset(hash,0,sizeof(hash));
      DFS(1,1);

      printf("\n");
    }

    return 0;
}
