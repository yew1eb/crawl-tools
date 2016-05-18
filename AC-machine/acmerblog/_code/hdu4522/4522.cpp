 #include<iostream>
 #include<cmath>
 using namespace std;
 
 int main(){
     int n;
     double num[40];
     while(~scanf("%d",&n)&&n){
         double max=-1;
         double min=400;
         double sum=0;
         for(int i=0;i<n;i++){
             scanf("%lf",&num[i]);
             if(num[i]<min)min=num[i];
             if(num[i]>max)max=num[i];
             sum+=num[i];
         }
         sum=(sum-min-max)/(n-2);
         int pos=0;
         min=400;
         for(int i=0;i<n;i++){
             if(fabs(sum-num[i])<min){
                 min=fabs(sum-num[i]);
                 pos=i+1;
             }
         }
         printf("%d\n",pos);
     }
     return 0;
 }
