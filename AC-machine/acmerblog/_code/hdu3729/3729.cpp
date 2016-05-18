 #include <iostream>
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include <algorithm>
 #include <string.h>
 #include <set>
 using namespace std;
 typedef struct abcd
 {
     int x,y;
 }abcd;
 abcd a[100];
 int b[100001];
 int c[100001];
 set<int> s;
 int dfs(int t)
 {
     int i;
     for(i=a[t].x;i<=a[t].y;i++)
     {
         if(!c[i])
         {
             c[i]=1;
             if(!b[i]||dfs(b[i]))
             {
                 b[i]=t;
                 s.insert(t);
                 return 1;
             }
         }
     }
     return 0;
 }
 int main()
 {
     int n,m,i,j;
     cin>>n;
     for(i=0;i<n;i++)
     {
         s.clear();
         memset(b,0,sizeof(b));
         cin>>m;
         for(j=1;j<=m;j++)
         {
             cin>>a[j].x>>a[j].y;
         }
         int sum=0;
         for(j=m;j>0;j--)
         {
             memset(c,0,sizeof(c));
             if(dfs(j))
             sum++;
         }
         cout<<sum<<endl;
         set<int> ::iterator it;
         for(it=s.begin();it!=s.end();it++)
         {
             sum--;
             if(sum)
             cout<<(*it)<<' ';
             else cout<<(*it)<<endl;
         }
     }
 }
