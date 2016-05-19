#include<iostream>
 #include<cmath>
 const int N=11000;
 using namespace std;
 bool mark[N];
 int prime[N];
 
 //素数筛选
 void sieve_prime(){
     memset(mark,true,sizeof(mark));
     mark[0]=mark[1]=false;
     for(int i=2;i<sqrt(N*1.0);i++)if(mark[i]){
         for(int j=i*i;j<N;j+=i){
             mark[j]=false;
         }
     }
 }
     
 int main(){
     int m,a,b;
     while(scanf("%d%d%d",&m,&a,&b)!=EOF){
         if(m==0&&a==0&&b==0)break;
         double temp=a*1.0/b;
         sieve_prime();
         int k=0,max=0,p=2,q=2;
         for(int i=2;i<N;i++)if(mark[i]){
             prime[k++]=i;
         }
         for(int i=0;i<k;i++){
             for(int j=i;j<k;j++){
                 if(prime[i]*prime[j]>max&&prime[i]*prime[j]<=m&&prime[i]*1.0/prime[j]>=temp){
                     p=prime[i];
                     q=prime[j];
                     max=prime[i]*prime[j];
                 }
                 if(prime[i]*prime[j]>m)break;
             }
         }
         printf("%d %d\n",p,q);
     }
     return 0;
 }