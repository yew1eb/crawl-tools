#include <stdio.h>
#define abs(x) (x>0?x:-(x))
int main(){
    int n,a,b,p,m,i;
    while(~scanf("%d",&n)){
        scanf("%d",&a);
        m=0;
        for(i=1;i<n;i++){
            scanf("%d",&b);
            if(m<abs(a-b)){
                m=abs(a-b);
                p=i;
            }
            a=b;
        }
        printf("%d %d\n",p,p+1);
    }
}
