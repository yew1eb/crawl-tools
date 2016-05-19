#include<iostream>
 #include<cstring>
 #include<cstdio>
 using namespace std;
 __int64 num,n,len;
 char str[15];
 void DFS(__int64 x,__int64 sum)
 {
     if(x==len)
     {
         if(sum==n)
         
             num++;
             return ;
         
     }
     __int64 k=0;//核心的东东  短短的几句  却是指数级的搜索量啊
     for(int i=x;i<len;i++)//这里刚开始写成了从0开始，哎合适能搜到头啊
     {
         k=k*10+str[i]-'0';
         DFS(i+1,sum+k);
         if(x!=0)//第一个数字前不能加“-”号
             DFS(i+1,sum-k);
     }
 }
 
 
 int main()
 {
     while(scanf("%s %I64d",str,&n)!=EOF)
     {
         len=strlen(str);
         num=0;
         DFS(0,0);
         printf("%I64d\n",num);
     }
     return 0;
 }