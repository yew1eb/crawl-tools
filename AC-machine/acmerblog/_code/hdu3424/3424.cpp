#include<stdio.h>
 #include<string.h>
 const int maxn = 1005;
 struct node{
     double dis,fuel;
 }a[ maxn ];
 int main(){
     int n=0;
     double aa,bb;
     while( scanf("%lf%lf",&aa,&bb) && (aa!=-1.0&&bb!=-1.0) ){
         a[ n ].dis=aa,a[ n ].fuel=bb,n++;
         while( scanf("%lf%lf",&aa,&bb)==2 ){
             if( aa==0.0&&bb==0.0 ) break;
             a[ n ].dis=aa,a[ n ].fuel=bb,n++;
         }
         double dis,fuel;
         dis=fuel=0;
         for( int i=0;i<n-1;i++ ){
             if( a[i].fuel>a[i+1].fuel ){
                 dis+=(a[i+1].dis-a[i].dis);
                 fuel+=(a[i].fuel-a[i+1].fuel);
             }
         }
         //printf("dis:%lf fuel:%lf\n",dis,fuel);
         double ans=a[n-1].fuel*dis/fuel;
     //    printf("ans:%.0lf\n",ans);
         if(( ans-(double)((int)(ans)) )>0.5) printf("%.0lf\n",( (double)((int)(ans)) )+1.0);
         else printf("%.0lf\n",( (double)((int)(ans)) ));
         n=0;
     }
     return 0;
 }