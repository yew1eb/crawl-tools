#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
struct point{
       int hp;
       int a;       
}mon[10005];
int m;
int cmp(const void * a,const void * b){
        struct point *aa=(struct point *)a;
        struct point *bb=(struct point *)b;
        return (int)ceil((double)aa->hp/m) * bb->a  -  aa->a * (int)ceil((double)bb->hp/m);
}
int main(){
    int t,T,i;
    int n;
    scanf("%d",&T);
    int ca=0;
    for(t=1;t<=T;t++){
                      scanf("%d %d",&n,&m);
                      for(i=1;i<=n;i++){
                                        scanf("%d %d",&mon[i].hp,&mon[i].a);                  
                      }                  
                      qsort(&mon[1],n,sizeof(mon[1]),cmp);
                      __int64  sum=0,t=0;
                      for(i=1;i<=n;i++){
                                        t+=(__int64 )ceil((double)mon[i].hp/(double)m);
                                        sum+=(__int64 )mon[i].a*t;                                                      
                      }
                      printf("Case #%d: ",++ca);
                      printf("%I64d\n",sum);
    }
}
