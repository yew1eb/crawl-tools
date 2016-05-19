#include <iostream>
#include <cstdio>
using namespace std;
int a[12],count;
int num[1000000];
int Rget(int x){
     int k = 0,res = 0;
     while(x>=10){
         a[k++] = x%10;
         x/=10;
     }
     a[k] = x%10;
     for(int i = 0;i<k;i++)
         res= (res+a[i])*10;
     return res+a[k];
}
void Num(int x){
    if(Rget(x)==x){num[count++] = x; return;}
    else{
        num[count++] = x;
        Num(Rget(x) + x);
    }
}
int main(){
    int x;
    while(scanf("%d",&x)!=EOF){
          count = 0;
          Num(x);
          printf("%d\n",count-1);
          for(int i = 0;i<count;i++){
                 printf("%d",num[i]);
                 if(i!=count-1) printf("--->");
          }
          printf("\n");
    }
    return 0;
}