#include <iostream>
 #include <stdio.h>
 #include <map>
 using namespace std;
 
 map<int,int>my_map;
 map<int,int>my_map2;
 int f[111111];
 int s;
 int cnt;
 int sum;
 
 void init()
 {
     int i;
     for(i=1;i<=100000;i++)
     {
         f[i]=i;
     }
     my_map.clear();
     my_map2.clear();
     s=0;
     cnt=0;
     sum=0;
 }
 
 int find(int x)
 {
     if(x==f[x])
     {
         return x;
     }
     int t=find(f[x]);
     f[x]=t;
     return t;
 }
 
 void Union(int a,int b)
 {
     f[b]=a;
 }
 
 int main()
 {
     int a,b;
     bool flag=false;
     init();
     int count=1;
     while(~scanf("%d%d",&a,&b))
     {
         if(a==0 && b==0)
         {
             if(flag)
             {
                 printf("Case %d is not a tree.\n",count++);
                 flag=false;
             }
             else
             {
                 if((sum==(cnt-1) && s==(cnt-1)) || (sum==0 && cnt==0))
                 {
                     printf("Case %d is a tree.\n",count++);
                 }
                 else
                 {
                     printf("Case %d is not a tree.\n",count++);
                 }
             }
             init();
             continue;
         }
         if(a<0 && b<0)
         {
             break;
         }
         if(!my_map[a])
         {
             my_map[a]++;
             cnt++;
         }
         if(!my_map2[b])
         {
             my_map2[b]++;
             s++;
         }
         if(!my_map[b])
         {
             my_map[b]++;
             cnt++;
         }
 
         int x,y;
         if(a==b)
         continue;
         x=find(a);
         y=find(b);
         if(x==y)
         {
             flag=true;
         }
         else
         {
             Union(x,y);
             sum++;
         }
     }
     return 0;
 }