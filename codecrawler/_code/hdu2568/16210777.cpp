#include <cstdio>
#include <cstring>
int main(){
    int t,n,i;
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        i=0;
        while(n>0){
            if(n%2==1){
            n--; i++;
            }
            else
                n/=2;
        }
        printf("%d\n", i);
    }
    return 0;
}
