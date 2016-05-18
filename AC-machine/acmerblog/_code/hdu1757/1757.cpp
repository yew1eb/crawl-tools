#include<iostream>
 #include<cstring>
 const int N=10;
 using namespace std;
 int k,m;
 struct Matrix{
     int map[N][N];
 };
 
 Matrix matrix;
 
 void Initiate(){
     for(int i=0;i<N;i++){
         scanf("%d",&matrix.map[0][i]);
     }
     for(int i=1;i<N;i++){
         for(int j=0;j<N;j++){
             if(i==(j+1))matrix.map[i][j]=1;
             else matrix.map[i][j]=0;
         }
     }
 }
 
 //矩阵相乘
 Matrix Mul(Matrix &a,Matrix &b){
     Matrix c;
     for(int i=0;i<N;i++){
         for(int j=0;j<N;j++){
             c.map[i][j]=0;
             for(int k=0;k<N;k++){
                 c.map[i][j]+=a.map[i][k]*b.map[k][j];
             }
             c.map[i][j]%=m;
         }
     }
     return c;
 }
 
 //快速幂
 Matrix Pow(int n){
     Matrix t;
     if(n==1)return matrix;
     if(n&1)return Mul(matrix,Pow(n-1));
     else {
         Matrix temp=Pow(n>>1);
         return Mul(temp,temp);
     }
 }
 
 
 int main(){
     while(scanf("%d%d",&k,&m)!=EOF){
         Initiate();
         if(k<10){
             printf("%d\n",k%m);
             continue;
         }
         Matrix temp=Pow(k-9);
         int ans=0;
         for(int i=0;i<N;i++){
             ans+=temp.map[0][i]*(N-i-1); //最后要乘上f[9],f[8],...,f[1],f[0];
             ans%=m;
         }
         printf("%d\n",ans);
     }
     return 0;
 }