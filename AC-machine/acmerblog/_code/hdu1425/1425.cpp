#include<iostream>
 #include<cstring>
 #include<string>
 #include<cstdio>
 using namespace std;
 
 int Hash[1000005];
 
 int main()
 {
     int n,m,x;
     while(scanf("%d %d",&n,&m)!=EOF){
         memset(Hash,0,sizeof(Hash));
         for(int i=0;i<n;i++){
             scanf("%d",&x);
             Hash[x+500000]=1;
         }
         for(int i=1000000;i>=0&&m>0;i--){
             if(Hash[i]){
                 m--;
                 m==0?(printf("%d\n",i-500000)):(printf("%d ",i-500000));
             }
         }
     }
     return 0;
 }