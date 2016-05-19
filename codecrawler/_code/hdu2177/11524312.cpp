#include"iostream"
#include"cmath"
using namespace std;
int main(){
    int a,b,t,p1,q1,p2,q2;
    double d=(1+sqrt(5.0))/2;
    while(scanf("%d%d",&a,&b)==2){
        if(a==0 && b==0)break;
        if(a>b){
                t=a;
                a=b;
                b=t;
        }
        if((int)((b-a)*d)==a){
                              printf("0\n");
                              continue;
        }
        else printf("1\n");
        if((int)((b-a)*d)<a){
             printf("%d %d\n",(int)((b-a)*d),(int)((b-a)*d)+b-a);
        }
        if((int)(((int)(a/d)+1)*d)==a){
            if(b>(int)(a/d)+a+1){
               printf("%d %d\n",a,(int)(a/d)+a+1);
            }
        }
        else if(  (int)(((int)(a/(d+1))+1)*d)+(int)(a/(d+1))+1==a){
             if(b>(int)(((int)(a/(d+1))+1)*d)){
                printf("%d %d\n",(int)(((int)(a/(d+1))+1)*d),a); 
             }
        }
    }
    return 0;
}
