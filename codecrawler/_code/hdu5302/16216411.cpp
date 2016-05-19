#include <iostream>
#include <stdio.h>
using namespace std;

int  main(){
    int T,a1,a2,a3,b1,b2,b3;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&b1,&b2,&b3);
        int m=a1+a2+a3;
        if(a2%2||b2%2||(a2==0&&a3<=2)||(b2==0&&b3<=2)||(a2+a3*2+b2+b3*2>m*4)||(a2+a3*2+b2+b3*2>m*(m-1))){
            puts("-1");
            continue;
        }
        printf("%d\n",(a2+b2)/2+a3+b3);
        //printf("%d %d %d %d %d %d\n",a1,a2,a3,b1,b2,b3);
        if(a2==0){
            for(int i=1;i<=a3;i++)
                printf("%d %d 0\n",i,(i+1)%a3);
        }
        else {
            for(int i=1;i<=a3;i++)
                printf("%d %d 0\n",i,i+1);
            printf("%d %d 0\n",a3+1,a3+2);
            for(int i=1;i<a2-1;i+=2)
                printf("%d %d 0\n",a3+2+i,a3+3+i);
        }
        if(b2!=0){
            int x=2,y=4;
            for(int i=1;i<=b3;i++){
                printf("%d %d 1\n",x,y);
                x+=2,y+=2;
                if(x>m) x=1;
                if(y>m) y=1;
            }
            for(int i=1;i<b2;i+=2){
                printf("%d %d 1\n",x,y);
                x+=4,y+=4;
                if(x>m+2) x=3;
                if(y>m+2) y=3;
                if(x>m) x=1;
                if(y>m) y=1;
            }
        }
        else{
            int x=2,y=4;
            if(b3==m){
                if(a2!=0){
                    
                    for(int i=1;i<=b3;i+=1){
                        printf("%d %d 1\n");
                        x+=2,y+=2;
                        if(x>m) x=1;
                        if(y>m) y=1;
                    }
                }
                else {
                    if(a3%2){
                    
                    for(int i=1;i<=b3;i+=1){
                        printf("%d %d 1\n");
                        x+=2,y+=2;
                        if(x>m) x=1;
                        if(y>m) y=1;
                    }
                    }
                    else{
                        for(int i=1;i<m-1;i++)
                            printf("%d %d 1\n",i,i+2);
                        printf("%d %d 1\n",m-1,(m-1)%2);
                        
                        printf("%d %d 1\n",m,(m)%2);
                    }
                }
            }
            else{
                
            for(int i=1;i<=b3;i+=1){
                printf("%d %d 1\n");
                x+=2,y+=2;
                if(x>m) x=3;
                if(y>m) y=3;
            }
            }
    }
    }
}
