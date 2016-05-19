#include<stdio.h>
main(){
     int n,t,i,j;
     scanf("%d",&t);
     while(t--)
        {
        scanf("%d",&n);
         for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){

                if((j>i)&&(i+j>n+1))
                  break;

         else if ((i==j)||(i+j==n+1)){
             printf("X");
        }
        else
          printf(" ");
            }
            
            
            printf("\n");
         }
         printf("\n");
     }
}