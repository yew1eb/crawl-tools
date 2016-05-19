#include<stdio.h>
#include<math.h>
int main(){
    int i,j,k,m,n,sum;
    scanf("%d",&n);
    while(n--){
        sum=1;
        scanf("%d",&m);
        for(i=2;i<=(int)sqrt(1.0*m);i++)
            if(m%i==0)
                if(i==m/i)
                    sum+=i;
                else sum+=i+m/i;
                printf("%d\n",sum);
    }
    return 0;
}