#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;
stack<int> s[105];         //每张牌看成一个栈
int main()
{
  int n,m,num=1,i,j,a[105],k;
  char str[105];
  int ok[105];               //标记每张牌的状态
  while(scanf("%d",&n)!=EOF)
  { 
    if(n==0)
         break;
    scanf("%s",str);
    for(i=0;i<n;i++)
    {
       if(str[i]=='U')
           ok[i]=1;
       else
           ok[i]=0;
    }
    
    int l=0,r=n-1;
    for(i=0;i<n;i++)
        s[i].push(i);       
    scanf("%s",str);
    for(i=0;i<n-1;i++)
    {
       if(str[i]=='L')
       { 
         l++;
         for(j=0;j<l;j++)
             ok[j]=1-ok[j];
         while(!s[l-1].empty())
         {
             s[l].push(s[l-1].top());
             s[l-1].pop();
         }
       }
       else
       {
         r--;
         for(j=n-1;j>r;j--)
             ok[j]=1-ok[j];
         while(!s[r+1].empty())
         {
           s[r].push(s[r+1].top());
           s[r+1].pop();
         }
       }
    }
     for(i=0;i<n;i++)
     {
         a[i]=s[l].top();
         s[l].pop();
     }
     printf("Pile %d\n",num++);
     scanf("%d",&m);
     while(m--)
     {  
        scanf("%d",&k);
        printf("Card %d is a face ",k);  
        k--;  
        printf(ok[a[k]]?"up ":"down ");  
        printf("%d.\n",a[k]+1);  
     }
  }
  return 0;
}