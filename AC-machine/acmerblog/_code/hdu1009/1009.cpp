 #include<stdio.h>
  #include<algorithm>
  struct node {
      double j,f,velu;
  }java[1000+5];
  double M;
  int N;
  bool cmp(node a,node b) {
      return a.velu>b.velu;
 }
 int main() {
     while(scanf("%lf%d",&M,&N)&&!(M==-1||N==-1)) {
         double sum=0;
         for(int i=1;i<=N;++i) {
             scanf("%lf%lf",&java[i].j,&java[i].f);
             java[i].velu=1.0*java[i].j/java[i].f;
         }
         if(N>1)
         std::sort(java+1,java+N+1,cmp);
         for(int i=1;;++i) {
             if(N==0)
             break;
             if(M>=java[i].f) {
                 M-=java[i].f;
                 sum+=java[i].j;
             }
             else{
                 sum+=1.0*M*java[i].j/java[i].f;
                 break;
             }
         }
         printf("%.3lf\n",sum);
     }
     return 0;
 }