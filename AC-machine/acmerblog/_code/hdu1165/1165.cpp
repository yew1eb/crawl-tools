#include<iostream>
using namespace std;

int dp(int m,int n)
{    if(m==1) return n+2;
     if(n==0) return dp(m-1,1); //这句话不写，递归出不来
     if(m==2) return 2*n+3;
     if(m==3) return 2*dp(3,n-1)+3; //这里在递减，上面那句不写的话，就没有递归终止条件
}

int main()
{    int m,n;
     while(scanf("%d%d",&m,&n)!=EOF)
     {   if(m==1)  printf("%d\n",n+2); 
         else  if(m==2) printf("%d\n",2*n+3);
         else printf("%d\n",dp(3,n));
     }
return 0;
}